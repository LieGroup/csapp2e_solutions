/* test whether float x is less than or equal to float y*/

int float_le(float x, float y);
int float_le(float x, float y)
{
    /* f2u() returns an unsigned 32-bit number have the same bit representation
     * as its floating-point argument
     */
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* get the sign bit*/
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    /* x<0&&y>0 or x<0&&y<0&&x>=y or x>0&&y>0&&x<=y or x=y=0*/
    return (sx && !sy) || (sx && sy && ux>=uy) || (!sx && !sy && ux<=uy) ||
    !(ux << 1 | uy << 1);
}
