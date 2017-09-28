#include "../double_sqrt/double_sqrt.h"
#include "../double_fabs/double_fabs.h"


static const double one_asin = 1.00000000000000000000e+00,
huge_asin = 1.000e+300,
pio2_hi_asin = 1.57079632679489655800e+00,
pio2_lo_asin = 6.12323399573676603587e-17,
pio4_hi_asin = 7.85398163397448278999e-01,
pS0_asin = 1.66666666666666657415e-01,
pS1_asin = -3.25565818622400915405e-01,
pS2_asin = 2.01212532134862925881e-01,
pS3_asin = -4.00555345006794114027e-02,
pS4_asin = 7.91534994289814532176e-04,
pS5_asin = 3.47933107596021167570e-05,
qS1_asin = -2.40339491173441421878e+00,
qS2_asin = 2.02094576023350569471e+00,
qS3_asin = -6.88283971605453293030e-01,
qS4_asin = 7.70381505559019352791e-02;


 double __ieee754_asin(double x) {
 double t,w,p,q,c,r,s;
 __int32_t hx,ix;
 do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
 ix = hx&0x7fffffff;
 if(ix>= 0x3ff00000) {
     __uint32_t lx;
     do { ieee_double_shape_type gl_u; gl_u.value = (x); (lx) = gl_u.parts.lsw; } while (0);
     if(((ix-0x3ff00000)|lx)==0)

  return x*pio2_hi_asin+x*pio2_lo_asin;
     return (x-x)/(x-x);
 } else if (ix<0x3fe00000) {
     if(ix<0x3e400000) {
  if(huge_asin+x>one_asin) return x;
          } else {
  t = x*x;
  p = t*(pS0_asin+t*(pS1_asin+t*(pS2_asin+t*(pS3_asin+t*(pS4_asin+t*pS5_asin)))));
  q = one_asin+t*(qS1_asin+t*(qS2_asin+t*(qS3_asin+t*qS4_asin)));
  w = p/q;
  return x+x*w;
          }
 }

 w = one_asin-fabs_double(x);
 t = w*0.5;
 p = t*(pS0_asin+t*(pS1_asin+t*(pS2_asin+t*(pS3_asin+t*(pS4_asin+t*pS5_asin)))));
 q = one_asin+t*(qS1_asin+t*(qS2_asin+t*(qS3_asin+t*qS4_asin)));
 s = __ieee754_sqrt(t);
 if(ix>=0x3FEF3333) {
     w = p/q;
     t = pio2_hi_asin-(2.0*(s+s*w)-pio2_lo_asin);
 } else {
     w = s;
     do { ieee_double_shape_type sl_u; sl_u.value = (w); sl_u.parts.lsw = (0); (w) = sl_u.value; } while (0);
     c = (t-w*w)/(s+w);
     r = p/q;
     p = 2.0*s*r-(pio2_lo_asin-2.0*c);
     q = pio4_hi_asin-2.0*w;
     t = pio4_hi_asin-(p-q);
 }
 if(hx>0) return t; else return -t;
}
