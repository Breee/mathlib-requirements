#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_exp.h"

int main()
{
  /* REQ-BL-0831
   * The exp and expf procedures shall return NaN if the argument x is NaN .
   */

  float x = NAN;
 	float res = __ieee754_expf(x);

   // x is +inf, the result shall be x
   if (!isnan_float(res)) {
   	__VERIFIER_error();
   	return 1;
   }

	return 0;
}
