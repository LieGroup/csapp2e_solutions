/* Failed attempt at xbyte */
/*
int xbyte(packed_t word, int bytenum)
{
return (word >> (bytenum << 3)) & 0xFF;
}
*/
/*
 * A. the most significant bit of "(word >> (bytenum << 3)) & 0xFF" 
 * is zero, so the function can't correctly deal with negative numbers.
 */

/* 
 * B. correct version of xbyte
 */
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int shift_bits = (3 - bytenum) << 3;
    return word << shift_bits >> 24;
    
}
