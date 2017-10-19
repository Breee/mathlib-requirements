#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_atan.h"

int main() {

  /*
   * REQ-BL-0621:
   * The atan and atanf procedures shall return +-pi/2 if the argument is +-Inf.
   */

  float x = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();
  float res = atan_float(x);
  // if x is +inf the result shall be +pi/2
  if (res != pi_o_2) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
