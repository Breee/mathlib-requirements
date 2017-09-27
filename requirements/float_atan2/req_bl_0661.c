#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

static const float pi_o_4 = 7.8539818525e-01,
pi_o_2 = 1.5707963705e+00,
pi = 3.1415927410e+00,
pi_lo = -8.7422776573e-08;


float __ieee754_atan2f(float y, float x) {
float z;
__int32_t k,m,hx,hy,ix,iy;

do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
ix = hx&0x7fffffff;
do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
iy = hy&0x7fffffff;
if(((ix)>0x7f800000L)||
   ((iy)>0x7f800000L))
   return x+y;
if(hx==0x3f800000) return atanf(y);
m = ((hy>>31)&1)|((hx>>30)&2);

if(((iy)==0)) {
    switch(m) {
 case 0:
 case 1: return y;
 case 2: return pi+tiny;
 case 3: return -pi-tiny;
    }
}

if(((ix)==0)) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

if(((ix)==0x7f800000L)) {
    if(((iy)==0x7f800000L)) {
 switch(m) {
     case 0: return pi_o_4+tiny;
     case 1: return -pi_o_4-tiny;
     case 2: return (float)3.0*pi_o_4+tiny;
     case 3: return (float)-3.0*pi_o_4-tiny;
 }
    } else {
 switch(m) {
     case 0: return zero ;
     case 1: return -zero ;
     case 2: return pi+tiny ;
     case 3: return -pi-tiny ;
 }
    }
}

if(((iy)==0x7f800000L)) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

k = (iy-ix)>>23;
if(k > 60) z=pi_o_2+(float)0.5*pi_lo;
else if(hx<0&&k<-60) z=0.0;
else z=atanf(fabsf(y/x));
switch (m) {
    case 0: return z ;
    case 1: {
           __uint32_t zh;
       do { ieee_float_shape_type gf_u; gf_u.value = (z); (zh) = gf_u.word; } while (0);
       do { ieee_float_shape_type sf_u; sf_u.word = (zh ^ 0x80000000); (z) = sf_u.value; } while (0);
     }
     return z ;
    case 2: return pi-(z-pi_lo);
    default:
         return (z-pi_lo)-pi;
}
}

int main()
{
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  /* REQ-BL-0661:
   * The atan2 and atan2f procedures shall return +-0 , if the argument y is +-0 and the argument x > 0.
   */

   if (x > 0.0f && (y == -0.0f || y == +0.0f)) {

      	__VERIFIER_precond_reach();

      	float res = __ieee754_atan2f(y, x);

       // x is > 0, y is -0.0f, the result shall be -0
      	if (x > +0.0f && y == -0.0f && res != -0.0f) {
      		__VERIFIER_error();
      		return 1;
      	}

       // x is > 0, y is +0, the result shall be +0
      	if (x > +0.0f && y == +0.0f && res != +0.0f) {
      		__VERIFIER_error();
      		return 1;
      	}
 	}

 	return 0;
}