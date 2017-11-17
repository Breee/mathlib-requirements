#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_modf.h"

int main() {
  /* REQ-BL-1210
  * The modf and modff procedures shall return NaN and set the argument ∗iptr to
  * NaN, if the argument x is NaN .
  */
  float x = 0.0f / 0.0f; // NAN
  float iptr;
  __VERIFIER_precond_reach();
  float res = modf_float(x, &iptr);

  // x is NAN, *iptr is NAN result shall be that *iptr and res is NAN
  if (isnan_float(iptr) && !isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }
  return 0;
}
