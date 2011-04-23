#include "GUI/Sidebar/BottomSidebar.h"
#include "macros.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SCV/Point.h>
#include <SCV/ScrollPane.h>

using namespace GUI;

BottomSidebar::BottomSidebar(int pos_x, int pos_y)
   : scv::Panel(scv::Point(pos_x, pos_y), WINDOW_WIDTH, BOTTOM_SIDEBAR_HEIGHT)
{
   m_pSampleScrollPanel = NULL;
   initGUIMembers();
}

BottomSidebar::~BottomSidebar()
{
   delete m_pSampleLabel;
   for(unsigned int i = 0; i < m_vGenerateSampleButtons.size(); i++)
      delete m_vGenerateSampleButtons[i];
   delete m_pSpinnersPanel;
   delete m_pSampleScrollPanel;
   delete m_pNumSampleSpinner;
}

void BottomSidebar::initGenerateSampleButtons()
{
   scv::Point p(m_pSampleScrollPanel->getRelativePosition().x + m_pSampleScrollPanel->getWidth() + 10, 20);
   GenerateSampleButton *random_button = new GenerateSampleButton(p, "Random Values", GenerateSampleButton::RANDOM);

   p.y += random_button->getHeight() + 5;
   GenerateSampleButton *linear_button = new GenerateSampleButton(p, "Linear Values", GenerateSampleButton::LINEAR);
   linear_button->setWidth(random_button->getWidth());

   p.y += random_button->getHeight() + 5;
   GenerateSampleButton *add_row_button = new GenerateSampleButton(p, "Add Row", GenerateSampleButton::ADD_ROW);
   add_row_button->setWidth(random_button->getWidth());

   m_vGenerateSampleButtons.push_back(random_button);
   m_vGenerateSampleButtons.push_back(linear_button);
   m_vGenerateSampleButtons.push_back(add_row_button);

   this->addComponent(random_button);
   this->addComponent(linear_button);
   this->addComponent(add_row_button);
}

void BottomSidebar::initSpinnersPanel()
{
	m_pSpinnersPanel = new SampleSpinnersPanel(scv::Point(0, 0), SAMPLE_SPINNER_WIDTH*11, 150);
   
   m_pSampleScrollPanel = new scv::ScrollPane(scv::Point(100, 5), SAMPLE_SPINNER_WIDTH*12, 150, m_pSpinnersPanel);
   this->addComponent(m_pSampleScrollPanel);
}

void BottomSidebar::initGUIMembers()
{
   m_pSampleLabel = new scv::Label(scv::Point(10, 5), "Sample Vector:");   

   this->addComponent(m_pSampleLabel);

   initSpinnersPanel();
   initGenerateSampleButtons();
   initNumSampleSpinner();
}

void BottomSidebar::generateRandomSample()
{
   m_pSpinnersPanel->generateRandomSample();
}

void BottomSidebar::generateLinearSample()
{
   m_pSpinnersPanel->generateLinearSample();
}

void BottomSidebar::addSampleRow()
{
   m_pSpinnersPanel->addRow();   
   m_pSampleScrollPanel->registerPanel(m_pSpinnersPanel);
   m_pSampleScrollPanel->setHeight(120);
}

void BottomSidebar::initNumSampleSpinner()
{
   m_pNumSampleSpinner = new NumSampleSpinner(scv::Point(10, 30));
   this->addComponent(m_pNumSampleSpinner);
}
