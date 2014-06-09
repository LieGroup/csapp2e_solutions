/* function mul3div4 computes3*x/4, replicate the fact that the computation 3*x
 * can cause overflow.
 */

int mul3div4(int x)
{
    int bias = 3;
    int sign = ((1 << 31) & x) != 0;
    x = x << 1 + x;
    return (x + (bias & sign)) >> 2;
}
