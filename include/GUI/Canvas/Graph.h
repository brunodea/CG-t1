/*
 * Classe que representa um gr�fico. � usado para desenhar os gr�ficos da amostra original, ap�s a FDCT e
 * ap�s a IDCT.
 */
#ifndef _BRUNODEA_CG_T1_GRAPH_H_
#define _BRUNODEA_CG_T1_GRAPH_H_

#include <SCV/Canvas.h>
#include <SCV/Point.h>
#include <vector>
#include <string>
#include "GUI/Canvas/GraphPoint.hpp"

namespace GUI
{
   class Graph
   {
   public:
      /* 
       * Construtor.
       * signals: vetor de sinais que v�o ser desenhados pelo gr�fico.
       * name: nome (t�tulo) do gr�fico.
       * p0x0: posi��o na tela de onde vai ficar o ponto 0x0 do gr�fico.
       * xLength: tamanho em pixels do eixo x.
       * yLength: tamanho em pixels do eixo y.
       */
      Graph(std::vector<std::vector<double> *> *signals, const std::string &name, 
            const scv::Point &p0x0, unsigned int xLenght, unsigned int yLength);
      ~Graph();

      /* 
       * Adiciona pontos para o gr�fico.
       * points: pontos a serem adiciondos.
       */
      void addPoints(const std::vector<GraphPoint *> &points);

      /* 
       * Ajusta o valor x e y de um ponto no gr�fico.
       * row: qual linha no vetor de sinais est� o valor para o ponto ser ajustado.
       * col: qual coluna no vetor de sinais est� o valor para o ponto ser ajustado.
       */
      void adjustPoint(unsigned int row, unsigned int col);

      /* Ajusta todos os pontos de acordo com o vetor de sinais. */
      void adjustPoints();

      /* Desenha o gr�fico. */
      void draw();

      /* Seta determinado ponto para 0 e ajusta no vetor de sinais. */
      void goToZero(GraphPoint *gp);

      /* 
       * Pega um ponto que esteja na posi��o 'index' do vetor de pontos. 
       * index: �ndice do ponto.
       * retorna NULL caso n�o exista.
       */
      GraphPoint *getPointAt(unsigned int index);

      /*
       * Pega um ponto que esteja na posi��o 'pt' e retorna seu �ndice.
       * pt: posi��o na canvas onde est� o ponto.
       * retorna -1 caso n�o tenha nenhum ponto na posi��o 'pt'.
       */
      int getPointAt(const scv::Point &pt);


      /* Setters & Getters */
      void setScale(const double &scale);
      inline double &getScale() { return m_Scale; }

      inline void setSignals(std::vector<std::vector<double> *> *signals) { m_vvpSignals = signals; }

   public:
      scv::Point m_Pos0x0; //posi��o 0x0 do gr�fico na canvas.
      double m_XLength; //tamanho do eixo x.
      double m_YLength; //tamanho do eixo y.

   private:
      std::vector<GraphPoint *> *m_vpPoints; //vetor de pontos do gr�fico.
      std::vector<std::vector<double> *> *m_vvpSignals; //sinais que vao ser mostrados no grafico.
      double m_Scale; //escala atual.
      std::string m_Name; //nome do gr�fico.

   private:
      void drawAxis();  //desenha os eixos.
      void drawPoints(); //desenha os pontos.
      
      void insertPoints(); //adiciona os pontos no gr�fico que estejam faltando com rela��o ao vetor de sinais.
      void clearPoints(); //deleta os pontos.

   }; //end of class Graph.

} //end of namespace GUI.

#endif
