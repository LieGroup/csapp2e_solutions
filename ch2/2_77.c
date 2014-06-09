/* divide a integer by power of two. 0<=k<w-1*/
#include <limits.h>

int divide_power2(int x, int k);

int divide_power2(int x, int k)
{
    int bias = (1 << k) - 1;
    (x & INT_MIN) && (x += bias);
    return x >> k;

}

