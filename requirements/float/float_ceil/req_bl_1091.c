#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_ceil.h"

int main() {


  /*
   * REQ-BL-1091:
   * The ceil and ceilf procedures shall return NaN , if the argument x is NaN.
   */

  float x = __VERIFIER_nondet_float();

  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

  	float res = ceil_float(x);

    // x is NAN, result shall be NAN
  	if (isnan_float(x) && !isnan_float(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
