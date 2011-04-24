/*
 * Classe que contém as ações dos botões que ficam na BottomSidebar.
 */

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
      //Tipos dos botões.
      enum Type
      {
         RANDOM = 0, //generate a random sample.
         LINEAR, //generate a linear sample.
         SENOIDAL,
         ADD_ROW //add a row to the sample.

      }; //end of enum ButtonType.

   public:
      /*
       * Construtor.
       * p: posição do botão.
       * label: label do botão.
       * type: tipo do botão.
       */
      GenerateSampleButton(const scv::Point &p, const std::string &label, Type type);

      /* Getter. */
      inline Type &getType() { return m_Type; }
      
   protected:
      /* CallBack. */
      void onMouseClick(const scv::MouseEvent &evt);

   private:
      Type m_Type; //tipo do botão.

   }; //end of the class GenerateSampleButton
} //end of the namespace GUI.

#endif
