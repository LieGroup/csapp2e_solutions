#include <stdio.h>
/* return 1 if x contains odd number of 1s. Assume x is 32-bit int*/
int odd_ones(unsigned x);

int main(void)
{
    printf("%d\n", odd_ones(0x3));
    printf("%d\n", odd_ones(0x7));
    return 0;
}
int odd_ones(unsigned x)
{
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}
