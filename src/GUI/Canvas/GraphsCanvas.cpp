#include "GUI/Canvas/GraphsCanvas.h"
#include "macros.h"

using namespace GUI;

GraphsCanvas::GraphsCanvas(const scv::Point &p)
   : scv::Canvas(p, WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT),
     m_bgColor(0.f, 0.f, 1.f)
{
   m_pOrigSampleGraph = new Graph(scv::Point(10,450), 500, 360);
}

GraphsCanvas::~GraphsCanvas()
{
   delete m_pOrigSampleGraph;
}

void GraphsCanvas::update()
{
}

void GraphsCanvas::render()
{   
   glClearColor(m_bgColor[0], m_bgColor[1], m_bgColor[2], m_bgColor[3]);
   glClear(GL_COLOR_BUFFER_BIT);
   m_pOrigSampleGraph->draw();
}
