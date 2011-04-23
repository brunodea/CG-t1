#include "GUI/Sidebar/NumSampleSpinner.h"
#include "macros.h"

#include <iostream>

using namespace GUI;

NumSampleSpinner::NumSampleSpinner(const scv::Point &p) 
   : scv::Spinner(p, SAMPLE_SPINNER_WIDTH, 8, 800, 8, 8)
{
   m_iLastValue = 8;
}

void NumSampleSpinner::onValueChange()
{
   if((int)getValue() % 8 != 0)
   {
      setValue(m_iLastValue);
      return;
   }
      
   m_iLastValue = (int)getValue();
}

