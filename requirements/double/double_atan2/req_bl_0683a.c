#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"

int main()
{

  /*
   * REQ-BL-0683//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The atan2 and atan2f procedures shall return ±0 ,
   * if the argument ± y is finite and not 0, and the argument x is +Inf .
   */

   double x = 1.0/0.0; // INF
   double y = __VERIFIER_nondet_double();

   if (isinf_double(x) && isfinite_double(y) && y < 0.0) {
     __VERIFIER_precond_reach();

     double res = __ieee754_atan2(y, x);

    // x is -inf, y < 0.0 and y != -inf, the result shall be -0.0
     if (!(res == -0.0 && __signbit_double(res) == 1)) {
       __VERIFIER_error();
       return 1;
     }

 	}

 	return 0;
}
