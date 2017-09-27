#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0875//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +0 , if |x| > 1 and the argument y is -Inf .
   */

	float x = __VERIFIER_nondet_float();
  float y = -INFINITY;

  if(fabs_float(x) > 1 && isinf_float(y)){

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x, y);

    // result shall be +0
    if(res != 0.0f){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
