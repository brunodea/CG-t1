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
      void adjustPoints();
      void draw();

      void setScale(const double &scale);
      inline double &getScale() { return m_Scale; }

   public:
      scv::Point m_Pos0x0;
      double m_XLength;
      double m_YLength;

   private:
      std::vector<GraphPoint *> *m_vpPoints;
      double m_Scale;

   private:
      void drawAxis();
      void drawPoints();
      
      void insertPoints();
      void cleanPoints();

   }; //end of class Graph.

} //end of namespace GUI.

#endif
