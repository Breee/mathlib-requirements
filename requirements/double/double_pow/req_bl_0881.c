#include "../../includes/math_functions_double.h"
#include "../../includes/verify.h"
#include "../double_fmod/double_fmod.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0881//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return -Inf , if the argument x is -Inf
   * and the argument y is an even integer > 0.
   */

  double x = -1.0 / 0.0; // -INF
  double y = __VERIFIER_nondet_double();

  if (y > 0.0 && isinteger_double(y) && (fmod_double(y, 2.0) == 0.0)) {

    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x, y);

    // result shall be -inf
    if (!isinf_double(res)) {
      __VERIFIER_error();
      return 1;
    }
  }

  return 0;
}
