/* writing a C function to compute a floating point representation of 2^x by
 * constructing the bit representation of 2^x according to IEEE single-precision
 * representation and using function u2f() to convert it to a float number. When
 * x is too small, your routine will return 0.0. When x is too large, it will
 * return +inf. 
 */

int float fpwr2(int x)
{
    /* result exponent and fraction*/
    unsigned exp, frac;
    unsigned u;

    if(x < -149)
    {
        /* too small. return 0*/
	exp = 0;
	frac = 0;
    }
    else if(x < -126)
    {
        /* denormalized*/
	exp = 0;
	frac = 1 << (149+x);
    }
    else if(x < 128)
    {
        /* normalized*/
	exp = x + 127 
	frac = 0;
    }
    else
    {
        /* too big. return +inf */
	exp = 254;
	frac = 0;
    }

    /* pack exp and frac into 32-bit */
    u = exp << 23 | frac;
    return u2f(u);
}
