#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"


int main() {

  /* REQ-BL-1051
   * The floor and floorf procedures shall return NaN, if the argument x is NaN.
   */

  double x = NAN; // NAN

  if (isnan_double(x)) {
    __VERIFIER_precond_reach();

  	double res = floor_double(x);

    // x is NAN the result shall be NAN
  	if (!isnan_double(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
