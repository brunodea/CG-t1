#include "../../../include/GUI/Sidebar/GenerateSampleButton.h"
#include "../../../include/GUI/Sidebar/BottomSidebar.h"

#include <iostream>

using namespace GUI;

GenerateSampleButton::GenerateSampleButton(const scv::Point &p, const std::string &label, Type type)
   : scv::Button(p, label), m_Type(type)
{
}

void GenerateSampleButton::onMouseClick(const scv::MouseEvent &evt)
{
   switch(getType())
   {
   case RANDOM:
      //std::cout << "Generate Random Sample button clicked." << std::endl;
      BottomSidebar::instance()->generateRandomSample();
      break;
   case LINEAR:
      //std::cout << "Generate Linear Sample button clicked." << std::endl;
      BottomSidebar::instance()->generateLinearSample();
      break;
   }
}

