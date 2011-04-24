/*
 * Arquivo com uma função do openGL para desenhar um texto. Copiada 
 * da API Canvas2D, feita pelo professor Pozzer.
 */

#ifndef _BRUNODEA_CG_T1_FUNCTIONS_H_
#define _BRUNODEA_CG_T1_FUNCTIONS_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>
#include <string>


/* Desenha uma string 'text' na canvas na posição 'p'. */
inline void drawText(std::string text, const scv::Point &p)
{
   //draw the name of the graph.    
   for(unsigned int i = 0; i < text.length(); i++)
   {
      glRasterPos2i(p.x + (i*10), p.y + 15);
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text.c_str()[i]);
   }
}




#endif
