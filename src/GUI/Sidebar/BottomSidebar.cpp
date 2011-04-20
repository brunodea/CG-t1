#include "GUI/Sidebar/BottomSidebar.h"
#include "macros.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SCV/Point.h>
#include <SCV/ScrollPane.h>

using namespace GUI;

BottomSidebar *BottomSidebar::m_sInstance = NULL;

BottomSidebar::BottomSidebar(int pos_x, int pos_y)
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, WINDOW_HEIGHT / 4)
{
   initGUIMembers();
}

BottomSidebar::~BottomSidebar()
{
   delete m_pSeparator;
   delete m_pSampleLabel;
   for(unsigned int i = 0; i < m_vGenerateSampleButtons.size(); i++)
      delete m_vGenerateSampleButtons[i];
   delete m_pSpinnersPanel;
}

BottomSidebar *BottomSidebar::instance()
{
   if(m_sInstance == NULL)
      m_sInstance = new BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 4));
   return m_sInstance;
}

void BottomSidebar::initGenerateSampleButtons()
{
   scv::Point p(600, 20);
   GenerateSampleButton *random_button = new GenerateSampleButton(p, "Random Values", GenerateSampleButton::RANDOM);
   m_vGenerateSampleButtons.push_back(random_button);

   p.y += random_button->getHeight() + 5;
   GenerateSampleButton *linear_button = new GenerateSampleButton(p, "Linear Values", GenerateSampleButton::LINEAR);
   linear_button->setWidth(random_button->getWidth());

   this->addComponent(random_button);
   this->addComponent(linear_button);
}

void BottomSidebar::initSpinnersPanel()
{
   scv::Panel *p = new scv::Panel(scv::Point(0, 0), 600, 200);
   
   SampleValueSpinner *aux = new SampleValueSpinner(30, 20);
   p->addComponent(aux);
   m_pSpinnersPanel = new SampleSpinnersPanel(*p);
   scv::ScrollPane *sp = new scv::ScrollPane(scv::Point(10, 10), 
      300, 130, m_pSpinnersPanel);
   this->addComponent(sp);
}

void BottomSidebar::initGUIMembers()
{
   //m_pSampleLabel = new scv::Label(scv::Point(10, 5), "Sample Vector:");   
   //m_pSeparator = new scv::Separator(scv::Point(450, 10), scv::Separator::vertical, getHeight() - 20);

   //this->addComponent(m_pSampleLabel);
   //this->addComponent(m_pSeparator);

   initGenerateSampleButtons();
   initSpinnersPanel();   
}

void BottomSidebar::generateRandomSample()
{
   m_pSpinnersPanel->generateRandomSample();
}

void BottomSidebar::generateLinearSample()
{
   m_pSpinnersPanel->generateRandomSample();
}
