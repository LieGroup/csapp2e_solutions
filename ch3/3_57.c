/* int cread(int *xp) {
 *     return (xp ? *xp : 0);
 * }
 * We showed a trial implementation using a conditional move instruction but
 * argued that it was not valid, since it could attempt to read from a null
 * address. Write a C function cread_alt that has the same behavior as cread,
 * except that it can be compiled to use conditional data transfer.
 */
int cread_alt(int *xp)
{
    int t = 0;
    return *(xp ? xp : &t);
}
