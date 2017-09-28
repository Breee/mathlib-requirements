#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_cos.h"

int main() {

  /*
   * REQ-BL-0310//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The cos and cosf procedures shall return NaN if the argument is NaN .
   */

  float x = NAN;

  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

  	float res = cos_float(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_float(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
