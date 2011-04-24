/*
 * Bruno Romero de Azevedo.
 * Matrícula: 2910098.
 */

#include <iostream>
#include <vector>
#include <cstdlib>

#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/Label.h>


#include "GUI/Sidebar/BottomSidebar.h"
#include "DCTViewer.h"
#include "macros.h"

#include <iostream>

void print_help()
{
    std::cout << "+-------------------------------------------+\n";
    std::cout << "|                DCT Viewer                 |\n";
    std::cout << "+---------------por Bruno Romero de Azevedo-+\n\n";
    
    std::cout << "                Pequeno Help\n";
    std::cout << "---------------------------------------------\n";
    
    std::cout << ">Para alterar o tamanho da amostra que vai ser passada para a fdct/idct:\n";
    std::cout << "\tAlterar o valor do spinner abaixo da label 'Sample'.\n";
    
    std::cout << ">Spinners dentro da scroll panel ao centro da sidebar inferior:\n";
    std::cout << "\tSao os valores da amostra original.\n";
    
    std::cout << ">Para truncar valores da fdct:\n";
    std::cout << "\tBasta clicar com o botao do meio do mouse em cima do ponto no grafico\n";
    std::cout << "\tque ele vai para zero.\n";
    
    std::cout << ">Para ajustar a escala:\n";
    std::cout << "\tBasta apertar no teclado (com a canvas dos graficos selecionada)\n";
    std::cout << "\t'+' ou '-'.\n";
    std::cout << "\tOu entao, scrollar a rodinha do mouse.\n";
    
    std::cout << "---------------------------------------------\n";
}

void dct_test()
{
   /*
   std::vector<double> s;
   s.push_back(8);
   s.push_back(16);
   s.push_back(24);
   s.push_back(32);
   s.push_back(40);
   s.push_back(48);
   s.push_back(56);
   s.push_back(64);

   for(unsigned int i = 0; i < s.size(); i++)
      std::cout << s.at(i) << " ";
   std::cout << std::endl;
   std::vector<double> res = DCTViewer::fdct(s);

   for(unsigned int i = 0; i < res.size(); i++)
      std::cout << res[i] << " ";
   std::cout << std::endl;

   std::vector<double> res_i = DCTViewer::idct(res);

   for(unsigned int i = 0; i < res_i.size(); i++)
      std::cout << res_i[i] << " ";
   std::cout << std::endl;

   system("pause");
   */
}

int main(int argc, char *argv[])
{
   scv::Kernel *kernel = scv::Kernel::getInstance();
   scv::ColorScheme *color_scheme = scv::ColorScheme::getInstance();

   color_scheme->loadScheme(scv::ColorScheme::clean);
   kernel->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
   kernel->lockWindowSize(true);
   kernel->setWindowTitle("DCT Viewer by Bruno Romero de Azevedo.");
   
   print_help();
   brunodea::DCTViewer::instance(); //para inicializar o dctviewer.

   kernel->setFramesPerSecond(60);
   kernel->run();

   delete brunodea::DCTViewer::instance();

	return 0;
}