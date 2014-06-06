#include <stdio.h>

int main(void)
{
    int x = 0xff000001;
    // return 1 if any bit of x equals 1
    printf("%d\n", x != 0); 
    // return 1 if any bit of x equals 0
    printf("%d\n", (x ^ ~0) != 0);
    // return 1 if any bit in the least significant byte of x equals 1
    printf("%d\n", (x & 0xff) != 0);
    // return 1 if any bit in the most significant byte of x equals 0
    printf("%d\n", (x >> ((sizeof(int) - 1) * 8) & 0xff) != 0xff);
    return 0;

}
