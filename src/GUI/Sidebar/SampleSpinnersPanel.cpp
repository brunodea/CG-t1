#include "GUI/Sidebar/SampleSpinnersPanel.h"

using namespace GUI;

SampleSpinnersPanel::SampleSpinnersPanel(const scv::Panel &p)
   : scv::Panel(p)
{
   addRow(); //inicia com 8 spinners.
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
   int y = 0;
   int x;
   int offset_x = SAMPLE_SPINNER_WIDTH / 2;
   int offset_y = 23;
   int col = 0;
   std::vector<SampleValueSpinner *> *v = new std::vector<SampleValueSpinner *>(8);
   for(int i = 0; i < 8; i++)
   {
      if(i % 8 == 0)
      {
         y += offset_y;
         col = 0;
      }
      x = col*SAMPLE_SPINNER_WIDTH + offset_x;
      SampleValueSpinner *s = new SampleValueSpinner(x, y);
      s->setVecPos(i);
      this->addComponent(s);
      v->push_back(s);
      col++;
   }
   m_vvSpinners.push_back(v);
}
