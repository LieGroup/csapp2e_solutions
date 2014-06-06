/*
 * rotating left shift. Assume 0 <=n<w
 * Examples when x = 0x12345678 andw=32:
 * n=4 -> 0x23456781, n=20 -> 0x67812345
 */
#include <stdio.h>

unsigned rotate_lshift(unsigned x, int n);

int main(void)
{
    printf("%x\n", rotate_lshift(0x12345678, 4));
    printf("%x\n", rotate_lshift(0x12345678, 20));
    printf("%x\n", rotate_lshift(0x12345678, 0));
}

unsigned rotate_lshift(unsigned x, int n)
{
    int w = sizeof(x) << 3;
    /* right shift w-n bits to get the leftmost n bits*/
    unsigned msnb = (x >> (w-n-1)) >> 1;
    return (x << n) | msnb;
}
