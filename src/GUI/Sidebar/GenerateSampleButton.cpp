#include "GUI/Sidebar/GenerateSampleButton.h"
#include "DCTViewer.h"
#include "macros.h"

#include <iostream>

using namespace GUI;

GenerateSampleButton::GenerateSampleButton(const scv::Point &p, const std::string &label, Type type)
   : scv::Button(p, label), m_Type(type)
{
}

void GenerateSampleButton::onMouseClick(const scv::MouseEvent &evt)
{
   /* Dependendo do tipo de bot�o, uma a��o diferente � realizada quando o usu�rio clica nele. */
   switch(getType())
   {
   case RANDOM:
      DCTVIEWER->getBottomSidebar()->generateRandomSample();
      break;
   case LINEAR:
      DCTVIEWER->getBottomSidebar()->generateLinearSample();
      break;
   case ADD_ROW:
      DCTVIEWER->getBottomSidebar()->addSampleRow();
   }
   
   /* Ap�s a a��o, � necess�rio ajustar os sinais da FDCT e IDCT. *Os sinais originais s�o atualizados nas fun��es do switch. */
   DCTVIEWER->adjustFDCTSignals();
   DCTVIEWER->adjustIDCTSignals();
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
}

