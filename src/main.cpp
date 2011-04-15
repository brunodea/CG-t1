#include <iostream>
#include <vector>
#include <cstdlib>

#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/Label.h>


#include "../include/GUI/Sidebar/BottomSidebar.h"
#include "../include/DCT/dct.hpp"
#include "../include/macros.h"

#include <iostream>

void dct_test()
{
   DCT::SignalVec s;
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
   DCT::SignalVec res = DCT::fdct(s);

   for(unsigned int i = 0; i < res.size(); i++)
      std::cout << res[i] << " ";
   std::cout << std::endl;

   DCT::SignalVec res_i = DCT::idct(res);

   for(unsigned int i = 0; i < res_i.size(); i++)
      std::cout << res_i[i] << " ";
   std::cout << std::endl;

   system("pause");
}

int main(int argc, char *argv[])
{
   scv::Kernel *kernel = scv::Kernel::getInstance();
   scv::ColorScheme *color_scheme = scv::ColorScheme::getInstance();

   color_scheme->loadScheme(scv::ColorScheme::clean);
   kernel->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

   GUI::BottomSidebar bottom_sidebar(0, WINDOW_HEIGHT - (WINDOW_HEIGHT / 6));
      
   kernel->addComponent(&bottom_sidebar);
   
   kernel->setFramesPerSecond(60);
   kernel->run();

	return 0;
}