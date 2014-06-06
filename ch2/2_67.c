/* determine if int is 32-bit */
int int_size_is_32_B();
int int_size_is_32_C();

/* for machine with at least 32-bit int */
int int_size_is_32_B()
{
    int beyond_msb = 1 << 31;
    /* shift past the 32th bit */
    beyond_msb <<= 1;
    return !beyond_msb;

}
/* for machine with at least 16-bit int */
int int_size_is_32_C()
{
    /* set most significant bit of 16-bit machine */
    int set_msb = 1 << 15; 

    /* set most significant bit of 32-bit machine */
    int beyond_msb = 1 << 15;
    beyond_msb <<= 15;
    beyond_msb <<= 2;
    return set_msb && !beyond_msb;
}
