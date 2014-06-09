/* we are running programs on a machine where values of typeintare 32 bits.
 * They are represented in two's complement, and they are right shifted
 * arithmetically. Values of typeunsignedare also 32 bits.
 *

 * Create some arbitrary values
 *
 * int x = random();
 * int y = random();
 *
 * Convert to unsigned
 *
 * unsigned ux = (unsigned) x;
 * unsigned uy = (unsigned) y;

 * For each of the following C expressions, indicate whether or not the
 * expression always yields 1.
 *
 * A. (x<y) == (-x>-y)
 * B. ((x+y)<<4) + y-x == 17*y+15*x
 * C. ~x+~y+1 == ~(x+y)
 * D. (ux-uy) == -(unsigned)(y-x)
 * E. ((x >> 2) << 2) <= x
 */


/*
 * A. false. e.g. x=INT_MIN
 * B. true.
 * C. true. ~x+~y+1=~x+1 + ~y+1 -1 = -x + -y -1 = -(x+y) -1 = ~(x+y)
 * D. true.
 * E. true
 */
