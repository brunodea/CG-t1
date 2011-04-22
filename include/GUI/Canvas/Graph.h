#ifndef _BRUNODEA_CG_T1_GRAPH_H_
#define _BRUNODEA_CG_T1_GRAPH_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>
#include <vector>
#include "GUI/Canvas/GraphPoint.hpp"

namespace GUI
{
   class Graph
   {
   public:
      Graph(const scv::Point &p0x0, unsigned int xLenght, unsigned int yLength);
      ~Graph();

      void addPoints(const std::vector<GraphPoint *> &points);
      void adjustPoint(unsigned int row, unsigned int col);
      void draw();

   public:
      scv::Point m_Pos0x0;
      unsigned int m_XLength;
      unsigned int m_YLength;

   private:
      std::vector<GraphPoint *> *m_vpPoints;


   private:
      void drawAxis();
      void drawPoints();
      
      void adjustPoints();
      void insertPoints();
      void cleanPoints();

   }; //end of class Graph.

} //end of namespace GUI.

#endif
