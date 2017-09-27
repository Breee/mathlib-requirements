#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

int main() {

  /*
   * REQ-BL-0720:
   * The sqrt and sqrtf procedures shall return NaN if the argument x is NaN .
   */

  float x = NAN;
  // if x is not NAN, we dont want to continue
  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_sqrtf(x);

    // x is NAN , the result shall be NAN
    if (!isnan_float(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
