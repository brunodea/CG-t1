#include "DCTViewer.h"

#include <SCV/Point.h>
#include <SCV/Kernel.h>

using namespace brunodea;

DCTViewer *DCTViewer::m_sInstance = NULL;

DCTViewer::DCTViewer()
{
   initSignals();
   
   m_pBottomSidebar = new GUI::BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 5));
   m_pGraphsCanvas = new GUI::GraphsCanvas(scv::Point(0, 0));

   scv::Kernel::getInstance()->addComponent(m_pBottomSidebar);
   scv::Kernel::getInstance()->addComponent(m_pGraphsCanvas);
}

DCTViewer::~DCTViewer()
{
   delete m_pBottomSidebar;
   delete m_pGraphsCanvas;

   for(unsigned int i = 0; i < m_pSignals->size(); i++)
      delete []m_pSignals->at(i);
   delete []m_pSignals;
}

DCTViewer *DCTViewer::instance()
{
   if(m_sInstance == NULL)
      m_sInstance = new DCTViewer();

   return m_sInstance;
}

void DCTViewer::initSignals()
{
   m_pSignals = new std::vector<std::vector<double> *>();
}

void DCTViewer::addSignalVec(std::vector<double> *sv)
{
   m_pSignals->push_back(sv);
}

void DCTViewer::addSignalVec()
{
   std::vector<double> *v = new std::vector<double>();
   for(unsigned int i = 0; i < 8; i++)
      v->push_back(0);
   addSignalVec(v);
}
