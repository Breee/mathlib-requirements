#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"

int main()
{
  /* REQ-BL-0831
   * The exp and expf procedures shall return NaN if the argument x is NaN .
   */

  double x = NAN;
 	double res = __ieee754_exp(x);

   // x is nan, the result shall be nan
   if (!isnan_double(res)) {
   	__VERIFIER_error();
   	return 1;
   }

	return 0;
}
