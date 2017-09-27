#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double ceil_double(double x) {
 __int32_t i0,i1,j0;
 __uint32_t i,j;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (i0) = ew_u.parts.msw; (i1) = ew_u.parts.lsw; } while (0);
 j0 = ((i0>>20)&0x7ff)-0x3ff;
 if(j0<20) {
     if(j0<0) {
  if(huge+x>0.0) {
      if(i0<0) {i0=0x80000000;i1=0;}
      else if((i0|i1)!=0) { i0=0x3ff00000;i1=0;}
  }
     } else {
  i = (0x000fffff)>>j0;
  if(((i0&i)|i1)==0) return x;
  if(huge+x>0.0) {
      if(i0>0) i0 += (0x00100000)>>j0;
      i0 &= (~i); i1=0;
  }
     }
 } else if (j0>51) {
     if(j0==0x400) return x+x;
     else return x;
 } else {
     i = ((__uint32_t)(0xffffffff))>>(j0-20);
     if((i1&i)==0) return x;
     if(huge+x>0.0) {
  if(i0>0) {
      if(j0==20) i0+=1;
      else {
   j = i1 + (1<<(52-j0));
   if(j<i1) i0+=1;
   i1 = j;
      }
  }
  i1 &= (~i);
     }
 }
 do { ieee_double_shape_type iw_u; iw_u.parts.msw = (i0); iw_u.parts.lsw = (i1); (x) = iw_u.value; } while (0);
 return x;
}


int main() {

  /*
   * REQ-BL-1092:
   * The ceil and ceilf procedures shall return the argument, if the argument x is -+0 or -+Inf.
   */

  double x = INFINITY;

  if (isinf_double(x)) {

    __VERIFIER_precond_reach();

  	double res = ceil_double(x);

    // x is -+0 or +inf , the result shall be x
  	if (res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

	}

	return 0;
}
