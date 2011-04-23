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
      GraphsCanvas(const scv::Point &p);
      ~GraphsCanvas();

      inline Graph *getOrigSampleGraph() { return m_pOrigSampleGraph; }
      inline Graph *getFDCTGraph() { return m_pFDCTGraph; }
      inline Graph *getIDCTGraph() { return m_pIDCTGraph; }

      void render();
      void update();
   protected:
      void onMouseClick(const scv::MouseEvent &evt);
      void onMouseWheel(const scv::MouseEvent &evt);
      void onKeyPressed(const scv::KeyEvent &evt);
      void onMouseOver(const scv::MouseEvent &evt);

   private:
      scv::Color4f m_bgColor;
      Graph *m_pOrigSampleGraph;
      Graph *m_pFDCTGraph;
      Graph *m_pIDCTGraph;

      GraphPoint *m_pCurrPointOvered; //current point that is overed by the mouse;
      unsigned int m_iCurrPointIndex; //index of the current point overed by the mouse;

   }; //end of class GraphsCanvas.
} //end of namespace GUI.

#endif
