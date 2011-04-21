#include "GUI/Canvas/GraphsCanvas.h"
#include "macros.h"

using namespace GUI;

GraphsCanvas::GraphsCanvas(const scv::Point &p)
   : scv::Canvas(p, WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT)
{
}

