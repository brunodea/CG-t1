#ifndef _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_
#define _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_

#include <SCV/Spinner.h>
#include <SCV/Point.h>
#include "macros.h"

namespace GUI
{
   class SampleValueSpinner : public scv::Spinner
   {
   public:
      SampleValueSpinner(int pos_x, int pos_y);
      SampleValueSpinner(const scv::Point &p);

      inline void setVecPos(int i) { m_iVecPos = i; }
      inline int getVecPos() { return m_iVecPos; }

   private:
      int m_iVecPos; //position in the vector of sample value spinners.

   private:
      void onValueChange();

   }; //end of class SampleValueSpinner
} //end of namespace GUI.

#endif