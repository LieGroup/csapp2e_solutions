/* determine if substraction overflows*/
#include <stdio.h>
#include <limits.h>
int tsub_ok(int x, int y);

int main(void)
{
    printf("%d\n", tsub_ok(1, 0x80000000));
    printf("%d\n", tsub_ok(-1, 0x80000000));
}

int tsub_ok(int x, int y)
{
    /* substraction overflow only occurs when x*y<=0 */
    int t = x - y;
    int pos_overflow = !(x & INT_MIN) && (y & INT_MIN) && (t & INT_MIN);
    int neg_overflow = (x & INT_MIN) && !(y & INT_MIN) && !(t & INT_MIN);

    return !(pos_overflow || neg_overflow);
}
