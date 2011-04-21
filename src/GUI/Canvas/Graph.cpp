#include "GUI/Canvas/Graph.h"

using namespace GUI;

Graph::Graph(const scv::Point &p0x0, unsigned int xLength, unsigned int yLength)
   : m_Pos0x0(p0x0), m_XLength(xLength), m_YLength(yLength)
{
   m_vpPoints = new std::vector<GraphPoint *>();
}

Graph::~Graph()
{
   for(unsigned int i = 0; i < m_vpPoints->size(); i++)
      delete m_vpPoints->at(i);
   delete []m_vpPoints;
}

void Graph::addPoints(const std::vector<GraphPoint *> &points)
{
   m_vpPoints->insert(m_vpPoints->end(), points.begin(), points.end());
}

void Graph::drawCoordinates()
{
   glBegin(GL_LINES);
      //draw coordinate x
      glColor4f(0.f, 0.f, 0.f, 1.f);
      glVertex2i(m_Pos0x0.x, m_Pos0x0.y);
      glVertex2i(m_Pos0x0.x + m_XLength, m_Pos0x0.y);

      //draw x arrow
      glVertex2i(m_Pos0x0.x + m_XLength - 10, m_Pos0x0.y - 5);
      glVertex2i(m_Pos0x0.x + m_XLength, m_Pos0x0.y);

      glVertex2i(m_Pos0x0.x + m_XLength - 10, m_Pos0x0.y + 5);
      glVertex2i(m_Pos0x0.x + m_XLength, m_Pos0x0.y);


      //draw coordinate y
      glVertex2i(m_Pos0x0.x, m_Pos0x0.y);
      glVertex2i(m_Pos0x0.x, m_Pos0x0.y - m_YLength);

      //draw y arrow
      glVertex2i(m_Pos0x0.x - 5, m_Pos0x0.y - m_YLength + 10);
      glVertex2i(m_Pos0x0.x, m_Pos0x0.y - m_YLength);
      
      glVertex2i(m_Pos0x0.x + 5, m_Pos0x0.y - m_YLength + 10);
      glVertex2i(m_Pos0x0.x, m_Pos0x0.y - m_YLength);


   glEnd();
}

void Graph::draw()
{
   drawCoordinates();

}

