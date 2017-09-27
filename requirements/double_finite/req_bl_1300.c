#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

int main()
{

  /* REQ-BL-1300
   * The isfinite procedure shall return a non-zero value if the argument x has a finite value
   * and is neither NaN nor +-Inf .
   */

  double x = __VERIFIER_nondet_double();

  // x is inf, or nan we don't want to continue
  if (isfinite_double(x) && !isnan_double(x)) {
    __VERIFIER_precond_reach();

  	double res = isfinite_double(x);

    // x is not inf, is not nan, the result shall be not 0.
  	if (res == 0) {
  		__VERIFIER_error();
  		return 1;
  	}
	}


	return 0;
}
