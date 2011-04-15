#include "../../../include/GUI/Sidebar/BottomSidebar.h"
#include "../../../include/macros.h"

#include <SCV/Point.h>

using namespace GUI;

BottomSidebar::BottomSidebar(int pos_x, int pos_y)
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, WINDOW_HEIGHT / 6)
{
   initSampleSpinners();
}

BottomSidebar::~BottomSidebar()
{
   for(int i = 0; i < m_vSampleSpinners.size(); i++)
      delete m_vSampleSpinners[i];
}

void BottomSidebar::initSampleSpinners()
{
   int number_of_initial_samples = 8;
   int y = this->getAbsolutePosition().y + this->getHeight() / 2;
   for(int i = 0; i < number_of_initial_samples; i++)
   {
      if(y % 8 == 0)
         y += this->getHeight() / 4;
      SampleValueSpinner *spinner = new SampleValueSpinner(WINDOW_WIDTH + i + 5, y); 
      this->addComponent(spinner);
      m_vSampleSpinners.push_back(spinner);
   }
}

