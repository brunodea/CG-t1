#ifndef _BRUNODEA_CG_T1_DCT_VIEWER_H_
#define _BRUNODEA_CG_T1_DCT_VIEWER_H_

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

      void addSignalVec(std::vector<double> *sv);
      void addSignalVec();

   private:
      static DCTViewer *m_sInstance;

      GUI::BottomSidebar *m_pBottomSidebar;
      GUI::GraphsCanvas *m_pGraphsCanvas;

      std::vector<std::vector<double> *> *m_pSignals;

   private:
      DCTViewer();

      void initSignals();

   }; //end of class DCTViewer.
} //end of namespace brunodea.
#endif
