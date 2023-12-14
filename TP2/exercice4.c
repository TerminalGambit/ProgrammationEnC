#include <stdio.h>

/* 1. Ecrivez la fonction int chercher_caractere(char chaine[], char symbole) : 
cette fonction renvoie vrai (sous forme d'entier) si un caractère symbole apparaît dans une chaîne chaine, faux sinon. */

int chercher_caractere(char chaine[], char symbole) {
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] == symbole) {
            return 1;
        }
        i++;
    }
    return 0;
}

void question1(void) {
    char chaine[] = "Bonjour";
    printf("%d\n", chercher_caractere(chaine, 'o')); /* 1 */
    printf("%d\n", chercher_caractere(chaine, 'z')); /* 0 */
}

/* 2. Ecrivez une fonction int egale(char chaine1[], char chaine2[]) testant l'égalité de deux chaînes de caractères. */

int egale(char chaine1[], char chaine2[]) {
    int i = 0;
    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i] != chaine2[i]) {
            return 0;
        }
        i++;
    }
    if (chaine1[i] != '\0' || chaine2[i] != '\0') {
        return 0;
    }
    return 1;
}

void question2(void) {
    char chaine1[] = "Bonjour";
    char chaine2[] = "Bonjour3";
    char chaine3[] = "Bonjour";
    printf("%d\n", egale(chaine1, chaine2)); /* 0 */
    printf("%d\n", egale(chaine1, chaine3)); /* 1 */
    printf("%d\n", egale(chaine2, chaine3)); /* 0 */
}

/* 3. Ecrivez une fonction void miroir(char chaine[]) qui modifie la chaine en argument pour la remplacer par son miroir */

void miroir(char chaine[]) {
    int i = 0;
    int j = 0;
    char tmp;
    while (chaine[i] != '\0') {
        i++;
    }
    i--;
    while (j < i) {
        tmp = chaine[j];
        chaine[j] = chaine[i];
        chaine[i] = tmp;
        j++;
        i--;
    }
}

void question3(void) {
    char chaine[] = "Bonjour";
    miroir(chaine);
    printf("%s\n", chaine);
}

/* 4. Ecrivez la fonction int inclue(char chaine[], char sous_chaine[]) 
qui teste si le second paramètre de la fonction est une sous-chaine du premier. */

int inclue(char chaine[], char sous_chaine[]) {
    int i = 0;
    int j = 0;
    int k;
    while (chaine[i] != '\0') {
        if (chaine[i] == sous_chaine[j]) {
            k = i;
            while (chaine[k] == sous_chaine[j] && chaine[k] != '\0' && sous_chaine[j] != '\0') {
                k++;
                j++;
            }
            if (sous_chaine[j] == '\0') {
                return 1;
            }
            j = 0;
        }
        i++;
    }
    return 0;
}

void question4(void) {
    char chaine1[] = "parapluie";
    char chaine2[] = "pluie";
    char chaine3[] = "coupevent";
    printf("%d\n", inclue(chaine1, chaine2));
    printf("%d\n", inclue(chaine2, chaine3));
    printf("%d\n", inclue(chaine1, chaine3));
}

int main(void) {
    question1();
    printf("\n");
    question2();
    printf("\n");
    question3();
    printf("\n");
    question4();
    printf("\n");
    return 0;
}
