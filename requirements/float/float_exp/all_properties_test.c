#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_exp.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float res = __ieee754_expf(x);
  return res;
}
