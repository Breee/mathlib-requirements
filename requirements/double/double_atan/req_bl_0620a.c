#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan.h"

int main()
{

  /*
   * REQ-BL-0620:
   * The atan and atanf procedures shall return the argument if the argument is +-0 .
   */

  double x = -0.0;
  __VERIFIER_precond_reach();
  
  double res = atan_double(x);

  // x is +-0, the result shall be x
  if (res != x) {
    __VERIFIER_error();
    	return 1;
  }

 	return 0;
}
