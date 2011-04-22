#include "GUI/Sidebar/SampleValueSpinner.h"
#include "DCTViewer.h"
#include "macros.h"

#include <SCV/Point.h>
#include <iostream>

#include "GUI/Sidebar/BottomSidebar.h"

using namespace GUI;

SampleValueSpinner::SampleValueSpinner(int pos_x, int pos_y)
   : scv::Spinner(scv::Point(pos_x, pos_y), SAMPLE_SPINNER_WIDTH, SAMPLE_SPINNER_MIN_VALUE, SAMPLE_SPINNER_MAX_VALUE, 0, 1)
{
   setVecPos(0);
}

SampleValueSpinner::SampleValueSpinner(const scv::Point &p)
   : scv::Spinner(p, SAMPLE_SPINNER_WIDTH, SAMPLE_SPINNER_MIN_VALUE, SAMPLE_SPINNER_MAX_VALUE, 0, 1)
{
   setVecPos(0);
}

void SampleValueSpinner::onValueChange()
{
   int row = m_iVecPos / 8;
   int col = m_iVecPos % 8;

   std::vector<double> *v = DCTVIEWER->getSignals()->at(row);
   double *orig = &v->at(col);
   *orig = this->getValue();

   DCTVIEWER->getGraphsCanvas()->getOrigSampleGraph()->adjustPoint(row, col);
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoint(row, col);
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoint(row, col);

   //mudancas feitas pelo usuario em um spinner.
   if(this->isFocused())
   {      
      DCTVIEWER->adjustFDCTSignals();
      DCTVIEWER->adjustIDCTSignals();
      DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
      DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
   }
}
