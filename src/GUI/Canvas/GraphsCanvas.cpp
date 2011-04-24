#include "GUI/Canvas/GraphsCanvas.h"
#include "GUI/Canvas/GraphPoint.hpp"
#include "macros.h"
#include "DCTViewer.h"
#include "GUI/Canvas/functions.hpp"

#include <sstream>
#include <iostream>

using namespace GUI;

GraphsCanvas::GraphsCanvas(const scv::Point &p)
   : scv::Canvas(p, WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT),
     m_bgColor(1.f, 1.f, 1.f)
{
   m_pOrigSampleGraph = NULL;
   m_pFDCTGraph = NULL;
   m_pIDCTGraph = NULL;
   m_pCurrPointOvered = NULL;
   m_iCurrPointIndex = -1;
}

GraphsCanvas::~GraphsCanvas()
{
   delete m_pOrigSampleGraph;
   delete m_pFDCTGraph;
   delete m_pIDCTGraph;
}

void GraphsCanvas::update()
{
   /* Inicializa os gráficos. */
   if(m_pOrigSampleGraph == NULL)
       m_pOrigSampleGraph = new Graph(DCTVIEWER->getSignals(), "Original", scv::Point(10,450), 300, 360);
   if(m_pFDCTGraph == NULL)
      m_pFDCTGraph = new Graph(DCTVIEWER->getFDCTSignals(), "Depois da FDCT", scv::Point(0,450), 300, 360);
   if(m_pIDCTGraph == NULL)
      m_pIDCTGraph = new Graph(DCTVIEWER->getIDCTSignals(), "IDCT apos a FDCT", scv::Point(0,450), 300, 360);

   /* 
    * Ajuste da posição y do 0x0 de cada gráfico. Isso é necessário pois a escala pode aumentar o tamanho da canvas.
    * Com isso os gráficos sempre ficam na parte de baixo da canvas.
    */
   double height = getHeight() - 60;
   m_pOrigSampleGraph->m_Pos0x0.y = height;
   m_pFDCTGraph->m_Pos0x0.y = height;
   m_pIDCTGraph->m_Pos0x0.y = height;

   /*
    * Sempre seta os signals pois o método da DCTViewer "getFDCTSignals()" sempre traz os sinais atualizados.
    */
   m_pFDCTGraph->setSignals(DCTVIEWER->getFDCTSignals());

   /* Ajusta a posição x do 0x0 de acordo com a escala. */
   m_pFDCTGraph->m_Pos0x0.x = m_pOrigSampleGraph->m_Pos0x0.x +
      m_pOrigSampleGraph->getScale()*m_pOrigSampleGraph->m_XLength + 60;
   m_pFDCTGraph->setScale(m_pOrigSampleGraph->getScale());

   /* Mesmo da FDCT. */
   m_pIDCTGraph->setSignals(DCTVIEWER->getIDCTSignals());
   m_pIDCTGraph->m_Pos0x0.x = m_pFDCTGraph->m_Pos0x0.x +
      m_pFDCTGraph->getScale()*m_pFDCTGraph->m_XLength + 60;
   m_pIDCTGraph->setScale(m_pOrigSampleGraph->getScale());
}

void GraphsCanvas::render()
{   
   glClearColor(m_bgColor[0], m_bgColor[1], m_bgColor[2], m_bgColor[3]);
   glClear(GL_COLOR_BUFFER_BIT);

   /* Faz o desenho dos gráficos. */
   m_pOrigSampleGraph->draw();
   m_pFDCTGraph->draw();
   m_pIDCTGraph->draw();


   /* Caso o mouse esteja sobre um ponto, logo acima dele é desenhado seu index. */
   if(m_pCurrPointOvered != NULL && m_iCurrPointIndex >= 0)
   {
      glColor4f(0.f, 0.f, 6.f, 1.f);
      std::stringstream ss;
      ss << m_iCurrPointIndex;

      scv::Point pos;
      pos.x = m_pCurrPointOvered->m_Pos.x;
      pos.y = m_pCurrPointOvered->m_Pos.y - 20;

      drawText(ss.str(), pos);
   }
}

void GraphsCanvas::onMouseWheel(const scv::MouseEvent &evt)
{
   /* Ajusta a escala quando o usuário mover a roda do mouse para cima ou para baixo. */
   if(evt.getState() == evt.wheelup)
   {
      double new_scale = m_pOrigSampleGraph->getScale() + 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
      DCTVIEWER->adjustCanvasPanel();
   }
   else if(evt.getState() == evt.wheeldown)
   {
      double new_scale = m_pOrigSampleGraph->getScale() - 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
      DCTVIEWER->adjustCanvasPanel();
   }
}

void GraphsCanvas::onKeyPressed(const scv::KeyEvent &evt)
{
   /* Ajusta a escala quando o usuário apertar + ou -. */
   if(evt.getKeyCode() == '+')
   {
      double new_scale = m_pOrigSampleGraph->getScale() + 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
      DCTVIEWER->adjustCanvasPanel();
   }
   else if(evt.getKeyCode() == '-')
   {
      double new_scale = m_pOrigSampleGraph->getScale() - 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
      DCTVIEWER->adjustCanvasPanel();
   }
}

void GraphsCanvas::onMouseClick(const scv::MouseEvent &evt)
{
   /*
    * Quando o usuário clica com o botão do meio do mouse em cima de um ponto
    * pertencente ao gráfico da FDCT ele é setado para zero (truncamento).
    * E o gráfico da IDCT, bem como o vetor de sinais, é ajustado na mesma hora.
    */
   if(evt.getButton() == evt.middle)
   {
      int index = -1;
      index = m_pFDCTGraph->getPointAt(evt.getPosition());
      if(index >= 0)
      {
         GraphPoint *aux = m_pFDCTGraph->getPointAt(index);
         m_pFDCTGraph->goToZero(aux);
         
         int row = index/MASTER_VALUE;
         int col = index%MASTER_VALUE;

         double *val = &DCTVIEWER->getFDCTSignals()->at(row)->at(col);
         *val = 0;

         DCTVIEWER->adjustIDCTSignals();
         DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
         return;
      }
   }
}

void GraphsCanvas::onMouseOver(const scv::MouseEvent &evt)
{
   /* Ajusta o m_pCurrPointOvered e o m_iCurrPointIndex. */
   int index = -1;
   GraphPoint *aux = NULL;
   scv::Point pos;

   index = m_pOrigSampleGraph->getPointAt(evt.getPosition());
   if(index >= 0)
      aux = m_pOrigSampleGraph->getPointAt(index);
   else
   {
      index = m_pFDCTGraph->getPointAt(evt.getPosition());
      if(index >= 0)
         aux = m_pFDCTGraph->getPointAt(index);
      else
      {
         index = m_pIDCTGraph->getPointAt(evt.getPosition());
         if(index >= 0)
            aux = m_pIDCTGraph->getPointAt(index);
      }
   }

   m_pCurrPointOvered = aux;
   m_iCurrPointIndex = index;
}
