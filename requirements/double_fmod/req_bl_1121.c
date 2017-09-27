#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

int main()
{

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN, if the argument y is 0.
  */

  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  if (y == 0.0 || y == -0.0) {

    __VERIFIER_precond_reach();

  	double res = fmod_double(x, y);

    // x is any value, y is +-0, the result shall be NAN
  	if (!isnan_double(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
