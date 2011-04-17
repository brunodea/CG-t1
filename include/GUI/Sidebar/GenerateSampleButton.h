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
      enum ButtonType
      {
         RANDOM = 0, //generate a random sample.
         LINEAR //generate a linear sample.

      }; //end of enum ButtonType.

   public:
      GenerateSampleButton(const scv::Point &p, const std::string &label, ButtonType type);

      inline ButtonType &getType() { return m_Type; }

   private:
      ButtonType m_Type;

   }; //end of the class GenerateSampleButton
} //end of the namespace GUI.

#endif
