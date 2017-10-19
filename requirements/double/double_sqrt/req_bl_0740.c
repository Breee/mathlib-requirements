#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_sqrt.h"


int main() {

  /*
   * REQ-BL-0740:
   * The sqrt and sqrtf procedures shall return NaN, if the argument x is -Inf.
   */

   double x = -1.0/0.0; // -INF
   __VERIFIER_precond_reach();
   double res = __ieee754_sqrt(x);

   // x -inf, the result shall be NAN
   if (!isnan_double(res))	{
     __VERIFIER_error();
     return 1;
   }

	return 0;
}
