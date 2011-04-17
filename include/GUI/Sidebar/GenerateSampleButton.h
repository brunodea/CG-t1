#ifndef _BRUNODEA_CG_T1_GENERATE_SAMPLE_BUTTON_H_
#define _BRUNODEA_CG_T1_GENERATE_SAMPLE_BUTTON_H_

#include <SCV/Button.h>
#include <SCV/Point.h>
#include <string>

namespace GUI
{
   class GenerateSampleButton : public scv::Button
   {
   public:
      GenerateSampleButton(const scv::Point &p, const std::string &label);

   }; //end of the class GenerateSampleButton
} //end of the namespace GUI.

#endif
