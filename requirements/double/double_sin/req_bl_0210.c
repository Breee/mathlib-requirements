#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_sin.h"

int main() {

  /*
   * REQ-BL-0210//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The sin and sinf procedures shall return NaN if the argument is NaN .
   */

  double x = NAN;

  if (isnan_double(x)) {
    __VERIFIER_precond_reach();

  	double res = sin_double(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_double(res))	{
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
