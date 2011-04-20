#include "GUI/Sidebar/SampleSpinnersPanel.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include <SCV/Label.h>
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
   unsigned int spinnersSize = m_vvSpinners.size();
	int y = spinnersSize*23;
   int x = 10;
   int offset_x = 15;
   std::vector<SampleValueSpinner *> *v = new std::vector<SampleValueSpinner *>();
   SampleValueSpinner *spinner_aux;
   for(int i = 0; i < 8; i++)
   {
      int pos = (spinnersSize*8) + i;
      std::stringstream ss;
      ss << pos;
      scv::Label *label = new scv::Label(scv::Point(x, y + 3), ss.str());
      this->addComponent(label);
      spinner_aux = new SampleValueSpinner(x + label->getWidth(), y);
      spinner_aux->setVecPos(pos);

      this->addComponent(spinner_aux);
      v->push_back(spinner_aux);
      x += SAMPLE_SPINNER_WIDTH + offset_x;
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
