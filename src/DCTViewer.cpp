#include "DCTViewer.h"

#include <SCV/Point.h>
#include <SCV/Kernel.h>

#include <iostream>

using namespace brunodea;

DCTViewer *DCTViewer::m_sInstance = NULL;

DCTViewer::DCTViewer()
{
   initSignals();
   
   m_pBottomSidebar = new GUI::BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 5));
   m_pGraphsCanvas = new GUI::GraphsCanvas(scv::Point(0, 0));

   m_pCanvasPanel = new scv::Panel(scv::Point(0, 0), WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT);
   m_pCanvasPanel->addComponent(m_pGraphsCanvas);

   m_pCanvasScrollPane = new scv::ScrollPane(scv::Point(0, 0), WINDOW_WIDTH, WINDOW_HEIGHT - BOTTOM_SIDEBAR_HEIGHT, m_pCanvasPanel);

   scv::Kernel::getInstance()->addComponent(m_pCanvasScrollPane);
   scv::Kernel::getInstance()->addComponent(m_pBottomSidebar);
}

DCTViewer::~DCTViewer()
{
   delete m_pCanvasPanel;
   m_pCanvasPanel = NULL;
   delete m_pCanvasScrollPane;

   delete m_pBottomSidebar;
   delete m_pGraphsCanvas;

   for(unsigned int i = 0; i < m_pSignals->size(); i++)
      delete []m_pSignals->at(i);
   delete []m_pSignals;
   
   for(unsigned int i = 0; i < m_pFDCTSignals->size(); i++)
      delete []m_pFDCTSignals->at(i);
   delete []m_pFDCTSignals;

   for(unsigned int i = 0; i < m_pIDCTSignals->size(); i++)
      delete []m_pIDCTSignals->at(i);
   delete []m_pIDCTSignals;
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
   m_pIDCTSignals = new std::vector<std::vector<double> *>();
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
         m_pFDCTSignals->push_back(&DCTViewer::fdct(*m_pSignals->at(i)));
   }

   return m_pFDCTSignals;
}

std::vector<std::vector<double> *> *DCTViewer::getIDCTSignals()
{
   double sigs_size = m_pSignals->size();
   double fdct_sigs_size = m_pIDCTSignals->size();
   if(fdct_sigs_size < sigs_size)
   {
      for(int i = fdct_sigs_size; i < sigs_size; i++)
         m_pIDCTSignals->push_back(&DCTViewer::idct(*m_pFDCTSignals->at(i)));
   }

   return m_pIDCTSignals;
}

void DCTViewer::adjustFDCTSignals()
{
   unsigned int sigs_size = m_pSignals->size();
   for(unsigned int i = 0; i < sigs_size; i++)
   {
      std::vector<double> *v = &DCTViewer::fdct(*m_pSignals->at(i));
      for(unsigned int j = 0; j < v->size(); j++)
      {
         double *val = &getFDCTSignals()->at(i)->at(j);
         *val = v->at(j);
         std::cout << *val << " ";
      }
      std::cout << "\n";
   }
}

void DCTViewer::adjustIDCTSignals()
{
   unsigned int sigs_size = getFDCTSignals()->size();
   for(unsigned int i = 0; i < sigs_size; i++)
   {
      std::vector<double> *v = &DCTViewer::idct(*getFDCTSignals()->at(i));
      for(unsigned int j = 0; j < v->size(); j++)
      {
         double *val = &getIDCTSignals()->at(i)->at(j);
         *val = v->at(j);
         std::cout << *val << " ";
      }
      std::cout << "\n";
   }
}

/*
 * Forward Discrete Cosine Transform.
 */
std::vector<double> &DCTViewer::fdct(std::vector<double> &sample)
{      
   std::vector<double> *result = new std::vector<double>();

   unsigned int n = sample.size();
   double f_u;
   double c_u;
   for(unsigned int u = 0; u < n; u++)
   {
      if(u == 0)
         c_u = (double) 1/sqrt(2.0);
      else
         c_u = 1;

      f_u = 0;
      for(unsigned int x = 0; x < n; x++)
         f_u += sample[x]*cos((double) ((2*x) + 1)*u*MY_PI/(2*n));
      f_u *= 0.5*c_u;
      result->push_back(f_u);
   }

   return *result;
}

/*
   * Inverse Discrete Cosine Transform.
*/
std::vector<double> &DCTViewer::idct(std::vector<double> &signal)
{
   std::vector<double> *original = new std::vector<double>();
    
   int n = signal.size();
   double c_j;
   double pt;

   for(int t = 0; t < n; t++)
   {
      pt = 0;
      for(int j = 0; j < n; j++)
      {
         if(j == 0)
               c_j = (double) 1/sqrt(2.0);
         else
               c_j = 1;
         pt += c_j*signal[j]*cos((double) (2*t + 1)*j*MY_PI/(2*n));
      }
      pt *= 0.5;
      original->push_back(pt);
   }

   return *original;
}

void DCTViewer::adjustCanvasPanel()
{
   //m_pCanvasScrollPane->set
}
