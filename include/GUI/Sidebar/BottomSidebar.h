/**
  * BottomSidebar eh um panel que fica na parte inferior da tela. Nele ficam os spinners que representam
  * a amostra. Como soh pode existir um BottomSidebar, ele eh singleton.
 **/
#ifndef _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_
#define _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_

#include <SCV/Panel.h>
#include <SCV/Label.h>
#include <SCV/Separator.h>
#include <vector>

#include "GUI/Sidebar/SampleValueSpinner.h"
#include "GUI/Sidebar/GenerateSampleButton.h"

namespace GUI
{
   class BottomSidebar : public scv::Panel
   {
   public:
      static BottomSidebar *instance(); //Retorna a unica instancia da classe.
      ~BottomSidebar();
      
      void generateRandomSample();
      void generateLinearSample();

   private:
      static BottomSidebar *m_sInstance;     

      std::vector<GenerateSampleButton *> m_vGenerateSampleButtons; //vetor com os botoes para geracao automatica da amostra.

      scv::Label *m_pSampleLabel;
      scv::Separator *m_pSeparator;

   private:
      BottomSidebar(int pos_x, int pos_y); //contrutor privado pois se trata de um singleton.
      void initGenerateSampleButtons();
      void initGUIMembers();

   }; //end of class BottomSidebar
} //end of namespace GUI.

#endif