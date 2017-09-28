float trunc_float(float x) {
 __int32_t signbit, w, exponent_less_127;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (w) = gf_u.word; } while (0);
 signbit = w & 0x80000000;
 exponent_less_127 = ((w & 0x7f800000) >> 23) - 127;
 if (exponent_less_127 < 23)
   {
     if (exponent_less_127 < 0)
       {

         do { ieee_float_shape_type sf_u; sf_u.word = (signbit); (x) = sf_u.value; } while (0);
       }
     else {
         do { ieee_float_shape_type sf_u; sf_u.word = (signbit | (w & ~(0x007fffff >> exponent_less_127))); (x) = sf_u.value; } while (0);
     }
   }
 else
   {
     if (exponent_less_127 == 255)
       return x + x;
   }
 return x;
}
