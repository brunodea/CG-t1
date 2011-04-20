#include <iostream>
#include <vector>
#include <cstdlib>

#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/Label.h>


#include "GUI/Sidebar/BottomSidebar.h"
#include "DCT/dct.hpp"
#include "macros.h"

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
   kernel->lockWindowSize(true);

   kernel->addComponent(GUI::BottomSidebar::instance());
   
   kernel->setFramesPerSecond(60);
   kernel->run();

   delete GUI::BottomSidebar::instance();

	return 0;
}