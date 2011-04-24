/*
 * Classe que representa um gráfico. É usado para desenhar os gráficos da amostra original, após a FDCT e
 * após a IDCT.
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
       * signals: vetor de sinais que vão ser desenhados pelo gráfico.
       * name: nome (título) do gráfico.
       * p0x0: posição na tela de onde vai ficar o ponto 0x0 do gráfico.
       * xLength: tamanho em pixels do eixo x.
       * yLength: tamanho em pixels do eixo y.
       */
      Graph(std::vector<std::vector<double> *> *signals, const std::string &name, 
            const scv::Point &p0x0, unsigned int xLenght, unsigned int yLength);
      ~Graph();

      /* 
       * Adiciona pontos para o gráfico.
       * points: pontos a serem adiciondos.
       */
      void addPoints(const std::vector<GraphPoint *> &points);

      /* 
       * Ajusta o valor x e y de um ponto no gráfico.
       * row: qual linha no vetor de sinais está o valor para o ponto ser ajustado.
       * col: qual coluna no vetor de sinais está o valor para o ponto ser ajustado.
       */
      void adjustPoint(unsigned int row, unsigned int col);

      /* Ajusta todos os pontos de acordo com o vetor de sinais. */
      void adjustPoints();

      /* Desenha o gráfico. */
      void draw();

      /* Seta determinado ponto para 0 e ajusta no vetor de sinais. */
      void goToZero(GraphPoint *gp);

      /* 
       * Pega um ponto que esteja na posição 'index' do vetor de pontos. 
       * index: índice do ponto.
       * retorna NULL caso não exista.
       */
      GraphPoint *getPointAt(unsigned int index);

      /*
       * Pega um ponto que esteja na posição 'pt' e retorna seu índice.
       * pt: posição na canvas onde está o ponto.
       * retorna -1 caso não tenha nenhum ponto na posição 'pt'.
       */
      int getPointAt(const scv::Point &pt);


      /* Setters & Getters */
      void setScale(const double &scale);
      inline double &getScale() { return m_Scale; }

      inline void setSignals(std::vector<std::vector<double> *> *signals) { m_vvpSignals = signals; }

   public:
      scv::Point m_Pos0x0; //posição 0x0 do gráfico na canvas.
      double m_XLength; //tamanho do eixo x.
      double m_YLength; //tamanho do eixo y.

   private:
      std::vector<GraphPoint *> *m_vpPoints; //vetor de pontos do gráfico.
      std::vector<std::vector<double> *> *m_vvpSignals; //sinais que vao ser mostrados no grafico.
      double m_Scale; //escala atual.
      std::string m_Name; //nome do gráfico.

   private:
      void drawAxis();  //desenha os eixos.
      void drawPoints(); //desenha os pontos.
      
      void insertPoints(); //adiciona os pontos no gráfico que estejam faltando com relação ao vetor de sinais.
      void clearPoints(); //deleta os pontos.

   }; //end of class Graph.

} //end of namespace GUI.

#endif
