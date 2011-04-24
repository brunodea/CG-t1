/*
 * Classe que representa um ponto no gráfico.
 */

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
      /*
       * Construtor.
       * p: posição na canvas em que o ponto vai ficar.
       */
      GraphPoint(const scv::Point &p)
         : m_Pos(p), m_Color(0.f, 0.5f, 0.f), m_iHalfWidth(GRAPH_POINT_WIDTH/2), 
           m_iHalfHeight(GRAPH_POINT_HEIGHT/2)           
      {}

      /*
       * Construtor.
       * p: posição na canvas em que o ponto vai ficar.
       * c: sua cor.
       */
      GraphPoint(const scv::Point &p, const scv::Color4f &c)
         : m_Pos(p), m_Color(c), m_iHalfWidth(GRAPH_POINT_WIDTH/2), 
           m_iHalfHeight(GRAPH_POINT_HEIGHT/2)
      {}

      /*
       * Desenha o ponto (na verdade desenha um retângulo representando o ponto).
       */
      inline void draw()
      {
         glBegin(GL_QUADS);
            glColor4f(m_Color[0], m_Color[1], m_Color[2], m_Color[3]);
            glVertex2i(m_Pos.x - m_iHalfWidth, m_Pos.y - m_iHalfHeight);
            glVertex2i(m_Pos.x - m_iHalfWidth, m_Pos.y + m_iHalfHeight);
            glVertex2i(m_Pos.x + m_iHalfWidth, m_Pos.y - m_iHalfHeight);
            glVertex2i(m_Pos.x + m_iHalfWidth, m_Pos.y + m_iHalfHeight);
         glEnd();
      }

      /*
       * Verifica se a posição 'pt' está dentro do (retângulo que representa o) ponto.
       * pt: posição que se quer fazer a verificação.
       */
      inline bool isInside(const scv::Point &pt)
      {
         if(pt.x >= m_Pos.x - m_iHalfWidth && pt.x <= m_Pos.x + m_iHalfWidth &&
            pt.y >= m_Pos.y - m_iHalfHeight && pt.y <= m_Pos.y + m_iHalfHeight)
            return true;
         return false;
      }

   public:
      scv::Point m_Pos; //posição do ponto na canvas.

   private:
      scv::Color4f m_Color; //cor do ponto.

      /* 
       * É a metade para não ter que ficar fazendo a divisão por 2 o tempo todo.
       * E é assim para que a posição m_Pos sempre fique no meio do retângulo.
       */
      int m_iHalfWidth; //metade da largura do retângulo que representa o ponto.
      int m_iHalfHeight; //metade da altura do retângulo que representa o ponto.

   }; //end of class GraphPoint.
} //end of namespace GUI.

#endif
