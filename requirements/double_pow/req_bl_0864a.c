#include "../includes/verify.h"
#include "../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0864//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return:
   *   +-Inf respectively if y is an odd integer, or
   *   +Inf if y is not an odd integer.
   * If the argument y is < 0 and x is 0.
   */

	double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  // x = -0, y odd negative integer.
  if(x == -0.0 && y < 0.0 && (fmod_double(y,2.0) == 1.0) && isinteger_double(y)){

    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x,y);

    // result shall be -Inf
    if(!isinf_double(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
