#include <stdio.h>

/* 1. Ecrivez une fonction unsigned int lire_binaire(char chaine[]) qui transforme uen chaîne représentant un nombre binaire en entier. 
On autorisera les espaces ("1111 1111" correspond à 255). 
On renverra -1 en cas d'erreur.*/

unsigned int lire_binaire(char chaine[]) {
    unsigned int n = 0;
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] == '1') {
            n = n * 2 + 1;
        } else if (chaine[i] == '0') {
            n = n * 2;
        } else if (chaine[i] != ' ') {
            return -1;
        }
        i++;
    }
    return n;
}

void question1(void) {
    printf("%d\n", lire_binaire("1111 1111")); /* 255 */
}

/* 2. Ecrivez une fonction void afficher_binaire(unsigned int n) qui affiche un entier en binaire. 
On pourra utiliser un tableau de taille suffisante pour contenir tous les bits d'un entier de type int
(astuce : sizeof(int) donne le nombre d'octer utilisé pour le type int). 
Par soucis de lisibilité, on affichera, on affichera les bits par groupe de 4 et on n'affichera pas les zéros inutiles 
à la gauche du nombre.
Exemple : 10 0010 1101 */

void afficher_binaire(unsigned int n) {
    int taille = sizeof(int) * 8;
    int tab[sizeof(int) * 8];
    int flag = 0;
    int i;
    
    for (i = 0; i < taille; i++) {
        tab[i] = n % 2;
        n = n / 2;
    }
    
    for (i = taille - 1; i >= 0; i--) {
        if (tab[i] == 1) {
            flag = 1;
        }
        if (flag) {
            if (i < taille - 1 && i % 4 == 3) {
                printf(" ");
            }
            printf("%d", tab[i]);
        }
    }

    if (!flag) {
        printf("0");
    }
    
    printf("\n");
}

void question2(void) {
    afficher_binaire(10);
    afficher_binaire(187);
}

int main(void) {
    question1();
    printf("\n");
    question2();
    return 0;
}
