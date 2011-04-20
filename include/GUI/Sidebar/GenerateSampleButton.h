#ifndef _BRUNODEA_CG_T1_GENERATE_SAMPLE_BUTTON_H_
#define _BRUNODEA_CG_T1_GENERATE_SAMPLE_BUTTON_H_

#include <SCV/Button.h>
#include <SCV/Point.h>
#include <string>

#include <SCV/MouseEvent.h>

namespace GUI
{
   class GenerateSampleButton : public scv::Button
   {
   public:      
      enum Type
      {
         RANDOM = 0, //generate a random sample.
         LINEAR, //generate a linear sample.
         ADD_ROW //add a row to the sample.

      }; //end of enum ButtonType.

   public:
      GenerateSampleButton(const scv::Point &p, const std::string &label, Type type);

      inline Type &getType() { return m_Type; }

   private:
      Type m_Type;

   private:
      void onMouseClick(const scv::MouseEvent &evt);

   }; //end of the class GenerateSampleButton
} //end of the namespace GUI.

#endif
