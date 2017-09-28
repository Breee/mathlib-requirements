float round_float(float x) {
 __uint32_t w;

 int exponent_less_127;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (w) = gf_u.word; } while (0);


 exponent_less_127 = (int)((w & 0x7f800000) >> 23) - 127;

 if (exponent_less_127 < 23)
   {
     if (exponent_less_127 < 0)
       {
         w &= 0x80000000;
         if (exponent_less_127 == -1)

           w |= ((__uint32_t)127 << 23);
       }
     else
       {
         unsigned int exponent_mask = 0x007fffff >> exponent_less_127;
         if ((w & exponent_mask) == 0)

           return x;

         w += 0x00400000 >> exponent_less_127;
         w &= ~exponent_mask;
       }
   }
 else
   {
     if (exponent_less_127 == 128)

       return x + x;
     else
       return x;
   }
 do { ieee_float_shape_type sf_u; sf_u.word = (w); (x) = sf_u.value; } while (0);
 return x;
}
