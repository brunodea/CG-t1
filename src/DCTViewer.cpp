#include "DCTViewer.h"

#include <SCV/Point.h>
#include <SCV/Kernel.h>

using namespace brunodea;

DCTViewer *DCTViewer::m_sInstance = NULL;

DCTViewer::DCTViewer()
{
   m_pBottomSidebar = new GUI::BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 5));
   m_pGraphsCanvas = new GUI::GraphsCanvas(scv::Point(0, 0));

   scv::Kernel::getInstance()->addComponent(m_pBottomSidebar);
   scv::Kernel::getInstance()->addComponent(m_pGraphsCanvas);
}

DCTViewer::~DCTViewer()
{
   delete m_pBottomSidebar;
   delete m_pGraphsCanvas;
}

DCTViewer *DCTViewer::instance()
{
   if(m_sInstance == NULL)
      m_sInstance = new DCTViewer();

   return m_sInstance;
}

