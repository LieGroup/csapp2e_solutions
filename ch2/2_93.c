/* compute 2*f. if f is NaN, return f */
typedef unsigned float_bits;

float_bits float_twice(float_bits f);
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7FFFFF;

    /* denormalized */
    if(exp == 0)
    {
        /* frac=1XXXXX... */ 
        if(frac >> 22)
	{
	    exp += 1;
	    frac = frac << 1 & 0x7FFFFFF; 
	}
	else
	    frac <<= 1;
    }
    else if(exp <= 254)
    {
        /* normalized */
	exp += 1;
	if(exp == 255)
	    frac = 0;
    }
    /* do nothing when exp=255 */

    return sign << 31 | exp << 23 | frac;
}
