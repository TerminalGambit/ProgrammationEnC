#include <stdio.h>

int globalc = 3;

int main(void)
{
    int u, d, localc, n;
    localc = 3;
    u = 1;
    d = 2;
    n = 100 * localc + 10 * d + u;
    printf("321 = %i\n", n);
    return 0;
}
