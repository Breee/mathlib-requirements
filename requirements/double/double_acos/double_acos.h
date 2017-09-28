#include "../double_sqrt/double_sqrt.h"

static const double one_acos= 1.00000000000000000000e+00,
pi = 3.14159265358979311600e+00,
pio2_hi_acos = 1.57079632679489655800e+00,
pio2_lo_acos = 6.12323399573676603587e-17,
pS0_acos = 1.66666666666666657415e-01,
pS1_acos = -3.25565818622400915405e-01,
pS2_acos = 2.01212532134862925881e-01,
pS3_acos = -4.00555345006794114027e-02,
pS4_acos = 7.91534994289814532176e-04,
pS5_acos = 3.47933107596021167570e-05,
qS1_acos = -2.40339491173441421878e+00,
qS2_acos = 2.02094576023350569471e+00,
qS3_acos = -6.88283971605453293030e-01,
qS4_acos = 7.70381505559019352791e-02;


 double __ieee754_acos(double x){
 double z,p,q,r,w,s,c,df;
 __int32_t hx,ix;
 do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
 ix = hx&0x7fffffff;
 if(ix>=0x3ff00000) {
     __uint32_t lx;
     do { ieee_double_shape_type gl_u; gl_u.value = (x); (lx) = gl_u.parts.lsw; } while (0);
     if(((ix-0x3ff00000)|lx)==0) {
  if(hx>0) return 0.0;
  else return pi+2.0*pio2_lo_acos;
     }
     return (x-x)/(x-x);
 }
 if(ix<0x3fe00000) {
     if(ix<=0x3c600000) return pio2_hi_acos+pio2_lo_acos;
     z = x*x;
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     r = p/q;
     return pio2_hi_acos - (x - (pio2_lo_acos-x*r));
 } else if (hx<0) {
     z = (one_acos+x)*0.5;
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     s = __ieee754_sqrt(z);
     r = p/q;
     w = r*s-pio2_lo_acos;
     return pi - 2.0*(s+w);
 } else {
     z = (one_acos-x)*0.5;
     s = __ieee754_sqrt(z);
     df = s;
     do { ieee_double_shape_type sl_u; sl_u.value = (df); sl_u.parts.lsw = (0); (df) = sl_u.value; } while (0);
     c = (z-df*df)/(s+df);
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     r = p/q;
     w = r*s+c;
     return 2.0*(df+w);
 }
}
