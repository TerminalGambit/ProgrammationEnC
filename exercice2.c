#include <stdio.h>
#include <stdlib.h>

/* 
Dans la suite du TP, on aura besoin de réserver de l'espace mémoire sur le tas avec la fonciton malloc. 
En C, il est indispensable de libérer la mémoire lorsque la variable n'est plus utilisée. 
Pour chacun malloc, vous devez ajouter le free correspondant. 
*/

/* 
1. Ecrivez une fonction longueur calculant la longueur d'une chaîne. 
Testez-la dans une fonction question1.
*/

int longueur(char *chaine) {
    int i = 0;
    while (chaine[i] != '\0') {
        i++;
    }
    return i;
}

void test_question1(void) {
    char *chaine = "Hello World!";
    printf("longueur de %s = %d\n", chaine, longueur(chaine));
}

/* Remarque : Ces fonctions utilisent simplement des pointeurs vers des chaînes de caractères littérales, qui sont stockées en mémoire statique et ne nécessitent pas d'allocation dynamique de mémoire.*/


/*
2. Ecrivez une fonction copie_chaine qui renvoie uen nouvelle chaine allouée sur le tas mais identique à la précédente.
Testez là-aussi votre fonction. 
Prenez l'habitude de libérer dans la mémoire lorsque vous n'utilisez plus la chaîne.
*/

char *copie_chaine(char *chaine) {
    int i = 0;
    char *copie = malloc(sizeof(char) * (longueur(chaine) + 1));
    while (chaine[i] != '\0') {
        copie[i] = chaine[i];
        i++;
    }
    copie[i] = '\0';
    return copie;
}

void test_question2(void) {
    char *chaine = "Hello World!";
    char *copie = copie_chaine(chaine);
    printf("chaine = %s, copie = %s\n", chaine, copie);
    free(copie);
}

/* 
3. Ecrivez une fonction concatener prenant deux chaînes en paramètre et renvoyant une nouvelle chaîne obtenue en concatenant les deux autres.
*/

char *concatener(char *chaine1, char *chaine2) {
    int i = 0;
    int j = 0;
    char *concat = malloc(sizeof(char) * (longueur(chaine1) + longueur(chaine2) + 1));
    while (chaine1[i] != '\0') {
        concat[i] = chaine1[i];
        i++;
    }
    while (chaine2[j] != '\0') {
        concat[i + j] = chaine2[j];
        j++;
    }
    concat[i + j] = '\0';
    return concat;
}

void test_question3(void) {
    char *chaine1 = "Hello";
    char *chaine2 = "World!";
    char *concat = concatener(chaine1, chaine2);
    printf("chaine1 = %s, chaine2 = %s, concat = %s\n", chaine1, chaine2, concat);
    free(concat);
}

int main(void) {
    test_question1();
    printf("\n");
    test_question2();
    printf("\n");
    test_question3();
    return 0;
}
