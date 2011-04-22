#ifndef _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_
#define _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>
#include <SCV/Color4f.h>
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

      void render();
      void update();
   private:
      scv::Color4f m_bgColor;
      Graph *m_pOrigSampleGraph;

   }; //end of class GraphsCanvas.
} //end of namespace GUI.

#endif
