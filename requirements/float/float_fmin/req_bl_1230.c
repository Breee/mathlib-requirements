#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fmin.h"

int main()
{

  /*
   * REQ-BL-1230:
   * The fmax and fmaxf procedures shall return NaN,
   * if the arguments x and y are NaN.
   */

  float x = NAN;
  float y = NAN;

	if (isnan_float(x) && isnan_float(y)) {
    __VERIFIER_precond_reach();

    float res = fmin_float(x, y);

    if (!isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
