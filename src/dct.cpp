#include "../include/dct.h"
#include "../include/macros.h"

#include <cmath>

/*
 * Forward Discrete Cosine Transform
 */
SignalVec &fdct(const SignalVec &sample)
{
	std::vector<double> *result = new SignalVec();

	unsigned int n = sample.size();
   double f_u;
   double c_u;
   for(unsigned int u = 0; u < n; u++)
   {
      if(u == 0)
         c_u = (double) 1/sqrt(2.0);
      else
         c_u = 1;

      f_u = 0;
      for(unsigned int x = 0; x < n; x++)
         f_u += sample[x]*cos((double) ((2*x) + 1)*u*MY_PI/(2*n));
      f_u *= 0.5*c_u;
      result->push_back(f_u);
   }

	return *result;
}

SignalVec &idct(const SignalVec &signal)
{
    SignalVec *original = new SignalVec();
    
    int n = signal.size();
    double c_j;
    double pt;
    for(int t = 0; t < n; t++)
    {
        pt = 0;
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
                c_j = (double) 1/sqrt(2.0);
            else
                c_j = 1;
            pt += c_j*signal[j]*cos((double) (2*t + 1)*j*MY_PI/(2*n));
        }
        pt *= 0.5;
        original->push_back(pt);
    }

    return *original;
}
