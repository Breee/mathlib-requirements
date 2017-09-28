#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmin.h"

int main() {


  /* REQ-BL-1231:
  * The fmin and fminf procedures shall return the one argument
  * if only the other argument is NaN.
  */

  double x = NAN; // NAN;
  double y = __VERIFIER_nondet_double();
  if (isnan_double(x) && !isnan_double(y)) {

    __VERIFIER_precond_reach();

    double res = fmin_double(x, y);

    // x is NAN and y is not NAN, the result shall be y
    if (res != y)	{
      __VERIFIER_error();
      return 1;
    }

	}

	return 0;
}
