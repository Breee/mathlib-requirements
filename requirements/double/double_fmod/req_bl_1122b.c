#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmod.h"

int main()
{

  /* REQ-BL-1121:
  * The fmod and fmodf procedures shall return NaN , if the argument x is +-Inf.
  */

  double x = -1.0/0.0; // -INF
  double y = __VERIFIER_nondet_double();
  __VERIFIER_precond_reach();
  double res = fmod_double(x, y);

  // y is any value, x is -inf, the result shall be NAN
  if (!isnan_double(res))	{
    __VERIFIER_error();
    return 1;
  }

	return 0;
}
