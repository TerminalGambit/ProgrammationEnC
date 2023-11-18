#include <stdio.h>

/* Ecrivez une fonction pyramide(int n) qui affiche une pyramide de taille n. 
Ecrivez ensuite uen boucle qui demande à l'utilisateur de rentrer une veleur entière et trace la pyramide correspondante. 
On s'arrêtera lorsque l'utilisateur rentrera une valeur invalide.*/

void pyramide(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n-i; j++) {
            printf(" ");
        }
        for (j = 0; j < 2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int lire_entier(void) {
    int n = 0;
    char c;
    int i;
    printf("Entier> ");
    while ((c = getchar()) != '\n') {
        i = c - '0';
        if (i > 9 || i < 0) {
            return -1;
        }
        n = n * 10 + i;
    }
    if (n == 0) {
        return -1;
    }
    return n;
}

int main(void) {
    int n;
    while ((n = lire_entier()) != -1) {
        pyramide(n);
    }
    return 0;
}
