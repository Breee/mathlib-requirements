#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_acos.h"

int main() {

  /*
   * REQ-BL-0480:
   * The acos and acosf procedures shall return NAN, if the argument x is NAN
   */

  double x = NAN;

  if (isnan_double(x)) {

    __VERIFIER_precond_reach();

  	double res = __ieee754_acos(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_double(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
