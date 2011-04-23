#ifndef _BRUNODEA_DCTVIEWER_H_
#define _BRUNODEA_DCTVIEWER_H_

#include <SCV/ScrollPane.h>
#include <SCV/Panel.h>

#include <vector>
#include "GUI/Sidebar/BottomSidebar.h"
#include "GUI/Canvas/GraphsCanvas.h"

namespace brunodea
{
   class DCTViewer
   {
   public:
      static DCTViewer *instance();
      ~DCTViewer();

      inline GUI::BottomSidebar *getBottomSidebar() { return m_pBottomSidebar; }
      inline GUI::GraphsCanvas *getGraphsCanvas() { return m_pGraphsCanvas; }
      inline std::vector<std::vector<double> *> *getSignals() { return m_pSignals; }
      std::vector<std::vector<double> *> *getFDCTSignals();
      std::vector<std::vector<double> *> *getIDCTSignals();

      void adjustFDCTSignals();
      void adjustIDCTSignals();

      void adjustCanvasPanel();

      void addSignalVec(std::vector<double> *sv);
      void addSignalVec();
            
      static std::vector<double> &fdct(std::vector<double> &sample);
      static std::vector<double> &idct(std::vector<double> &signal);

   private:
      static DCTViewer *m_sInstance;

      GUI::BottomSidebar *m_pBottomSidebar;
      GUI::GraphsCanvas *m_pGraphsCanvas;

      std::vector<std::vector<double> *> *m_pSignals;
      std::vector<std::vector<double> *> *m_pFDCTSignals;
      std::vector<std::vector<double> *> *m_pIDCTSignals;

      scv::ScrollPane *m_pCanvasScrollPane;
      scv::Panel *m_pCanvasPanel;

      /*DEVE ser SEMPRE um numero multiplo de 8.*/
      int m_iSampleSize; //size of the sample that will be passed to the fdct/idct (1 or 2 times 8).

   private:
      DCTViewer();
      void initSignals();

   }; //end of class DCTViewer.
} //end of namespace brunodea.
#endif
