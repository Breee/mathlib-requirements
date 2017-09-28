#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_modf.h"

int main()
{
  float x = NAN;
  float iptr;

  /* REQ-BL-1210
   * The modf and modff procedures shall return NaN and set the argument ∗iptr to NaN, if the argument x is NaN .
   */

  if (isnan_float(x)){
    __VERIFIER_precond_reach();

  	float res = modf_float(x, &iptr);

    // x is NAN, *iptr is NAN result shall be that *iptr and x is NAN
  	if (isnan_float(x) && isnan_float(iptr) && !isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}
	return 0;
}
