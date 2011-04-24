#ifndef _BRUNODEA_DCTVIEWER_H_
#define _BRUNODEA_DCTVIEWER_H_

#include <SCV/ScrollPane.h>
#include <SCV/Panel.h>

/*
 * Classe que representa a aplicação em si.
 * É um singleton.
 */
#include <vector>
#include "GUI/Sidebar/BottomSidebar.h"
#include "GUI/Canvas/GraphsCanvas.h"

namespace brunodea
{
   class DCTViewer
   {
   public:
      /* Pega a única instância da classe. */
      static DCTViewer *instance();
      ~DCTViewer();

      /* Getters. */
      inline GUI::BottomSidebar *getBottomSidebar() { return m_pBottomSidebar; }
      inline GUI::GraphsCanvas *getGraphsCanvas() { return m_pGraphsCanvas; }
      inline std::vector<std::vector<double> *> *getSignals() { return m_pSignals; }
      std::vector<std::vector<double> *> *getFDCTSignals();
      std::vector<std::vector<double> *> *getIDCTSignals();

      /* Ajusta os sinais da FDCT e IDCT. */
      void adjustFDCTSignals();
      void adjustIDCTSignals();

      /* Ajusta o panel da canvas (para o caso da escala ter mudado). */
      void adjustCanvasPanel();

      /* 
       * Adiciona um vetor de sinais para a amostra original.
       * sv: vetor de sinais.
       */
      void addSignalVec(std::vector<double> *sv);
      /* Adiciona um vetor de sinais para a amostra original com valor default. */
      void addSignalVec();
      
      /* Função que aplica a fdct em uma amostra. */
      static std::vector<double> &fdct(std::vector<double> &sample);
      /* Função que aplica a idct em uma amostra. */
      static std::vector<double> &idct(std::vector<double> &signal);

      /* Seta o tamanho do vetor que vai ser passado para as funções da fdct e idct. */
      void setSizeSample(const unsigned int &size);

   private:
      static DCTViewer *m_sInstance; //instancia da classe singleton.

      GUI::BottomSidebar *m_pBottomSidebar; //sidebar inferior.
      GUI::GraphsCanvas *m_pGraphsCanvas; //canvas onde ficam os gráficos.

      /* Vetores com os sinais. */
      std::vector<std::vector<double> *> *m_pSignals;
      std::vector<std::vector<double> *> *m_pFDCTSignals;
      std::vector<std::vector<double> *> *m_pIDCTSignals;

      scv::ScrollPane *m_pCanvasScrollPane; //scroll pane onde fica a canvas.
      scv::Panel *m_pCanvasPanel; //panel onde fica a canvas.

      int m_iSampleSize; //fator de multiplicidade do MASTER_VALUE que vai determinar o tamanho da amostrada passada pra fdct e idct.

   private:
      DCTViewer(); //Construtor.
      void initSignals();

   }; //end of class DCTViewer.
} //end of namespace brunodea.
#endif
