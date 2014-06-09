/* The following code computes the product ofxandyand stores the result in
 * memory. Data typell_tis defined to be equivalent tolong long.
 *
 * typedef long long ll_t;
 * void store_prod(ll_t *dest, int x, ll_t y) {
 *     *dest = x*y;
 * }
 *
 * gcc generates the following assembly code implementing the computation:
 * dest at %ebp+8, x at %ebp+12, y at %ebp+16
 * 1 movl 16(%ebp), %esi
 * 2 movl 12(%ebp), %eax
 * 3 movl %eax, %edx
 * 4 sarl $31, %edx
 * 5 movl 20(%ebp), %ecx
 * 6 imull %eax, %ecx
 * 7 movl %edx, %ebx
 * 8 imull %esi, %ebx
 * 9 addl %ebx, %ecx
 * 10 mull %esi
 * 11 leal (%ecx,%edx), %edx
 * 12 movl 8(%ebp), %ecx
 * 13 movl %eax, (%ecx)
 * 14 movl %edx, 4(%ecx)
 * This code uses three multiplications to implement the multiprecision arith-
 * metic required to implement 64-bit arithmetic on a 32-bit machine. Describe
 * the algorithm used to compute the product, and annotate the assembly code to
 * show how it realizes your algorithm.
 */


/*
 * let y64=y=y_h*2^32+y_l x64=(sign_ext_x)*2^32 + x
 * (x*y)64=(y_h*x*2^32+x*y_l+y_l*(sign_ext_x)*2^32+y_h*(sign_ext_x)*2^64)%2^64
 *      =y_h*x*2^32 + x*y_l + y_l*(sign_ext_x)*2^32
 *
 * 1 lower 4 bytes of y(y_l) -> %esi
 * 2 x -> %eax
 * 3 copy x to %edx
 * 4 x >> 31 -> %edx(sign extend x)
 * 5 higher 4 bytes of y(y_h) -> %ecx
 * 6 %eax * %ecx -> %ecx(= x*y_h)
 * 7 %edx -> %ebx
 * 8 %esi * %ebx -> %ebx(=y_l*(sign_ext_x))
 * 9 %ecx + %ebx -> %ecx
 * 10 [%edx][%eax]<--64-bit multiply: %esi * %eax ->
 * 11 add (x*y_h+y_l*(sign_ext_x))*2^32
 * 12 put address that dest point to into %ecx
 * 13 put lower bits of product into *dest
 * 14 put higher bits of product into *dest
 */
