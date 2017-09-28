#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_acos.h"

int main()
{

  /* REQ-BL-0480:
   * The acos and acosf procedures shall return NAN , if the argument x is +-inf
   */

  float x = -INFINITY;

  if (isinf_float(x)) {

    __VERIFIER_precond_reach();

  	float res = __ieee754_acosf(x);

    // x is +-inf, the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
