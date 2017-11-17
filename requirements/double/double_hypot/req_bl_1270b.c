#include "../../includes/math_functions_double.h"
#include "../../includes/verify.h"
#include "double_hypot.h"

int main() {

  /* REQ-BL-1270:
   * The hypot and hypotf procedures shall return +Inf,
   * if one of the arguments x or y is ±Inf.
   */

  double x = -1.0 / 0.0; // INF
  double y = __VERIFIER_nondet_double();
  __VERIFIER_precond_reach();

  double res = __ieee754_hypot(x, y);

  if (!isinf_double(res)) {
    __VERIFIER_error();
    return 1;
  }
  return 0;
}
