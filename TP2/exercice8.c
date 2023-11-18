#include <stdio.h>

/* 1. Écrivez une fonction void remplir_chiffre (char chaine []) qui remplit une chaîne de taille suffisante pour qu'elle soit égale à "0123.,ABCD.YZ". 
Cette fonction permettra d'avoir un tableau contenant tous les chiffres nécessaire à l'utilisation de bases inférieures à 36. */

void remplir_chiffre(char chaine[]) {
    int i;
    for (i = 0; i < 10; i++) {
        chaine[i] = i + '0';
    }
    for (i = 0; i < 26; i++) {
        chaine[i + 10] = i + 'A';
    }
    chaine[36] = '\0';
}

void question1(void) {
    char chaine[37];
    remplir_chiffre(chaine);
    printf("%s\n", chaine);
}

/* 2. Ecrivez uen fonction int lire_base(char chaine[], int base) généralisant la fonction lire_binaire mais par une base quelconque (jusqu'à 36). */

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

unsigned int lire_base(char chaine[], int base) {
    unsigned int n = 0;
    int i = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] >= '0' && chaine[i] <= '9') {
            n = n * base + chaine[i] - '0';
        } else if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            n = n * base + chaine[i] - 'A' + 10;
        } else if (chaine[i] != ' ') {
            return -1;
        }
        i++;
    }
    return n;
}

void question2(void) {
    printf("%d\n", lire_base("1111 1111", 2)); /* 255 */
    printf("%d\n", lire_base("1111 1111", 10)); /* 11111111 */
    printf("%d\n", lire_base("1111 1111", 16)); /* 11111111 */
    printf("%d\n", lire_base("1111 1111", 36)); /* 11111111 */
}

/* 3. Ecrivez une fonction void afficher_base(int n, int base) généralisant la fonction afficher_binaire mais là aussi pour une base quelconque (jusqu'à 36). */

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

void afficher_base(int n, int base) {
    int taille = sizeof(int) * 8;
    int tab[sizeof(int) * 8];
    int flag = 0;
    int i;
    
    for (i = 0; i < taille; i++) {
        tab[i] = n % base;
        n = n / base;
    }
    
    for (i = taille - 1; i >= 0; i--) {
        if (tab[i] != 0) {
            flag = 1;
        }
        if (flag) {
            if (i < taille - 1 && i % 4 == 3) {
                printf(" ");
            }
            if (tab[i] >= 0 && tab[i] <= 9) {
                printf("%d", tab[i]);
            } else {
                printf("%c", tab[i] - 10 + 'A');
            }
        }
    }

    if (!flag) {
        printf("0");
    }
    
    printf("\n");
}

void question3(void) {
    afficher_base(10, 2);
    afficher_base(10, 10);
    afficher_base(10, 16);
    afficher_base(10, 36);
}

int main(void) {
    question1();
    printf("\n");
    question2();
    printf("\n");
    question3();
    return 0;
}
