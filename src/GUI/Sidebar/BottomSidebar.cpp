#include "GUI/Sidebar/BottomSidebar.h"
#include "macros.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SCV/Point.h>

using namespace GUI;

BottomSidebar *BottomSidebar::m_sInstance = NULL;

BottomSidebar::BottomSidebar(int pos_x, int pos_y)
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, WINDOW_HEIGHT / 6),
     m_iElementsInSample(16)
{
   initGUIMembers();
}

BottomSidebar::~BottomSidebar()
{
   delete m_pSeparator;
   delete m_pSampleLabel;
   for(unsigned int i = 0; i < m_vSampleSpinners.size(); i++)
      delete m_vSampleSpinners[i];
   for(unsigned int i = 0; i < m_vGenerateSampleButtons.size(); i++)
      delete m_vGenerateSampleButtons[i];
}

BottomSidebar *BottomSidebar::instance()
{
   if(m_sInstance == NULL)
      m_sInstance = new BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 6));
   return m_sInstance;
}

void BottomSidebar::initSampleSpinners()
{
   int y = 0;
   int x;
   int offset_x = SAMPLE_SPINNER_WIDTH / 2;

   int offset_y = 23;

   int col = 0;
   for(int i = 0; i < m_iElementsInSample; i++)
   {
      if(i % 8 == 0)
      {
         y += offset_y;
         col = 0;
      }
      x = col*SAMPLE_SPINNER_WIDTH + offset_x;
      SampleValueSpinner *spinner = new SampleValueSpinner(x, y);
      spinner->setVecPos(i);
      this->addComponent(spinner);
      m_vSampleSpinners.push_back(spinner);

      col++;
   }
}

void BottomSidebar::initGenerateSampleButtons()
{
   scv::Point p(500, 20);
   GenerateSampleButton *random_button = new GenerateSampleButton(p, "Random Values", GenerateSampleButton::RANDOM);
   m_vGenerateSampleButtons.push_back(random_button);

   p.y += random_button->getHeight() + 5;
   GenerateSampleButton *linear_button = new GenerateSampleButton(p, "Linear Values", GenerateSampleButton::LINEAR);
   linear_button->setWidth(random_button->getWidth());

   this->addComponent(random_button);
   this->addComponent(linear_button);
}

void BottomSidebar::initGUIMembers()
{
   m_pSampleLabel = new scv::Label(scv::Point(10, 5), "Sample Vector:");   
   m_pSeparator = new scv::Separator(scv::Point(450, 10), scv::Separator::vertical, getHeight() - 20);

   this->addComponent(m_pSampleLabel);
   this->addComponent(m_pSeparator);

   initSampleSpinners();
   initGenerateSampleButtons();
   
}

void BottomSidebar::generateRandomSample()
{
   srand((unsigned)time(NULL));

   for(unsigned int i = 0; i < m_vSampleSpinners.size(); i++)
   {
      SampleValueSpinner *spinner = m_vSampleSpinners.at(i);
      spinner->setValue(rand() % 255);
   }
}

void BottomSidebar::generateLinearSample()
{
   srand((unsigned)time(NULL));

   int first = (rand() % 20) + 1;
   for(unsigned int i = 0; i < m_vSampleSpinners.size(); i++)
   {
      SampleValueSpinner *spinner = m_vSampleSpinners.at(i);
      spinner->setValue(first*(i + 1));
   }
}
