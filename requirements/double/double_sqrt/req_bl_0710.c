#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_sqrt.h"


int main() {

  /*
   * REQ-BL-0710:
   * The sqrt and sqrtf procedures shall return NaN, if the argument x < -0.
   */

  double x = __VERIFIER_nondet_double();

  if (x < -0.0) {
    __VERIFIER_precond_reach();

  	double res = __ieee754_sqrt(x);

    // x is -0 , the result shall be NAN
  	if (!isnan_double(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
