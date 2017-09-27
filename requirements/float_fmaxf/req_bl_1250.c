#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float fmax_float(float x, float y) {
  if (__fpclassifyf(x) == 0) {
    return y;
  }

  if (__fpclassifyf(y) == 0) {
    return x;
  }
  return x > y ? x : y;
}

int main()
{
	// REQ-BL-1250
	float x = NAN;
	float y = NAN;

  // REQ-BL-1250: The fmax and fmaxf procedures shall return NaN, if the arguments x and y are NaN.
	if (isnan_float(x) && isnan_float(y)) {
    __VERIFIER_precond_reach();

    float res = fmax_float(x, y);

    if (!isnan_float(res))	{
      /*@ assert 0==1; */
      //__VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
