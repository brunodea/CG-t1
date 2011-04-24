/*
 * Classe que 'segura' os spinners da amostra em um panel.
 */
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
      /*
       * Construtor.
       * p: posi��o onde esse panel vai se localizar.
       * width/height: dimens�es do panel.
       */
      SampleSpinnersPanel(const scv::Point &p, unsigned int width, unsigned int height);
      ~SampleSpinnersPanel();

      void addRow(); //adiciona uma linha com MASTER_VALUE spinners.
      void generateRandomSample(); //gera uma amostra aleat�ria.
      void generateLinearSample(); //gera uma amostra linear.

   private:
      std::vector<std::vector<SampleValueSpinner *> *> m_vvSpinners; //vetor de spinners que far�o parte do panel.

   }; //end of class SampleSpinnersPanel.
} //end of namespace GUI.

#endif