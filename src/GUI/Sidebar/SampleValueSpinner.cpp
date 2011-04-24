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
   /* Quando o valor do spinner é alterado, o vetor de sinais originais é ajustado,
    * bem como o da FDCT e IDCT. Ajustando também seus gráficos.
    */
   int row = m_iVecPos / MASTER_VALUE;
   int col = m_iVecPos % MASTER_VALUE;

   std::vector<double> *v = DCTVIEWER->getSignals()->at(row);
   double *orig = &v->at(col);
   *orig = this->getValue();

   /* Ajusta os gráficos. */
   DCTVIEWER->getGraphsCanvas()->getOrigSampleGraph()->adjustPoint(row, col);
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoint(row, col);
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoint(row, col);

   /* Caso o spinner esteja em foco e seu valor é alterado, os sinais e os gráficos são ajustados. */
   if(isFocused())
   {
      DCTVIEWER->adjustFDCTSignals();
      DCTVIEWER->adjustIDCTSignals();
      DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
      DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
   }
}
