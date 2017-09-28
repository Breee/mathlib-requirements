#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_asin.h"

int main() {

  /*
   * REQ-BL-0260:
   * The asin and asinf procedures shall return NAN, if the argument x is NAN
   */

  float x = NAN;

  if (isnan_float(x)) {

    __VERIFIER_precond_reach();

  	float res = __ieee754_asinf(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
