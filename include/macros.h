/*
 * Macros usados ao longo do programa.
 */

#ifndef _BRUNODEA__CG_T1_MACROS_H_
#define _BRUNODEA__CG_T1_MACROS_H_

#define MY_PI 3.14159265 //pi

#define WINDOW_WIDTH 1024 //Dimensão da janela.
#define WINDOW_HEIGHT 600

#define MASTER_VALUE 8 //valor mestre em que as contas vão ser baseadas.

#define SAMPLE_SPINNER_MAX_VALUE 255 //Valores default para os Spinners da amostra original.
#define SAMPLE_SPINNER_MIN_VALUE 0
#define SAMPLE_SPINNER_WIDTH 50

#define BOTTOM_SIDEBAR_HEIGHT (WINDOW_HEIGHT / 5) //altura da sidebar inferior.

#define DCTVIEWER brunodea::DCTViewer::instance()

#define GRAPH_POINT_WIDTH 6 //tamanho do retângulo que representa um ponto no gráfico.
#define GRAPH_POINT_HEIGHT GRAPH_POINT_WIDTH

#endif