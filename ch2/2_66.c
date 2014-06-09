#include <stdio.h>
/*
 * Generate mask indicating leftmost 1 in x.  Assume w=32.
 * For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x);

int main(void)
{
    printf("mask for 0xff00 is %x\n", leftmost_one(0xff00));
    printf("mask for 0x6600 is %x\n", leftmost_one(0x6600));
}

int leftmost_one(unsigned x)
{
    /* e.g. x=00101100 */

    x = (x | (x >> 1)) & (x >> 1);/* x= 0001....*/
    x |= x >> 1 ; /* x= 00011... */
    x |= x >> 2 ; /* x= 0001111. */
    x |= x >> 4 ;
    x |= x >> 8 ;
    x |= x >> 16; /* x= 00011111 */
    return x + 1;
}

