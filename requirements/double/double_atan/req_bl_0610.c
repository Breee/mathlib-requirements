#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan.h"

int main()
{

  /*
   * REQ-BL-0610:
   * The atan and atanf procedures shall return NaN if the argument is NaN.
   */

  double x = NAN;

  if (isnan_double(x)) {

    __VERIFIER_precond_reach();

  	double res = atan_double(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_double(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
