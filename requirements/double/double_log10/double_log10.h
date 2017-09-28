#include "../double_log/double_log.h"

static const double two54_log10 = 1.80143985094819840000e+16,
ivln10_log10 = 4.34294481903251816668e-01,
log10_2hi_log10 = 3.01029995663611771306e-01,
log10_2lo_log10 = 3.69423907715893078616e-13;


static const double zero_log10 = 0.0;

double __ieee754_log10(double x) {
 double y,z;
 __int32_t i,k,hx;
 __uint32_t lx;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);

        k=0;
        if (hx < 0x00100000) {
            if (((hx&0x7fffffff)|lx)==0)
                return -two54_log10/zero_log10;
            if (hx<0) return (x-x)/zero_log10;
            k -= 54; x *= two54_log10;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
        }
 if (hx >= 0x7ff00000) return x+x;
 k += (hx>>20)-1023;
 i = ((__uint32_t)k&0x80000000)>>31;
        hx = (hx&0x000fffff)|((0x3ff-i)<<20);
        y = (double)(k+i);
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (hx); (x) = sh_u.value; } while (0);
 z = y*log10_2lo_log10 + ivln10_log10*__ieee754_log(x);
 return z+y*log10_2hi_log10;
}
