#include <stdio.h>
#include <math.h>

/* Dans cette exercice, on considère les entiers comme une suite de bits. 
Le nombre 13 par exemple, s'écrivant en binaire 1101, a son bit de position 0 égal à 1, son bit de position 1 égal à 0 et ceux de positions 2 et 3 égals à 1 ; 
tous les autres bits nuls. */

/* 1. Ecrivez le code des fonctions suivantes (x est une variable, et pos est la position du bit à modifier). 
Chacune de ses fonctions ne devra contenir qu'une ligne avec un return et une unique formule contenant des opérations sur les bits.
(a) unsigned int get_bit(unsigned int x, int pos) : retourne la valeur du bit a la position pos. */

unsigned int get_bit(unsigned int x, int pos) {
    return (x / (unsigned int)pow(2, pos)) % 2;
}

void questionA(void) {
    printf("%d\n", get_bit(13, 0)); /* 1 */
    printf("%d\n", get_bit(13, 1)); /* 0 */
    printf("%d\n", get_bit(13, 2)); /* 1 */
    printf("%d\n", get_bit(13, 3)); /* 1 */
}

/* (b) unsigned int set_bit(unsigned int x, int pos) : retourne un entier qui est égal à l'entier x pour lequel on a mis le bit à la position 1. */

unsigned int set_bit(unsigned int x, int pos) {
    return x + (unsigned int)pow(2, pos);
}

void questionB(void) {
    printf("%d\n", set_bit(13, 0)); /* 13 */
    printf("%d\n", set_bit(13, 1)); /* 15 */
    printf("%d\n", set_bit(13, 2)); /* 13 */
    printf("%d\n", set_bit(13, 3)); /* 13 */
}

/* (c) unsigned int clear_bit(unsigned int x, int pos) : retourne un entier qui est égal à l'entier x pour lequel on a mis à zéro le bit à la position pos. */

unsigned int clear_bit(unsigned int x, int pos) {
    return x - (unsigned int)pow(2, pos);
}

void questionC(void) {
    printf("%d\n", clear_bit(13, 0)); /* 12 */
    printf("%d\n", clear_bit(13, 1)); /* 13 */
    printf("%d\n", clear_bit(13, 2)); /* 9 */
    printf("%d\n", clear_bit(13, 3)); /* 5 */
}

/* (d) unsigned int toggle_bit(unsigned int x, int pos) : retourne un entier qui est égal à l'entier x pour lequel on a inversé le bit à la position pos. */

unsigned int toggle_bit(unsigned int x, int pos) {
    return x + (unsigned int)pow(2, pos) * (1 - 2 * get_bit(x, pos));
}

void questionD(void) {
    printf("%d\n", toggle_bit(13, 0)); /* 12 */
    printf("%d\n", toggle_bit(13, 1)); /* 15 */
    printf("%d\n", toggle_bit(13, 2)); /* 9 */
    printf("%d\n", toggle_bit(13, 3)); /* 5 */
}

/* (e) unsigned int define_bit(unsigned int x, int pos, int bool) : retourne un entier qui est égal à l'entier x pour lequel on a définit le bit à la position pos suivant la position de bool. */

unsigned int define_bit(unsigned int x, int pos, int bool) {
    return x + (unsigned int)pow(2, pos) * (bool - get_bit(x, pos));
}

void questionE(void) {
    printf("%d\n", define_bit(13, 0, 0)); /* 12 */
    printf("%d\n", define_bit(13, 1, 0)); /* 13 */
    printf("%d\n", define_bit(13, 2, 0)); /* 9 */
    printf("%d\n", define_bit(13, 3, 0)); /* 5 */
    printf("%d\n", define_bit(13, 0, 1)); /* 13 */
    printf("%d\n", define_bit(13, 1, 1)); /* 15 */
    printf("%d\n", define_bit(13, 2, 1)); /* 13 */
    printf("%d\n", define_bit(13, 3, 1)); /* 13 */
}

/* 2. Ecrivez un programme qui effectue le miroir d'un entier non signé sur 32 bits. 
Par exemple si les entiers sont représentés sur 4 bits : 8 s'écrira 1000, son miroir est 0001 = 1*/

unsigned int miroir(unsigned int x) {
    unsigned int y = 0;
    int i;
    for (i = 0; i < 32; i++) {
        y = y * 2 + get_bit(x, i);
    }
    return y;
}

void question2(void) {
    printf("%d\n", miroir(8)); /* 1 */
    printf("%d\n", miroir(13)); /* 11 */
    printf("%d\n", miroir(15)); /* 15 */
    printf("%d\n", miroir(16)); /* 1 */
}

/* 3. Ecrivez un programme qui isole les 10 bits les plus à gauche, les 10 bits les plus à droite et les 12 bits restants au milieu d'un entier non signé. */

unsigned int isolate(unsigned int x) {
    unsigned int y = 0;
    int i;
    for (i = 0; i < 10; i++) {
        y = y * 2 + get_bit(x, i);
    }
    for (i = 22; i < 32; i++) {
        y = y * 2 + get_bit(x, i);
    }
    for (i = 10; i < 22; i++) {
        y = y * 2 + get_bit(x, i);
    }
    return y;
}

void question3(void) {
    printf("%d\n", isolate(0)); /* 0 */
    printf("%d\n", isolate(1)); /* 1024 */
    printf("%d\n", isolate(2)); /* 2048 */
    printf("%d\n", isolate(3)); /* 3072 */
    printf("%d\n", isolate(4)); /* 4096 */
}

int main(void) {
    printf("1.\n");
    questionA();
    printf("\n");
    questionB();
    printf("\n");
    questionC();
    printf("\n");
    questionD();
    printf("\n");
    questionE();
    printf("\n");

    printf("2.\n");
    question2();
    printf("\n");

    printf("3.\n");
    question3();
    return 0;
}
