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
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, WINDOW_HEIGHT / 6)
{
   initGUIMembers();
}

BottomSidebar::~BottomSidebar()
{
   delete m_pSampleLabel;
   for(unsigned int i = 0; i < m_vGenerateSampleButtons.size(); i++)
      delete m_vGenerateSampleButtons[i];
   delete m_pSpinnersPanel;
   delete m_pSampleScrollPanel;
}

BottomSidebar *BottomSidebar::instance()
{
   if(m_sInstance == NULL)
      m_sInstance = new BottomSidebar(0,  WINDOW_HEIGHT - (WINDOW_HEIGHT / 6));
   return m_sInstance;
}

void BottomSidebar::initGenerateSampleButtons()
{
   scv::Point p(m_pSampleScrollPanel->getRelativePosition().x + m_pSampleScrollPanel->getWidth() + 10, 20);
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
	m_pSpinnersPanel = new SampleSpinnersPanel(scv::Point(0, 0), SAMPLE_SPINNER_WIDTH*10.5, 150);
   m_pSampleScrollPanel = new scv::ScrollPane(scv::Point(100, 0), SAMPLE_SPINNER_WIDTH*11.5, 150, m_pSpinnersPanel);
   this->addComponent(m_pSampleScrollPanel);
}

void BottomSidebar::initGUIMembers()
{
   m_pSampleLabel = new scv::Label(scv::Point(10, 5), "Sample Vector:");   

   this->addComponent(m_pSampleLabel);

   initSpinnersPanel();
   initGenerateSampleButtons();
}

void BottomSidebar::generateRandomSample()
{
   m_pSpinnersPanel->generateRandomSample();
}

void BottomSidebar::generateLinearSample()
{
   m_pSpinnersPanel->generateRandomSample();
}
