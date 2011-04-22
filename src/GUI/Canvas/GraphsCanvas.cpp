#include "GUI/Canvas/GraphsCanvas.h"
#include "macros.h"
#include "DCTViewer.h"

#include <iostream>

using namespace GUI;

GraphsCanvas::GraphsCanvas(const scv::Point &p)
   : scv::Canvas(p, WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT),
     m_bgColor(1.f, 1.f, 1.f)
{
   m_pOrigSampleGraph = NULL;
   m_pFDCTGraph = NULL;
   m_pIDCTGraph = NULL;
}

GraphsCanvas::~GraphsCanvas()
{
   delete m_pOrigSampleGraph;
   delete m_pFDCTGraph;
}

void GraphsCanvas::update()
{
   if(m_pOrigSampleGraph == NULL)
       m_pOrigSampleGraph = new Graph(DCTVIEWER->getSignals(), scv::Point(10,450), 300, 360);
   if(m_pFDCTGraph == NULL)
      m_pFDCTGraph = new Graph(DCTVIEWER->getFDCTSignals(), scv::Point(0,450), 300, 360);
   if(m_pIDCTGraph == NULL)
      m_pIDCTGraph = new Graph(DCTVIEWER->getIDCTSignals(), scv::Point(0,450), 300, 360);


   m_pFDCTGraph->setSignals(DCTVIEWER->getFDCTSignals());
   m_pFDCTGraph->m_Pos0x0.x = m_pOrigSampleGraph->m_Pos0x0.x +
      m_pOrigSampleGraph->getScale()*m_pOrigSampleGraph->m_XLength + 30;
   m_pFDCTGraph->setScale(m_pOrigSampleGraph->getScale());

   m_pIDCTGraph->setSignals(DCTVIEWER->getIDCTSignals());
   m_pIDCTGraph->m_Pos0x0.x = m_pFDCTGraph->m_Pos0x0.x +
      m_pFDCTGraph->getScale()*m_pFDCTGraph->m_XLength + 30;
   m_pIDCTGraph->setScale(m_pOrigSampleGraph->getScale());
}

void GraphsCanvas::render()
{   
   glClearColor(m_bgColor[0], m_bgColor[1], m_bgColor[2], m_bgColor[3]);
   glClear(GL_COLOR_BUFFER_BIT);
   m_pOrigSampleGraph->draw();
   m_pFDCTGraph->draw();
   m_pIDCTGraph->draw();
}

void GraphsCanvas::onMouseWheel(const scv::MouseEvent &evt)
{
   if(evt.getState() == evt.wheelup)
   {
      double new_scale = m_pOrigSampleGraph->getScale() + 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
   }
   else if(evt.getState() == evt.wheeldown)
   {
      double new_scale = m_pOrigSampleGraph->getScale() - 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
   }
}

void GraphsCanvas::onKeyPressed(const scv::KeyEvent &evt)
{
   if(evt.getKeyCode() == '+')
   {
      double new_scale = m_pOrigSampleGraph->getScale() + 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
   }
   else if(evt.getKeyCode() == '-')
   {
      double new_scale = m_pOrigSampleGraph->getScale() - 0.1;
      m_pOrigSampleGraph->setScale(new_scale);
   }
}
