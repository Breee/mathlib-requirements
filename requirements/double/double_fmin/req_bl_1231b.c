#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmin.h"

int main() {


  /* REQ-BL-1231:
  * The fmin and fminf procedures shall return the one argument
  * if only the other argument is NaN.
  */

  double x = __VERIFIER_nondet_double();
  double y = 0.0/0.0; // NAN
  if (!isnan_double(x)) {

    __VERIFIER_precond_reach();

    double res = fmin_double(x, y);

      // y is NAN and x is not NAN, the result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
