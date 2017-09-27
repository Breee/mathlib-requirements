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

  /* REQ-BL-1240:
  * The fmax and fmaxf procedures shall determine the
  * maximum numeric value of the argument x and y.
  */

  double x = __VERIFIER_nondet_double();
	double y = __VERIFIER_nondet_double();

  // continue if x or y is not nan, both not nan, x and y not +-0 at the same time.
  // this IF-statement excludes the cases of the other requirements.
  if(!isnan_double(x) && !isnan_double(y)
     && ((x != -0.0 &&  y != 0.0) || (x != 0.0 && y != -0.0))) {

    __VERIFIER_precond_reach();

  	double res = fmax_double(x, y);

    // x is bigger than y, then the result should be x
  	if (x > y && res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

    // x is smaller or equal to y,  then the result shall be y
    if (x <= y && res != y )	{
  		__VERIFIER_error();
  		return 1;
  	}
  }

	return 0;
}
