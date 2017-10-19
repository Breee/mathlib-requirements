#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fmax.h"

int main()
{

  /* REQ-BL-1240:
  * The fmax and fmaxf procedures shall determine the
  * maximum numeric value of the argument x and y.
  */

  float x = __VERIFIER_nondet_float();
	float y = __VERIFIER_nondet_float();

  // continue if x or y is not nan, both not nan, x and y not +-0 at the same time.
  // this IF-statement excludes the cases of the other requirements.
  float res = fmax_float(x, y);

	return 0;
}
