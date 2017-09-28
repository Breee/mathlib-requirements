#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan.h"

int main() {

  /* REQ-BL-0621:
   * The atan and atanf procedures shall return +-pi/2 if the argument is +-Inf.
   */

   float x = -INFINITY;

   // x is not +-inf we don't want to continue
   if (isinf_float(x)) {

     __VERIFIER_precond_reach();

     float res = atan_float(x);
     // x is +-inf the result shall be +-pi/2
     if (res != (float)(-M_PI_2)) {
       __VERIFIER_error();
    	 return 1;
     }
 	 }

 	return 0;
}
