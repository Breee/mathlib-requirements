#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_acos.h"

int main()
{

  /* REQ-BL-0460:
   * The acos and acosf procedures shall return NaN , if the argument x is not in the range [-1,1].
   */

  double x = __VERIFIER_nondet_double();

  if (x < -1.0 || x > 1.0) {
    __VERIFIER_precond_reach();

  	double res = __ieee754_acos(x);

    // x is not in [-1,1] the result shall be NAN
  	if (!isnan_double(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
