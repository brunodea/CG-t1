#ifndef _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_
#define _BRUNODEA_CG_T1_SAMPLE_VALUE_SPINNER_H_

#include <SCV/Spinner.h>
#include "../../macros.h"

namespace GUI
{
   class SampleValueSpinner : public scv::Spinner
   {
   public:
      SampleValueSpinner(int pos_x, int pos_y);

   }; //end of class SampleValueSpinner
} //end of namespace GUI.

#endif