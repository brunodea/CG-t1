#ifndef _BRUNODEA_CG_T1_SAMPLE_SPINNERS_PANE_H_
#define _BRUNODEA_CG_T1_SAMPLE_SPINNERS_PANE_H_

#include <SCV/Panel.h>
#include <vector>
#include "GUI/Sidebar/SampleValueSpinner.h"

namespace GUI
{
   class SampleSpinnersPanel : public scv::Panel
   {
   public:
      SampleSpinnersPanel(const scv::Panel &panel);
      ~SampleSpinnersPanel();

      void addRow(); //adiciona uma linha com 8 spinners.

   private:
      std::vector<std::vector<SampleValueSpinner *> *> m_vvSpinners;

   }; //end of class SampleSpinnersPanel.
} //end of namespace GUI.

#endif