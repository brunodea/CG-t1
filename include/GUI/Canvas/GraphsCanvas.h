#ifndef _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_
#define _BRUNODEA_CG_T1_GRAPHS_CANVAS_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>

namespace GUI
{
   class GraphsCanvas : public scv::Canvas
   {
   public:
      GraphsCanvas(const scv::Point &p);

   }; //end of class GraphsCanvas.
} //end of namespace GUI.

#endif
