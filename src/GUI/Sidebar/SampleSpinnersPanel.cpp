#include "GUI/Sidebar/SampleSpinnersPanel.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace GUI;

SampleSpinnersPanel::SampleSpinnersPanel(const scv::Point &p, unsigned int width, unsigned int height)
   : scv::Panel(p, width, height)
{
   addRow(); //inicia com 8 spinners.
   this->setVisible(true);
}

SampleSpinnersPanel::~SampleSpinnersPanel()
{
   for(unsigned int i = 0; i < m_vvSpinners.size(); i++)
   {
      std::vector<SampleValueSpinner *> *v = m_vvSpinners.at(i);
      for(unsigned int j = 0; j < v->size(); j++)
         delete v->at(j);
      v->clear();
      delete []v;
   }
   m_vvSpinners.clear();
}

void SampleSpinnersPanel::addRow()
{
	int y = m_vvSpinners.size()*23;
   int x;
   int offset_x = SAMPLE_SPINNER_WIDTH / 2;
   std::vector<SampleValueSpinner *> *v = new std::vector<SampleValueSpinner *>();
   SampleValueSpinner *spinner_aux;
   for(int i = 0; i < 8; i++)
   {
      x = i*SAMPLE_SPINNER_WIDTH + offset_x;
      spinner_aux = new SampleValueSpinner(x, y);
      spinner_aux->setVecPos(i);
      this->addComponent(spinner_aux);
      v->push_back(spinner_aux);
   }
   m_vvSpinners.push_back(v);
   this->setHeight(50+m_vvSpinners.size()*spinner_aux->getHeight());
}

void SampleSpinnersPanel::generateRandomSample()
{
   srand((unsigned)time(NULL));
   for(unsigned int i = 0; i < m_vvSpinners.size(); i++)
   {
      std::vector<SampleValueSpinner *> *v = m_vvSpinners.at(i);
      for(unsigned int j = 0; j < v->size(); j++)
         v->at(j)->setValue(rand() % 256);
   }
}

void SampleSpinnersPanel::generateLinearSample()
{
   srand((unsigned)time(NULL));

   int first = (rand() % 20) + 1;
   for(unsigned int i = 0; i < m_vvSpinners.size(); i++)
   {
      std::vector<SampleValueSpinner *> *v = m_vvSpinners.at(i);
      for(unsigned int j = 0; j < v->size(); j++)
         v->at(j)->setValue(first*(i + 1)*0.5);
   }
}
