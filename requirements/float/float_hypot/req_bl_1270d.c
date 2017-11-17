#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_hypot.h"

int main() {

  /* REQ-BL-1270:
   * The hypot and hypotf procedures shall return +Inf,
   * if one of the arguments x or y is ±Inf.
   */

  float x = __VERIFIER_nondet_float();
  float y = -1.0f / 0.0f; // -inf
  __VERIFIER_precond_reach();

  float res = __ieee754_hypotf(x, y);

  if (!isinf_float(res)) {
    __VERIFIER_error();
    return 1;
  }
  return 0;
}
