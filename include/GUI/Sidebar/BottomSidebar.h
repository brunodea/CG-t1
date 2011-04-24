/**
  * BottomSidebar é um panel que fica na parte inferior da tela. Nele ficam os spinners que representam
  * a amostra, além de outras funcionalidades.
 **/
#ifndef _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_
#define _BRUNODEA_CG_T1_BOTTOM_SIDEBAR_PANE_

#include <SCV/Panel.h>
#include <SCV/Label.h>
#include <SCV/Separator.h>
#include <SCV/ScrollPane.h>
#include <vector>

#include "GUI/Sidebar/NumSampleSpinner.h"
#include "GUI/Sidebar/SampleValueSpinner.h"
#include "GUI/Sidebar/GenerateSampleButton.h"
#include "GUI/Sidebar/SampleSpinnersPanel.h"

namespace GUI
{
   class BottomSidebar : public scv::Panel
   {
   public:
      /*
       * Construtor.
       * pos_x/pos_y: posição da sidebar na tela.
       */
      BottomSidebar(int pos_x, int pos_y);
      ~BottomSidebar();
      
      /* Gera amostras aleatoriamente. */
      void generateRandomSample();
      /* Gera amostras lineares, com valor inicial aleatório. */
      void generateLinearSample();
      void generateSenoidalSample();
      /* Adiciona uma linha contendo MASTER_VALUE amostras (adicionando uma linha de spinners). */
      void addSampleRow();

   private: 
      SampleSpinnersPanel *m_pSpinnersPanel; //panel onde ficam os spinners com os valores da amostra.
      std::vector<GenerateSampleButton *> m_vGenerateSampleButtons; //vetor com os botoes para geracao automatica da amostra.

      scv::Label *m_pSampleLabel; //label "Sample:".
      scv::ScrollPane *m_pSampleScrollPanel; //scroll panel onde fica o panel dos spinners.

      NumSampleSpinner *m_pNumSampleSpinner; //spinner que ajusta a porção de sinais que serão enviados por vez para fazer a fdct e a idct.

   private:
      void initNumSampleSpinner();
      void initGenerateSampleButtons();
      void initSpinnersPanel();
      void initGUIMembers();

   }; //end of class BottomSidebar
} //end of namespace GUI.

#endif