#include <stdio.h>

int main(void)
{
    int k = 3, j = 4;
    printf("%x\n", ~0 << k);
    printf("%x\n", ~(~0 << k) << j);
    return 0;
}
