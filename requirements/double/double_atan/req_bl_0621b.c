#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan.h"

int main() {

  /* REQ-BL-0621:
   * The atan and atanf procedures shall return +-pi/2 if the argument is +-Inf.
   */

   double x = -1.0/0.0; // -INF
   __VERIFIER_precond_reach();
   
   double res = atan_double(x);
   // x is -inf the result shall be -pi/2
   if (res != -pi_o_2) {
       __VERIFIER_error();
    	 return 1;
   }

 	return 0;
}
