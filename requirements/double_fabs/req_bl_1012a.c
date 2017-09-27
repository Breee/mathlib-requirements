#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

int main()
{

  /*
   * REQ-BL-1011
   * The fabs and fabsf procedures shall return +Inf , if the argument x is +-Inf .
   */

  double x = INFINITY; // inf

  if (isinf_double(x)) {
    __VERIFIER_precond_reach();

    double res = fabs_double(x);

    // x is +inf, result shall be +inf
    if (!isinf_double(res)) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
