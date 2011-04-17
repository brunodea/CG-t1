/**
  * BottomSidebar eh um panel que fica na parte inferior da tela. Nele ficam os spinners que representam
  * a amostra. Como soh pode existir um BottomSidebar, ele eh singleton.
 **/
#ifndef _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_
#define _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_

#include <SCV/Panel.h>
#include <SCV/Label.h>
#include <vector>

#include "SampleValueSpinner.h"

namespace GUI
{
   class BottomSidebar : public scv::Panel
   {
   public:
      static BottomSidebar *instance(); //Retorna a unica instancia da classe.
      ~BottomSidebar();

      inline int getNumberOfSamples() { return m_iElementsInSample; }

   private:
      static BottomSidebar *m_sInstance;

      std::vector<SampleValueSpinner *> m_vSampleSpinners; //vetor com a amostra.
      int m_iElementsInSample; //numero de elementos na amostra (8 ou 16).      

      scv::Label *m_pSampleLabel;

   private:
      BottomSidebar(int pos_x, int pos_y); //contrutor privado pois se trata de um singleton.
      void initSampleSpinners();
      void initGUIMembers();

   }; //end of class BottomSidebar
} //end of namespace GUI.

#endif