/* return 1 when x can be represented as an n-bit, 2¡¯s complement
* number; 0 otherwise Assume 1 <= n <= w
*/

#include <stdio.h>

int fits_bits(int x, int n);
int fits_bits2(int x, int n);

int main(void)
{
    printf("%d\n", fits_bits(-8, 4));
    printf("%d\n", fits_bits2(-8, 4));
    
}

int fits_bits(int x, int n)
{
    /* assume x is a w-bit int. if the nth to the wth bits of 
     * x are all 0s, or all 1s, then x can be represented as
     * an n-bit, 2's complement number
     */
     
     /* NOTE: this method doesn't rely on arithmetic right shift*/
     int y = ~0 << (n-1); /* all 1s from nth to wth bits */
     x &= y; /* nth to wth bits of x*/
     return (x == 0) ^ ((x^y) == 0);

}


int fits_bits2(int x, int n)
{
    /* NOTE: this method DOES rely on arithmetic right shift*/
    int w = sizeof(x) << 3;
    return x == (x << (w-n) >> (w-n));
}
