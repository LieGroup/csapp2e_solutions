/* Arguments: p1 at %ebp+8, p2 at %ebp+12, action at %ebp+16
 * Registers: result in %edx(initialized to -1)
 * The jump targets:
 * 1 .L17: MODE_E
 * 2 movl $17, %edx
 * 3 jmp .L19
 * 4 .L13: MODE_A
 * 5 movl 8(%ebp), %eax
 * 6 movl (%eax), %edx
 * 7 movl 12(%ebp), %ecx
 * 8 movl (%ecx), %eax
 * 9 movl 8(%ebp), %ecx
 * 10 movl %eax, (%ecx)
 * 11 jmp .L19
 * 12 .L14: MODE_B
 * 13 movl 12(%ebp), %edx
 * 14 movl (%edx), %eax
 * 15 movl %eax, %edx
 * 16 movl 8(%ebp), %ecx
 * 17 addl (%ecx), %edx
 * 18 movl 12(%ebp), %eax
 * 19 movl %edx, (%eax)
 * 20 jmp .L19
 * 21 .L15: MODE_C
 * 22 movl 12(%ebp), %edx
 * 23 movl $15, (%edx)
 * 24 movl 8(%ebp), %ecx
 * 25 movl (%ecx), %edx
 * 26 jmp .L19
 * 27 .L16: MODE_D
 * 28 movl 8(%ebp), %edx
 * 29 movl (%edx), %eax
 * 30 movl 12(%ebp), %ecx
 * 31 movl %eax, (%ecx)
 * 32 movl $17, %edx
 * 33 .L19: default
 * 34 movl %edx, %eax Set return value
 */

/* Enumerated type creates set of constants numbered 0 and upward */
typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

int switch3(int *p1, int *p2, mode_t action)
{
    int result = 0;
    switch(action) {
        case MODE_A:
            result = *p1;
            *p1 = *p2;
            break;
        case MODE_B:
            result = *p2 + *p1;
            *p2 = result;
            break;
        case MODE_C:
            *p2 = 15;
            result = *p1;
            break;
        case MODE_D:
            *p2 = *p1;
        case MODE_E:
            result = 17;
        default:
    }
    return result;
}
