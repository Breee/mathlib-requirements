#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_hypot.h"

int main() {


  /* REQ-BL-1260:
   * The hypot and hypotf procedures shall compute the length of
   * the hypotenuse of a rightangled triangle with sides of length x and y .
   */
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  // TODO: precondition
  if(0) {
		return 0;
	}

	__VERIFIER_precond_reach();

	float res = __ieee754_hypotf(x, y);

  // TODO: postcondition
	if(0)	{
		__VERIFIER_error();
		return 1;
	}

	return 0;
}
