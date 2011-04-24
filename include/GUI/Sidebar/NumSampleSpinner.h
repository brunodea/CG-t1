/*
 * Classe que representa o spinner para a determinação do tamanho da amostra
 * que vai ser passada para a FDCT e IDCT.
 */
#ifndef _BRUNODEA_CG_T1_NUM_SAMPLE_SPINNER_H_
#define _BRUNODEA_CG_T1_NUM_SAMPLE_SPINNER_H_

#include <SCV/Spinner.h>
#include <SCV/Point.h>

namespace GUI
{
   class NumSampleSpinner : public scv::Spinner
   {
   public:
      /*
       * Construtor.
       * p: posição do spinner.
       */
      NumSampleSpinner(const scv::Point &p);

   protected:
      /* CallBack */
      void onValueChange();

   private:
      int m_iLastValue; //último valor válido do spinner.

   }; //end of class NumSampleSpinner.
} //end of namespace GUI.

#endif
