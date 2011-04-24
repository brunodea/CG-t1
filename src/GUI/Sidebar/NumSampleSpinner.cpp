#include "GUI/Sidebar/NumSampleSpinner.h"
#include "macros.h"
#include "DCTViewer.h"

#include <iostream>

using namespace GUI;

NumSampleSpinner::NumSampleSpinner(const scv::Point &p) 
   : scv::Spinner(p, SAMPLE_SPINNER_WIDTH, MASTER_VALUE, MASTER_VALUE*100, MASTER_VALUE, MASTER_VALUE)
{
   m_iLastValue = MASTER_VALUE;
}

void NumSampleSpinner::onValueChange()
{
   /* Impede que o valor do spinner seja algum valor não-múltiplo do MASTER_VALUE. */
   if((int)getValue() % MASTER_VALUE != 0)
   {
      setValue(m_iLastValue);
      return;
   }
      
   m_iLastValue = (int)getValue();
   DCTVIEWER->setSizeSample((int) m_iLastValue/MASTER_VALUE);
   
   /* Após o valor setado, é necessário ajustar a FDCT e a IDCT. */
   DCTVIEWER->adjustFDCTSignals();
   DCTVIEWER->adjustIDCTSignals();
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
}

