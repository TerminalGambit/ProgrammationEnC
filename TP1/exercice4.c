#include <stdio.h>

/* Ecrivez un programme qui affiche les nombres de 1 à 100 à raison de 10 par lignes. 
Les nomnres devront alignés correctement*/

void question1(void) {
    int i;
    for (i = 1; i <= 100; i++) {
        printf("%4d ", i);
        if (i % 10 == 0) {
            printf("\n");
        }
    }

}

int main(void) {
    question1();
    return 0;
}
