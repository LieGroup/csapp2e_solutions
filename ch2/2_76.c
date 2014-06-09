/* using only the operations +, - and << to perform multiply variable x by
 * constant factor K
 */

int main(void)
{
    int x = 3;
    (x << 4) + x; /* K=17*/
    x - (x << 3); /* K=-7*/
    (x << 6) - (x << 2); /* K=60*/
    (x << 4) - (x << 7); /* k=-112*/
}
