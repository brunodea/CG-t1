#ifndef _CG_T1_FUNCTIONS_H_
#define _CG_T1_FUNCTIONS_H_

#include <vector>

typedef std::vector<double> Signal;

namespace DCT
{
   Signal fdct(const Signal &signal);
   Signal &idct(const Signal &signal);

} //end of namespace DCT.

#endif