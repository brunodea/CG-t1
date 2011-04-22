#ifndef _BRUNODEA_CG_T1_GRAPH_POINT_H_
#define _BRUNODEA_CG_T1_GRAPH_POINT_H_

#include <SCV/Point.h>
#include <SCV/Color4f.h>
#include <SCV/Canvas.h>

#include "macros.h"

#include <string>
#include <iostream>

namespace GUI
{
   class GraphPoint
   {
   public:
      GraphPoint(const scv::Point &p)
         : m_Pos(p), m_Color(0.f, 0.5f, 0.f), m_iHalfWidth(GRAPH_POINT_WIDTH/2), 
           m_iHalfHeight(GRAPH_POINT_HEIGHT/2)           
      {}

      GraphPoint(const scv::Point &p, const scv::Color4f &c)
         : m_Pos(p), m_Color(c), m_iHalfWidth(GRAPH_POINT_WIDTH/2), 
           m_iHalfHeight(GRAPH_POINT_HEIGHT/2)
      {}

      void draw()
      {
         glBegin(GL_QUADS);
            glColor4f(m_Color[0], m_Color[1], m_Color[2], m_Color[3]);
            glVertex2i(m_Pos.x - m_iHalfWidth, m_Pos.y - m_iHalfHeight);
            glVertex2i(m_Pos.x - m_iHalfWidth, m_Pos.y + m_iHalfHeight);
            glVertex2i(m_Pos.x + m_iHalfWidth, m_Pos.y - m_iHalfHeight);
            glVertex2i(m_Pos.x + m_iHalfWidth, m_Pos.y + m_iHalfHeight);
         glEnd();
      }
   public:
      scv::Point m_Pos;

   private:
      scv::Color4f m_Color;

      int m_iHalfWidth;
      int m_iHalfHeight;
   }; //end of class GraphPoint.
} //end of namespace GUI.

#endif
