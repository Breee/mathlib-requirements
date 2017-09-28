#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fmod.h"

int main()
{

  /* REQ-BL-1130:
  * The fmod and fmodf procedures shall return x ,
  * if the argument x is +-0 and the argument y is not zero.
  */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  if ((x == -0.0f || x == +0.0f) && (y < 0.0f || y > 0.0f)) {
    __VERIFIER_precond_reach();

    float res = fmod_float(x, y);

    // x is -+0, y is not 0, result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
