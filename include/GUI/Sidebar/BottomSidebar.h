#ifndef _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_
#define _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_

#include <SCV/Panel.h>
#include <vector>

#include "SampleValueSpinner.h"

namespace GUI
{
   class BottomSidebar : public scv::Panel
   {
   public:
      BottomSidebar(int pos_x, int pos_y);
      ~BottomSidebar();

      inline int getNumberOfSamples() { return m_iNumberOfSamples; }


   private:
      std::vector<SampleValueSpinner *> m_vSampleSpinners;
      int m_iNumberOfSamples; //numero de amostras (8 ou 16).      

   private:
      void initSampleSpinners();


   }; //end of class BottomSidebar
} //end of namespace GUI.

#endif