#include "../includes/verify.h"
#include "../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0885//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +-0 respectively,
   * if the argument x is +-0 and the argument y is an odd integer > 0.
   */

	double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  // x = -0, y > 0, odd integer.
  if(x == -0.0 && y > 0.0 && (fmod_double(y,2.0) == 1.0) && isinteger_double(y)){

    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x,y);

    // result shall be -0
    if(res != -0.0){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
