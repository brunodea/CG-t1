#include "../../../include/GUI/Sidebar/GenerateSampleButton.h"

using namespace GUI;

GenerateSampleButton::GenerateSampleButton(const scv::Point &p, const std::string &label, ButtonType type)
   : scv::Button(p, label), m_Type(type)
{
}

