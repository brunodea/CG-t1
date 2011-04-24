/*
 * Classe que guarda os sinais da amostra original e possibilita a alteração de seus valores ao usuário.
 */
#ifndef _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_
#define _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_

#include <SCV/Spinner.h>
#include <SCV/Point.h>
#include <SCV/KeyEvent.h>
#include "macros.h"

namespace GUI
{
   class SampleValueSpinner : public scv::Spinner
   {
   public:
      /* Construtores. */
      SampleValueSpinner(int pos_x, int pos_y);
      SampleValueSpinner(const scv::Point &p);

      /* Setter e Getter. */
      inline void setVecPos(int i) { m_iVecPos = i; }
      inline int getVecPos() { return m_iVecPos; }

   protected:
      /* Callback. */
      void onValueChange();

   private:
      int m_iVecPos; //posição no vetor de amostras.

   }; //end of class SampleValueSpinner
} //end of namespace GUI.

#endif