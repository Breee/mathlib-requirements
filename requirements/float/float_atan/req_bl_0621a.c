#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan.h"

int main() {

  /*
   * REQ-BL-0621:
   * The atan and atanf procedures shall return +-pi/2 if the argument is +-Inf.
   */

   float x = INFINITY;

   if (isinf_float(x)) {

     __VERIFIER_precond_reach();

     float res = atan_float(x);

     // if x is +-inf the result shall be +-pi/2
     if (res != (float)M_PI_2) {
       __VERIFIER_error();
    	 return 1;
     }
 	 }

 	return 0;
}
