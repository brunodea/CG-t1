#include <iostream>
#include <vector>
#include <cstdlib>

#include "../include/dct.hpp"

int main(int argc, char *argv[])
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

	return 0;
}