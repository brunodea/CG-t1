#include "DCTViewer.h"
#include "DCT/dct.hpp"

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
   
   for(unsigned int i = 0; i < m_pSignals->size(); i++)
      delete []m_pFDCTSignals->at(i);
   delete []m_pFDCTSignals;
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
   m_pFDCTSignals = new std::vector<std::vector<double> *>();
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

std::vector<std::vector<double> *> *DCTViewer::getFDCTSignals()
{
   double sigs_size = m_pSignals->size();
   double fdct_sigs_size = m_pFDCTSignals->size();
   if(fdct_sigs_size < sigs_size)
   {
      for(int i = fdct_sigs_size; i < sigs_size; i++)
         m_pFDCTSignals->push_back(&DCT::fdct(*m_pSignals->at(i)));
   }

   return m_pFDCTSignals;
}
