#include "GUI/Sidebar/SampleSpinnersPanel.h"
#include "macros.h"
#include "DCTViewer.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include <SCV/Label.h>

using namespace GUI;

SampleSpinnersPanel::SampleSpinnersPanel(const scv::Point &p, unsigned int width, unsigned int height)
   : scv::Panel(p, width, height)
{
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

   //Limita em 1000 o número de spinners possíveis para serem adicionados ao panel.
   //isso resulta em 1000/MASTER_VALUE linhas de spinners.
   if(spinnersSize >= 1000/MASTER_VALUE)
   {
      std::cout << "Limit number of rows of spinners reached." << std::endl;
      return;
   }

   DCTVIEWER->addSignalVec(); //deixa o signalvec sempre atualizado qnt ao numero de signals.

	int y = spinnersSize*23;
   int x = 5;
   int offset_x = 18;
   std::vector<SampleValueSpinner *> *v = new std::vector<SampleValueSpinner *>();
   SampleValueSpinner *spinner_aux;

   /* Cria uma linha com MASTER_VALUE spinners e ajusta suas posições. */
   for(int i = 0; i < MASTER_VALUE; i++)
   {
      int pos = (spinnersSize*MASTER_VALUE) + i;
      std::stringstream ss;
      ss << pos;
      scv::Label *label = new scv::Label(scv::Point(x, y + 3), ss.str());
      this->addComponent(label);
      spinner_aux = new SampleValueSpinner(x + 18, y);
      spinner_aux->setVecPos(pos);

      this->addComponent(spinner_aux);
      v->push_back(spinner_aux);
      x += SAMPLE_SPINNER_WIDTH + offset_x;
   }
   m_vvSpinners.push_back(v);
   this->setHeight(y+spinner_aux->getHeight());
}

void SampleSpinnersPanel::generateRandomSample()
{
   srand((unsigned)time(NULL));
   for(unsigned int i = 0; i < m_vvSpinners.size(); i++)
   {
      std::vector<SampleValueSpinner *> *v = m_vvSpinners.at(i);
      std::vector<double> *signalVec = DCTVIEWER->getSignals()->at(i);
      for(unsigned int j = 0; j < v->size(); j++)
      {
         double value = rand() % (SAMPLE_SPINNER_MAX_VALUE + 1);
         v->at(j)->setValue(value);
         
         double *orig = &signalVec->at(j);
         *orig = value;
      }
   }
}

void SampleSpinnersPanel::generateLinearSample()
{
   srand((unsigned)time(NULL));

   int first = (rand() % 20) + 1;
   for(unsigned int i = 0; i < m_vvSpinners.size(); i++)
   {
      std::vector<SampleValueSpinner *> *v = m_vvSpinners.at(i);
      std::vector<double> *signalVec = DCTVIEWER->getSignals()->at(i);
      for(unsigned int j = 0; j < v->size(); j++)
      {
         double value = first*(((i + 1)*MASTER_VALUE) + j)*0.1;
         v->at(j)->setValue(value);

         double *orig = &signalVec->at(j);
         *orig = value;
      }
   }
}
