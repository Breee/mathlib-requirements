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

  /* REQ-BL-1252:
  * The fmax and fmaxf procedures shall return +0 if one argument is -0
  * and the other +0.
  */

  float x = 0.0f;
  float y = -0.0f;

  if (y == -0.0f && x == 0.0f) {

    __VERIFIER_precond_reach();

  	float res = fmax_float(x, y);

    // y is -0 and x is +0, the result shall be +0
    if (res != 0.0f)	{
  		__VERIFIER_error();
  		return 1;
  	}

	}

	return 0;
}
