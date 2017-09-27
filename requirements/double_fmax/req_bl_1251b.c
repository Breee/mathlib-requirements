#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double fmax_double(double x, double y) {

 if (__fpclassifyd(x) == 0)
   return y;
 if (__fpclassifyd(y) == 0)
   return x;

 return x > y ? x : y;
}

int main()
{
	double x = __VERIFIER_nondet_double();
	double y = NAN; // NAN

  /* REQ-BL-1251:
  * The fmax and fmaxf procedures shall return the one argument
  * if only the other argument is NaN.
  */

  if (!isnan_double(x) && isnan_double(y)) {

    __VERIFIER_precond_reach();

    double res = fmax_double(x, y);

    // y is NAN and x is not NAN, the result shall be x
    if (res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
