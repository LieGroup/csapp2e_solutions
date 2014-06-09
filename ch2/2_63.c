#include <stdio.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

int main(void)
{
    printf("%x\n", srl(0xf0000000,3));
    printf("%x\n", sra((int)0xf0000000,3));
    printf("%x\n", sra((int)0x70000000,3));
    return 0;
}

int sra(int x, int k)
{
    // perform shift logically
    int xsrl = (unsigned)x >> k;
    // get sign of the most significant bit of x
    int negative = (x & (1 << (sizeof(int)*8 - 1))) != 0;
    if(negative == 0)
        return xsrl;
    // produce mask as 1110...0
    unsigned mask = ~0 << (sizeof(int)*8 - k);
    return xsrl ^ mask;
}
unsigned srl(unsigned x, int k)
{
    // perform shift arithmetically
    unsigned xsra = (int)x >> k;
    // produce mask as 0001..1111
    unsigned mask = ~(~0 << (sizeof(int)*8 - k));
    // set most significant k-bit of xsra to 0
    return xsra & mask;
}
