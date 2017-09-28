#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan.h"

int main()
{

  /*
   * REQ-BL-0620:
   * The atan and atanf procedures shall return the argument if the argument is +-0 .
   */

  float x = -0.0f;

  if (x == -0.0f) {

    __VERIFIER_precond_reach();

    float res = atan_float(x);

    // x is +-0, the result shall be x
    if (res != x) {
    	__VERIFIER_error();
    	return 1;
    }
 	}

 	return 0;
}
