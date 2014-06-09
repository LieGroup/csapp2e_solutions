/* Suppose we want to compute the complete 2w-bit representation of x*y, where
 * both x and y are unsigned, on a machine for which data type unsigned is w
 * bits.The low-order w bits of the product can be computed with the expression
 * x*y, so we only require a procedure with prototype
 *
 * unsigned int unsigned_high_prod(unsigned x, unsigned y);
 *
 * that computes the high-orderwbits ofx.yfor unsigned variables. We have
 * access to a library function with prototype
 *
 * int signed_high_prod(int x, int y);
 *
 * that computes the high-order w bits of x*y for the case where x and y are
 * in two's complement form. Write code calling this procedure to implement
 * the function for unsigned arguments.
 */
unsigned int unsigned_high_prod(unsigned x, unsigned y);

unsigned int unsigned_high_prod(unsigned x, unsigned y)
{
    /* this solution is based on equation(2.18) on pp.90*/
    int w = sizeof(int) << 3;
    int msb_x = x >> (w-1);
    int msb_y = y >> (w-1);

    return signed_high_prod(x, y) + msb_y*x + msb_x*y;
}
