#include <stdio.h>

int is_arithmetic_rshift();

int main(void)
{
    printf("%d\n", is_arithmetic_rshift());
    return 0;
}
int is_arithmetic_rshift()
{
    int x = 0xf0000000;
    return ((x >> 1) & (1 << (8*sizeof(int) - 1))) != 0; 
}
