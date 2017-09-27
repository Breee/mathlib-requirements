#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

int main()
{

  /* REQ-BL-1131:
   * The fmod and fmodf procedures shall return the argument x,
   * if the argument x is not ±Inf and the argument y is ±Inf
   */

  float y = __VERIFIER_nondet_float();
  float x = __VERIFIER_nondet_float();

  if (isfinite_float(x) && isinf_float(y)) {

    __VERIFIER_precond_reach();

    float res = fmod_float(x, y);

    // x is not +-inf, y is +-inf, result shall be x
    if (!isinf_float(x) && isinf_float(y) && res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
