#include <stdio.h>

/* Ecrivez un programme, qui contient la fonction multiple_de_3 : cette fonction renvoie vrai si une chaîne de caractères 
(passée en paramètre) contenant un nombre positif (supposé valide syntaxiquement) est multiple de trois, faux sinon. 
Rappel : Pour qu'un nombre soit multiple de trois, il suffit qie ma somme des chiffres de ce nombre soit multiple de trois. 
12345678 multiplie de 3 ? 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36 er 3 + 6 = 9, donc multiple de 3. 
Attention, votre fonction doit fonctionner mêm si un entier est trop grand pour être réprésenté (en tant qu'entier) en C. */

int multiple_de_3(char chaine[]) {
    int i = 0;
    int somme = 0;
    while (chaine[i] != '\0') {
        somme += chaine[i] - '0';
        i++;
    }
    if (somme % 3 == 0) {
        return 1;
    }
    return 0;
}

void question1(void) {
    printf("%d\n", multiple_de_3("786"));
    printf("%d\n", multiple_de_3("787"));
    printf("%d\n", multiple_de_3("788"));
}

int main(void) {
    question1();
    return 0;
}
