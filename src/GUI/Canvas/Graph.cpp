#include "GUI/Canvas/Graph.h"
#include "DCTViewer.h"
#include "macros.h"

#include <iostream>

using namespace GUI;

Graph::Graph(const scv::Point &p0x0, unsigned int xLength, unsigned int yLength)
   : m_Pos0x0(p0x0), m_XLength(xLength), m_YLength(yLength)
{
   m_vpPoints = new std::vector<GraphPoint *>();
   m_Scale = 1;
}

Graph::~Graph()
{
   cleanPoints();
   delete []m_vpPoints;
}

void Graph::setScale(const double &scale)
{
   m_Scale = scale;
   m_XLength *= m_Scale;
   m_YLength *= m_Scale;
}

void Graph::addPoints(const std::vector<GraphPoint *> &points)
{
   m_vpPoints->insert(m_vpPoints->end(), points.begin(), points.end());
}

void Graph::adjustPoint(unsigned int row, unsigned int col)
{
   int pos = (row*8) + col;
   GraphPoint *pt = m_vpPoints->at(pos);
   pt->m_Pos.y = -DCTVIEWER->getSignals()->at(row)->at(col) + m_Pos0x0.y;
}

void Graph::adjustPoints()
{
   unsigned int signalsSize = DCTVIEWER->getSignals()->size()*8;
   unsigned int pointsSize = m_vpPoints->size();
   double x_spacement = (double)m_XLength/signalsSize;
   unsigned int size = DCTVIEWER->getSignals()->size();

   for(unsigned int i = 0; i < pointsSize; i++)
   {
      double x = (x_spacement*i) + m_Pos0x0.x;
      GraphPoint *pt = m_vpPoints->at(i);
      pt->m_Pos.x = (x_spacement*i) + m_Pos0x0.x;

      int row = i/8;
      int col = i%8;
      pt->m_Pos.y = -DCTVIEWER->getSignals()->at(row)->at(col) + m_Pos0x0.y;
      pt->m_Pos.x = x;
   }
}

void Graph::insertPoints()
{
   unsigned int signalsSize = DCTVIEWER->getSignals()->size()*8;
   unsigned int pointsSize = m_vpPoints->size();
   if(signalsSize > pointsSize)
   {
      double x_spacement = (double)m_XLength/signalsSize;
      unsigned int size = DCTVIEWER->getSignals()->size();

      adjustPoints();
      
      std::vector<GraphPoint *> *points = new std::vector<GraphPoint *>();
      for(unsigned int i = size-1; i < size; i++)
      {
         std::vector<double> *v = DCTVIEWER->getSignals()->at(i);
         for(unsigned int j = 0; j < v->size(); j++)
         {
            double x = (x_spacement*((i*8)+j)) + m_Pos0x0.x; //pega a posicao do sinal na matriz.
            double y = -v->at(j) + m_Pos0x0.y;
            GraphPoint *pt = new GraphPoint(scv::Point(x, y));
            points->push_back(pt);
         }
      }
      addPoints(*points);
   }
}

void Graph::drawAxis()
{
   glBegin(GL_LINES);
      //draw coordinate x
      glColor4f(0.f, 0.f, 0.f, 1.f);
      glVertex2d(m_Pos0x0.x, m_Pos0x0.y);
      glVertex2d(m_Pos0x0.x + m_XLength, m_Pos0x0.y);
      
      //draw x arrow
      glVertex2d(m_Pos0x0.x + m_XLength - 10, m_Pos0x0.y - 5);
      glVertex2d(m_Pos0x0.x + m_XLength, m_Pos0x0.y);

      glVertex2d(m_Pos0x0.x + m_XLength - 10, m_Pos0x0.y + 5);
      glVertex2d(m_Pos0x0.x + m_XLength, m_Pos0x0.y);


      //draw coordinate y
      glVertex2d(m_Pos0x0.x, m_Pos0x0.y);
      glVertex2d(m_Pos0x0.x, m_Pos0x0.y - m_YLength);

      //draw y arrow
      glVertex2d(m_Pos0x0.x - 5, m_Pos0x0.y - m_YLength + 10);
      glVertex2d(m_Pos0x0.x, m_Pos0x0.y - m_YLength);
      
      glVertex2d(m_Pos0x0.x + 5, m_Pos0x0.y - m_YLength + 10);
      glVertex2d(m_Pos0x0.x, m_Pos0x0.y - m_YLength);


   glEnd();
}

void Graph::drawPoints()
{
   //para o caso de ter apenas 1 ponto...
   unsigned int size = m_vpPoints->size();
   if(size < 2)
   {
      if(size > 0)
         m_vpPoints->at(0)->draw();
      return;
   }

   for(unsigned int i = 0; i < size - 1; i++)
   {
      scv::Point p1 = m_vpPoints->at(i)->m_Pos;
      scv::Point p2 = m_vpPoints->at(i+1)->m_Pos;

      //desenha uma linha entre dois pontos.
      glBegin(GL_LINES);
         glColor4f(1.f, 0.f, 0.f, 1.f);
         glVertex2i(p1.x, p1.y);
         glVertex2i(p2.x, p2.y);
      glEnd();

      m_vpPoints->at(i)->draw();
   }
   m_vpPoints->at(size-1)->draw();
}

void Graph::draw()
{
   insertPoints();
   drawAxis();
   drawPoints();
}

void Graph::cleanPoints()
{
   for(unsigned int i = 0; i < m_vpPoints->size(); i++)
      delete m_vpPoints->at(i);
}
