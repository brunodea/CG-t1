#ifndef _BRUNODEA_CG_T1_NUM_SAMPLE_SPINNER_H_
#define _BRUNODEA_CG_T1_NUM_SAMPLE_SPINNER_H_

#include <SCV/Spinner.h>
#include <SCV/Point.h>

namespace GUI
{
   class NumSampleSpinner : public scv::Spinner
   {
   public:
      NumSampleSpinner(const scv::Point &p);

   protected:
      void onValueChange();

   private:
      int m_iLastValue;
   }; //end of class NumSampleSpinner.
} //end of namespace GUI.

#endif
