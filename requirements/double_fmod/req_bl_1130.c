#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

int main()
{

  /* REQ-BL-1130:
  * The fmod and fmodf procedures shall return x ,
  * if the argument x is +-0 and the argument y is not zero.
  */

  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  if ((x == -0.0 || x == 0.0) && (y < 0.0 || y > 0.0)) {
    __VERIFIER_precond_reach();

    double res = fmod_double(x, y);

    // x is -+0, y is not 0, result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
