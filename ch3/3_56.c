/* Consider the following assembly code:
 * x at %ebp+8, n at %ebp+12
 * 1 movl 8(%ebp), %esi
 * 2 movl 12(%ebp), %ebx
 * 3 movl $-1, %edi
 * 4 movl $1, %edx
 * 5 .L2:
 * 6 movl %edx, %eax
 * 7 andl %esi, %eax
 * 8 xorl %eax, %edi
 * 9 movl %ebx, %ecx
 * 10 sall %cl, %edx
 * 11 testl %edx, %edx
 * 12 jne .L2
 * 13 movl %edi, %eax
 */
int loop(int x, int n)
{
    int result = -1; /* by line 13, edi <-> result */
    int mask; /* by line 11, edx <-> mask */

    for(mask = 1; mask != 0 ; mask = mask << (n & 0xFF))
    {
        result ^= (mask & x);
    }
    return result;
}
