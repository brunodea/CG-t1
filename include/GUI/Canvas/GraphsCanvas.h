/*
 * Canvas onde os gráficos dos sinais originais, da fdct e da idct serão desenhados.
 */
#ifndef _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_
#define _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>
#include <SCV/Color4f.h>
#include <SCV/MouseEvent.h>
#include <SCV/KeyEvent.h>
#include "GUI/Canvas/GraphPoint.hpp"
#include "GUI/Canvas/Graph.h"

#include <vector>

namespace GUI
{
   class GraphsCanvas : public scv::Canvas
   {
   public:
      /*
       * Construtor.
       * p: posição na tela onde a canvas vai ser posicionada.
       */
      GraphsCanvas(const scv::Point &p);
      ~GraphsCanvas();

      /* Getters. */
      inline Graph *getOrigSampleGraph() { return m_pOrigSampleGraph; }
      inline Graph *getFDCTGraph() { return m_pFDCTGraph; }
      inline Graph *getIDCTGraph() { return m_pIDCTGraph; }

      void render();
      void update();
   protected:
      /* Callbacks. */
      void onMouseClick(const scv::MouseEvent &evt);
      void onMouseWheel(const scv::MouseEvent &evt);
      void onKeyPressed(const scv::KeyEvent &evt);
      void onMouseOver(const scv::MouseEvent &evt);

   private:
      scv::Color4f m_bgColor; //cor do fundo da canvas.
      Graph *m_pOrigSampleGraph; //gráfico que representa a amostra original.
      Graph *m_pFDCTGraph; //gráfico que representa a amostra após a FDCT.
      Graph *m_pIDCTGraph; //gráfico que representa a amostra após a IDCT.

      GraphPoint *m_pCurrPointOvered; //ponto atual que está com o mouse sobre ele.
      unsigned int m_iCurrPointIndex; //índice do ponto atual em que o mouse está sobre.

   }; //end of class GraphsCanvas.
} //end of namespace GUI.

#endif
