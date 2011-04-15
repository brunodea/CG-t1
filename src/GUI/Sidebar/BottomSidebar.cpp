#include "../../../include/GUI/Sidebar/BottomSidebar.h"
#include "../../../include/macros.h"

#include <iostream>
#include <SCV/Point.h>

using namespace GUI;

BottomSidebar::BottomSidebar(int pos_x, int pos_y)
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, WINDOW_HEIGHT / 6)
{
   initSampleSpinners();
}

BottomSidebar::~BottomSidebar()
{
   for(unsigned int i = 0; i < m_vSampleSpinners.size(); i++)
      delete m_vSampleSpinners[i];
}

void BottomSidebar::initSampleSpinners()
{
   int number_of_initial_samples = 16;
   int y = 0;
   int x;
   int offset_x = SAMPLE_SPINNER_WIDTH / 2;

   int offset_y = 23;

   int col = 0;
   for(int i = 0; i < number_of_initial_samples; i++)
   {
      if(i % 8 == 0)
      {
         y += offset_y;
         col = 0;
      }
      x = col*SAMPLE_SPINNER_WIDTH + offset_x;
      SampleValueSpinner *spinner = new SampleValueSpinner(x, y);
      
      this->addComponent(spinner);
      m_vSampleSpinners.push_back(spinner);

      col++;
   }
}

