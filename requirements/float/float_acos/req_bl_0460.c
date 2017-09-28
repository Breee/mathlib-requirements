#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_acos.h"

int main()
{

  /* REQ-BL-0460:
   * The acos and acosf procedures shall return NaN , if the argument x is not in the range [-1,1].
   */

  float x = __VERIFIER_nondet_float();

  if (x < -1.0f || x > 1.0f) {
    __VERIFIER_precond_reach();

  	float res = __ieee754_acosf(x);

    // x is not in [-1,1] the result shall be NAN
  	if (!isnan_float(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
