#include <stdio.h>

int somme(int n)
{
    int resultat;
    int i;

    resultat = 0;
    for (i = 1; i <= n; i++)
    {
        resultat += 1;
    }
    return resultat;
}

int main(void)
{
    int s;
    s = somme(10);
    printf("1+2+...+9+10 = %d\n", s);
    return 0;
}