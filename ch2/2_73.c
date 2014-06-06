/* saturating addition*/
#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);

int saturating_add(int x, int y)
{
    int t = x + y;
    int w = sizeof(int) << 3;
    /* most significant bit(msb) of x, y, and t*/
    int msb_x = x >> (w-1) & 1;
    int msb_y = y >> (w-1) & 1;
    int msb_t = t >> (w-1) & 1;
    /* overflow*/
    pos_overflow = !msb_x && !msb_y && msb_t;
    neg_overflow = msb_x && msb_y && !msb_t;

    (pos_overflow && (t=INT_MAX)) || (neg_overflow && (t=INT_MIN));
    return t;

}
