/* compute (int)f. if conversion causes overflow or f is NaN, return f. the
 * conversion should round toward zero
 */
#include <limits.h>

typedef unsigned float_bits;

int float_f2i(float_bits f);

int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    int exp = (f >> 23 & 0xff) - 127;
    unsigned frac = f & 0x7FFFFF;
    int result = 0x80000000;


    if(exp < 0)
    {
        /* abs|f| < 1 */
	result = 0;

    }
    else if(exp <= 23)
    {
        result = frac >> (23-exp) | 1 << exp;
	/* negative number */
	if(sign)
	    result = ~result + 1;
    }
    else if(exp <= 30)
    {
        result = frac << (exp-23) | 1 << exp;
	if(sign)
	    result = ~result + 1;
    }
    else if(sign && exp==31)
    {
        result = INT_MIN;
    }

    /* do nothing when exp>31 */

    return result;
}
