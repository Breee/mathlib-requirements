#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_log10.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float res = __ieee754_log10f(x);
  return res;
}
