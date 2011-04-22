#include "GUI/Canvas/GraphsCanvas.h"
#include "macros.h"

using namespace GUI;

GraphsCanvas::GraphsCanvas(const scv::Point &p)
   : scv::Canvas(p, WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT),
     m_bgColor(1.f, 1.f, 1.f)
{
   m_pOrigSampleGraph = new Graph(scv::Point(10,450), 300, 360);
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

void GraphsCanvas::onMouseWheel(const scv::MouseEvent &evt)
{
   if(evt.getState() == evt.wheelup)
   {
      double new_scale = m_pOrigSampleGraph->getScale()/2;
      m_pOrigSampleGraph->setScale(new_scale);
   }
   else if(evt.getState() == evt.wheeldown)
   {
      double new_scale = m_pOrigSampleGraph->getScale() + 0.5;
      m_pOrigSampleGraph->setScale(new_scale);
   }
   m_pOrigSampleGraph->adjustPoints();
}
