#include <stdio.h>
#include <stdlib.h>

/* 1. Ecrivez une fonction void incrementer(int *a) qui incrémente la valeur pointée par a. */

void incrementer(int *a) {
    *a = *a + 1;
    /* (*a)++; */
}

void test_question1(void) {
    int a = 0;
    int *b = malloc(sizeof(int));

    printf("a = %d\n", a);
    incrementer(&a);
    printf("a = %d\n", a);
    
    *b = 0;
    printf("b = %d\n", *b);
    incrementer(b);
    printf("b = %d\n", *b);
    free(b);
}

/* 2. Ecrivez une fonction void echange(int *a, int *b) qui échange deux valeurs pointées par les deux variables.
Si avant la fonction *a vaut 4 et *b vaut 3, après appel, on aura *a qui vaudra 3 et *b qui vaudra 4. */

void echange(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void test_question2(void) {
    int a = 4;
    int b = 3;

    printf("a = %d, b = %d\n", a, b);
    echange(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

/* 3. Ecrivez une fonction int trier(int *a, int *b) qui met la plus petite des valeurs dans a et la plus grande des valeurs dans b. 
On utilisera la fonction précédente. On renverra 0 s'il n'y a pas eu d'échange et 1 s'il y a eu un échange. */

int trier(int *a, int *b) {
    if (*a > *b) {
        echange(a, b);
        return 1;
    }
    return 0;
}

void test_question3(void) {
    int a = 4;
    int b = 3;

    printf("a = %d, b = %d\n", a, b);
    printf("%d\n", trier(&a, &b));
    trier(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

int main(void) {
    test_question1();
    printf("\n");
    test_question2();
    printf("\n");
    test_question3();
    return 0;
}
