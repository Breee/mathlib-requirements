#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

static const double pi_o_4 = 7.8539816339744827900E-01,
pi_o_2 = 1.5707963267948965580E+00,
pi = 3.1415926535897931160E+00,
pi_lo = 1.2246467991473531772E-16;


double __ieee754_atan2(double y, double x) {
 double z;
 __int32_t k,m,hx,hy,ix,iy;
 __uint32_t lx,ly;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
 ix = hx&0x7fffffff;
 do { ieee_double_shape_type ew_u; ew_u.value = (y); (hy) = ew_u.parts.msw; (ly) = ew_u.parts.lsw; } while (0);
 iy = hy&0x7fffffff;
 if(((ix|((lx|-lx)>>31))>0x7ff00000)||
    ((iy|((ly|-ly)>>31))>0x7ff00000))
    return x+y;
 if(((hx-0x3ff00000)|lx)==0) return atan_double(y);
 m = ((hy>>31)&1)|((hx>>30)&2);


 if((iy|ly)==0) {
     switch(m) {
  case 0:
  case 1: return y;
  case 2: return pi+tiny;
  case 3: return -pi-tiny;
     }
 }

 if((ix|lx)==0) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

 if(ix==0x7ff00000) {
     if(iy==0x7ff00000) {
  switch(m) {
      case 0: return pi_o_4+tiny;
      case 1: return -pi_o_4-tiny;
      case 2: return 3.0*pi_o_4+tiny;
      case 3: return -3.0*pi_o_4-tiny;
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

 if(iy==0x7ff00000) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

 k = (iy-ix)>>20;
 if(k > 60) z=pi_o_2+0.5*pi_lo;
 else if(hx<0&&k<-60) z=0.0;
 else z=atan_double(fabs_double(y/x));
 switch (m) {
     case 0: return z ;
     case 1: {
            __uint32_t zh;
        do { ieee_double_shape_type gh_u; gh_u.value = (z); (zh) = gh_u.parts.msw; } while (0);
        do { ieee_double_shape_type sh_u; sh_u.value = (z); sh_u.parts.msw = (zh ^ 0x80000000); (z) = sh_u.value; } while (0);
      }
      return z ;
     case 2: return pi-(z-pi_lo);
     default:
          return (z-pi_lo)-pi;
 }
}

int main()
{

  /* REQ-BL-0681:
   * The atan2 and atan2f procedures shall return +-0 , if the argument y is +-0 and the argument x is +0.
   */

   double x = 0.0;
   double y = -0.0;

   if (x == 0.0 && y == -0.0) {

     __VERIFIER_precond_reach();

     double res = __ieee754_atan2(y, x);

     // x is +0, y is -0, the result shall be -0
     if (res != -0.0) {
       __VERIFIER_error();
       return 1;
     }
 	}

 	return 0;
}
