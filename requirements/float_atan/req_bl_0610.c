#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

static const float atanhi[] = {
  4.6364760399e-01,
  7.8539812565e-01,
  9.8279368877e-01,
  1.5707962513e+00,
};


static const float atanlo[] = {
  5.0121582440e-09,
  3.7748947079e-08,
  3.4473217170e-08,
  7.5497894159e-08,
};


static const float aT[] = {
  3.3333334327e-01,
 -2.0000000298e-01,
  1.4285714924e-01,
 -1.1111110449e-01,
  9.0908870101e-02,
 -7.6918758452e-02,
  6.6610731184e-02,
 -5.8335702866e-02,
  4.9768779427e-02,
 -3.6531571299e-02,
  1.6285819933e-02,
};

float atan_float(float x){
 float w,s1,s2,z;
 __int32_t ix,hx,id;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 ix = hx&0x7fffffff;
 if(ix>=0x50800000) {
     if(((ix)>0x7f800000L))
  return x+x;
     if(hx>0) return atanhi[3]+atanlo[3];
     else return -atanhi[3]-atanlo[3];
 } if (ix < 0x3ee00000) {
     if (ix < 0x31000000) {
  if(huge+x>one) return x;
     }
     id = -1;
 } else {
 x = fabsf(x);
 if (ix < 0x3f980000) {
     if (ix < 0x3f300000) {
  id = 0; x = ((float)2.0*x-one)/((float)2.0+x);
     } else {
  id = 1; x = (x-one)/(x+one);
     }
 } else {
     if (ix < 0x401c0000) {
  id = 2; x = (x-(float)1.5)/(one+(float)1.5*x);
     } else {
  id = 3; x = -(float)1.0/x;
     }
 }}

 z = x*x;
 w = z*z;

 s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
 s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
 if (id<0) return x - x*(s1+s2);
 else {
     z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
     return (hx<0)? -z:z;
 }
}

int main()
{

  /*
   * REQ-BL-0610:
   * The atan and atanf procedures shall return NaN if the argument is NaN.
   */

  float x = NAN;

  if (isnan_float(x)) {

    __VERIFIER_precond_reach();

  	float res = atan_float(x);

    // x is NAN, the result shall be NAN
  	if (!isnan_float(res)) {
  		__VERIFIER_error();
  		return 1;
  	}
	}

	return 0;
}
