#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"

int main() {

  /* REQ-BL-1051
   * The floor and floorf procedures shall return NaN, if the argument x is NaN.
   */

  float x = NAN;
  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

  	float res = floor_float(x);

    // x is NAN the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
