/* compute 0.5*f. if f is NaN, return f */
typedef unsigned float_bits;

float_bits float_twice(float_bits f);

float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7FFFFF;
    unsigned round_to_even = (frac & 0x11) == 0x11;
    if(exp == 0)
    {
        /* denormalized */
	frac = (frac >> 1) + round_to_even;
    }
    else if(exp == 1)
    {
	/* special case when exp=1 */
	if(frac == 0x7fffff)
	    frac = 0;
	else
	{
            frac = (1 << 22) | (frac >> 1) + round_to_even;
	    exp = 0;
	}
    }
    else if(exp <= 254)
    {
        /* normalized */
	exp -= 1;
    }
    /* do nothing when exp=255 */

    return sign << 31 | exp << 23 | frac;
}
