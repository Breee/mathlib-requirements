#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_hypot.h"


int main() {


  /* REQ-BL-1260:
   * The hypot and hypotf procedures shall compute the length of
   * the hypotenuse of a rightangled triangle with sides of length x and y .
   */
  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  // TODO: precondition
  if(0) {
		return 0;
	}

	__VERIFIER_precond_reach();

	double res = __ieee754_hypot(x, y);

  // TODO: postcondition
	if(0)	{
		__VERIFIER_error();
		return 1;
	}

	return 0;
}
