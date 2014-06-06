/*
* mask with least signficant n bits set to 1
* Examples:n=6-->0x2F,n=17-->0x1FFFF
* Assume 1 <= n <= w
*/

#include <stdio.h>

int lower_one_mask(int n);

int main(void)
{
    printf("%x\n", lower_one_mask(17));
    printf("%x\n", lower_one_mask(32));
}

int lower_one_mask(int n)
{
    int x = (1 << (n-1)) - 1;/* set least n-1 bit to 1 */
    return (x << 1) + 1;
}
