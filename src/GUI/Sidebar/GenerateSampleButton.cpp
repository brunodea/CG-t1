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
   
   DCTVIEWER->adjustFDCTSignals();
   DCTVIEWER->adjustIDCTSignals();
   DCTVIEWER->getGraphsCanvas()->getFDCTGraph()->adjustPoints();
   DCTVIEWER->getGraphsCanvas()->getIDCTGraph()->adjustPoints();
}

