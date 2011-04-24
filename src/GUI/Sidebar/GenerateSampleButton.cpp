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
   /* Dependendo do tipo de botão, uma ação diferente é realizada quando o usuário clica nele. */
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
   
   /* Após a ação, é necessário ajustar os sinais da FDCT e IDCT. *Os sinais originais são atualizados nas funções do switch. */
   DCTVIEWER->adjustFDCTSignals();
   DCTVIEWER->adjustIDCTSignals();
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
}

