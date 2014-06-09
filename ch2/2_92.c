/* Compute |f|. If f is NaN, then return f. */

typedef unsigned float_bits;

float_bits float_absval(float_bits f);

float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 && 0xff;
    unsigned frac = f & 0x7FFFFF;

    if( (~exp) || !frac)
        sign &= 0;

    return sign << 31 | exp << 23 | frac;


}
