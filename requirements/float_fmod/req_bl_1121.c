#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

int main()
{

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN, if the argument y is 0.
  */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  if (y == +0.0f || y == -0.0f) {

    __VERIFIER_precond_reach();

  	float res = fmod_float(x, y);

    // x is any value, y is +-0, the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
