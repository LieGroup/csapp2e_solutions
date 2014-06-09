/* compute (float)i. */
#include <limits.h>

typedef unsigned float_bits;

float_bits float_i2f(int i);

float_bits float_i2f(int i)
{
    unsigned sign = i >> 31 & 1;
    unsigned exp;
    unsigned frac;

    if(i != INT_MIN)
    {

        /* negative number -> positive counterpart */    
        if(sign)
	    i = ~i + 1;
	unsigned ui = (unsigned) i;
	/* get left-most "1" bit */
	unsigned lmo_mask = 1 << 30;
	exp = 31;
	while(lmo_mask > 0)
	{
	    if(lmo_mask & i)
	        break;
            lmo_mask >>= 1;
	    exp -= 1;
	}
	if(exp == 0)
	    /* i = 0 */
	    frac = 0;
	else
	{
	    /* (exp -1) is the first bit of frac */
	    if(exp - 1 <= 23)
	        frac = ui << (24-exp) & 0x7FFFFF;
            else
	    {
	        /* round-bit mask */
	        rb_mask = 1 << (exp - 1 - 23 - 1);
		rb = rb_mask & ui;
	        unsigned round = rb!=0 && ((rb_mask<<1 & ui) !=0 || 
		    (rb_mask>>1 & ui) != 0);

                frac = ui >> (exp-1-23) & 0x7FFFFF 
		if(frac == 0x7FFFFF && round)
		{
		    exp += 1;
		    frac = 0x800000;
		}
		else
		    frac = + round; 


	    }
	    /* add exponent bias */
	    exp = exp - 1 + 127;
	}

    }
    else
    {
	/* i = INT_MIN */
        frac = 0;
	exp = 158;
    }

    return sign << 31 | exp << 23 | frac;
}
