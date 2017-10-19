#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_sqrt.h"

int main() {

  /*
   * REQ-BL-0730:
   * The sqrt and sqrtf procedures shall return the argument if the argument x
   * is +-0 or +Inf.
   */

  float x = 1.0f / 0.0f; // INF
  __VERIFIER_precond_reach();

  float res = __ieee754_sqrtf(x);

  // x +inf the result shall be x
  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
