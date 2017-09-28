#include "../float_atan/float_atan.h"

static const float tiny_atan2 = 1.0e-30,
zero_atan2 = 0.0,
pi_o_4 = 7.8539818525e-01,
pi_o_2 = 1.5707963705e+00,
pi = 3.1415927410e+00,
pi_lo_atan2 = -8.7422776573e-08;


float __ieee754_atan2f(float y, float x){
 float z;
 __int32_t k,m,hx,hy,ix,iy;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 ix = hx&0x7fffffff;
 do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
 iy = hy&0x7fffffff;
 if(((ix)>0x7f800000L)||
    ((iy)>0x7f800000L))
    return x+y;
 if(hx==0x3f800000) return atan_float(y);
 m = ((hy>>31)&1)|((hx>>30)&2);


 if(((iy)==0)) {
     switch(m) {
  case 0:
  case 1: return y;
  case 2: return pi+tiny_atan2;
  case 3: return -pi-tiny_atan2;
     }
 }

 if(((ix)==0)) return (hy<0)? -pi_o_2-tiny_atan2: pi_o_2+tiny_atan2;


 if(((ix)==0x7f800000L)) {
     if(((iy)==0x7f800000L)) {
  switch(m) {
      case 0: return pi_o_4+tiny_atan2;
      case 1: return -pi_o_4-tiny_atan2;
      case 2: return (float)3.0*pi_o_4+tiny_atan2;
      case 3: return (float)-3.0*pi_o_4-tiny_atan2;
  }
     } else {
  switch(m) {
      case 0: return zero_atan2 ;
      case 1: return -zero_atan2 ;
      case 2: return pi+tiny_atan2 ;
      case 3: return -pi-tiny_atan2 ;
  }
     }
 }

 if(((iy)==0x7f800000L)) return (hy<0)? -pi_o_2-tiny_atan2: pi_o_2+tiny_atan2;


 k = (iy-ix)>>23;
 if(k > 60) z=pi_o_2+(float)0.5*pi_lo_atan2;
 else if(hx<0&&k<-60) z=0.0;
 else z=atan_float(fabs_float(y/x));
 switch (m) {
     case 0: return z ;
     case 1: {
            __uint32_t zh;
        do { ieee_float_shape_type gf_u; gf_u.value = (z); (zh) = gf_u.word; } while (0);
        do { ieee_float_shape_type sf_u; sf_u.word = (zh ^ 0x80000000); (z) = sf_u.value; } while (0);
      }
      return z ;
     case 2: return pi-(z-pi_lo_atan2);
     default:
          return (z-pi_lo_atan2)-pi;
 }
}
