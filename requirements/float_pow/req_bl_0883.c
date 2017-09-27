#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include "float_pow.h"

int main() {

  /*
   * REQ-BL-0883//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +Inf , if the argument x is +Inf and the argument y > 0.
   */

	float x = INFINITY;
  float y = __VERIFIER_nondet_float();

  if(isinf_float(x) && y > 0){

    __VERIFIER_precond_reach();

    float res = __ieee754_powf(x, y);

    // result shall be +inf
    if(isinf_float(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
