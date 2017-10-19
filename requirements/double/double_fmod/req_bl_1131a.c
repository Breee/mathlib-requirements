#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmod.h"


int main()
{

  /* REQ-BL-1131:
   * The fmod and fmodf procedures shall return the argument x,
   * if the argument x is not ±Inf and the argument y is ±Inf
   */

  double y = 1.0/0.0; //INF
  double x = __VERIFIER_nondet_double();

  if (isfinite_double(x)) {

    __VERIFIER_precond_reach();

    double res = fmod_double(x, y);

    // x is not +-inf, y is +inf, result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
