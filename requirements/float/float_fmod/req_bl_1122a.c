#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fmod.h"

int main()
{

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN , if the argument x is +-Inf.
  */

  float x = INFINITY;
  float y = __VERIFIER_nondet_float();

  if (isinf_float(x)) {
    __VERIFIER_precond_reach();

    float res = fmod_float(x, y);

    // y is any value, x is +inf, the result shall be NAN
    if (!isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    };
	}

	return 0;
}
