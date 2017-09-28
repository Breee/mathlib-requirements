#include "../double_copysign/double_copysign.h"

static const double two54_scalbn = 1.80143985094819840000e+16,
twom54_scalbn = 5.55111512312578270212e-17,
huge_scalbn = 1.0e+300,
tiny_scalbn = 1.0e-300;

double scalbn_double (double x, int n) {
 __int32_t k,hx,lx;
 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
        k = (hx&0x7ff00000)>>20;
        if (k==0) {
            if ((lx|(hx&0x7fffffff))==0) return x;
     x *= two54_scalbn;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
     k = ((hx&0x7ff00000)>>20) - 54;
            if (n< -50000) return tiny_scalbn*x;
     }
        if (k==0x7ff) return x+x;
        k = k+n;
        if (k > 0x7fe) return huge_scalbn*copysign_double(huge_scalbn,x);
        if (k > 0)
     {do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x800fffff)|(k<<20)); (x) = sh_u.value; } while (0); return x;}
        if (k <= -54) {
            if (n > 50000)
  return huge_scalbn*copysign_double(huge_scalbn,x);
     else return tiny_scalbn*copysign_double(tiny_scalbn,x);
      }
        k += 54;
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = ((hx&0x800fffff)|(k<<20)); (x) = sh_u.value; } while (0);
        return x*twom54_scalbn;
}
