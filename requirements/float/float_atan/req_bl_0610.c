#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan.h"

int main()
{

  /*
   * REQ-BL-0610:
   * The atan and atanf procedures shall return NaN if the argument is NaN.
   */

  float x = NAN;

  if (isnan_float(x)) {

    __VERIFIER_precond_reach();

  	float res = atan_float(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
