#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

static const float one = 1.0000000000e+00,
huge = 1.000e+30,
pio2_hi = 1.57079637050628662109375f,
pio2_lo = -4.37113900018624283e-8f,
pio4_hi = 0.785398185253143310546875f,
pS0 = 1.6666667163e-01,
pS1 = -3.2556581497e-01,
pS2 = 2.0121252537e-01,
pS3 = -4.0055535734e-02,
pS4 = 7.9153501429e-04,
pS5 = 3.4793309169e-05,
qS1 = -2.4033949375e+00,
qS2 = 2.0209457874e+00,
qS3 = -6.8828397989e-01,
qS4 = 7.7038154006e-02;


 float __ieee754_asinf(float x){
 float t,w,p,q,c,r,s;
 __int32_t hx,ix;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 ix = hx&0x7fffffff;
 if(ix==0x3f800000) {

     return x*pio2_hi+x*pio2_lo;
 } else if(ix> 0x3f800000) {
     return (x-x)/(x-x);
 } else if (ix<0x3f000000) {
     if(ix<0x32000000) {
  if(huge+x>one) return x;
          } else {
  t = x*x;
  p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
  q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
  w = p/q;
  return x+x*w;
          }
 }

 w = one-fabsf(x);
 t = w*(float)0.5;
 p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
 q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
 s = __ieee754_sqrtf(t);
 if(ix>=0x3F79999A) {
     w = p/q;
     t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
 } else {
     __int32_t iw;
     w = s;
     do { ieee_float_shape_type gf_u; gf_u.value = (w); (iw) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (iw&0xfffff000); (w) = sf_u.value; } while (0);
     c = (t-w*w)/(s+w);
     r = p/q;
     p = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
     q = pio4_hi-(float)2.0*w;
     t = pio4_hi-(p-q);
 }
 if(hx>0) return t; else return -t;
}

int main() {

  /*
   * REQ-BL-0270
   * The asin and asinf procedures shall return NaN if the argument is not in the range [-1, 1].
   */

   float x = __VERIFIER_nondet_float();

   if (x < -1.0f && x > 1.0f) {

     __VERIFIER_precond_reach();

   	float res = __ieee754_asinf(x);

     // x is not in [-1,1] the result shall be NAN
   	if (!isnan_float(res))	{
   		__VERIFIER_error();
   		return 1;
   	}
   }

	return 0;
}
