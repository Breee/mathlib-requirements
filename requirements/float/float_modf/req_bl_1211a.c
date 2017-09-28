#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_modf.h"

int main() {

  /* REQ-BL-1211
   * The modf and modff procedures shall return ±0 and set the argument ∗iptr to +-Inf , if the argument x is +-Inf .
   */

  float x = INFINITY;
  float iptr = __VERIFIER_nondet_float();

  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = modf_float(x, &iptr);
    // x is inf, *iptr is inf, result shall be -+0
  	if (isinf_float(x) && isinf_float(iptr) && res != +0.0f) {
  		__VERIFIER_error();
  		return 1;
  	}
	}


	return 0;
}
