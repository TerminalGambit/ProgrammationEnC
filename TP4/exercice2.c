#include <stdio.h>
#include <stdlib.h>

/*
Le but de cet exercice est de programmer les fonctions de base permettant de définir et de manipuler des listes chaînées.
Dans cet exercice, on implémentera les listes chaînées pour les utiliser dans les algorithmes récursifs comme on peut 
en rencontrer dans des langages comme OCaml.
*/

/* Partie I : création des types */

/* 1. Commencez par créer une structure cellule contenant deux champs : un champs "contenu" de type entier et 
un champs "suivant" représentant un pointeur vers une autre cellule. */

typedef struct cellule_t {
    int contenu;
    struct cellule_t *suivant;
} cellule;

/* 2. Pour simplifier, les types des fonctions, redéfinissez avec typedef le type "pointeur vers celllule" sous le nom liste_chainee. */

typedef cellule *liste_chainee;

/* Partie II : fonctions d'accès au type */
/* Ecrivez les six fonctions suivantes permettant de manipuler notre nouveau type*/

/* 3. void liberer_lc(liste_chainee L) libérant la mémoire associée à la liste. */

void liberer_lc(liste_chainee L) {
    if (L != NULL) {
        liberer_lc(L->suivant);
        free(L);
    }
}

/* 4. liste_chainee nouvelle_lc() renvoyant une liste chaînée vide. */

liste_chainee nouvelle_lc(void) {
    return NULL;
}

/* 5. int est_vide(liste_chainee L) indiquant si la liste est vide. */

int est_vide(liste_chainee L) {
    return L == NULL;
}

/* 6. int head(liste_chainee L) renvoyant la valeur du premier élément de la liste (ne fonctionne que si L est non vide). */

int head(liste_chainee L) {
    if (est_vide(L)) {
        return 0;
    } else {
        return L->contenu;
    }
}

/* 7. liste_chainee tail(liste_chainee L) renvoyant la suite de la liste (ne fonctionne que si L est non vide). */

liste_chainee tail(liste_chainee L) {
    if (est_vide(L)) {
        return 0;
    } else {
        return L->suivant;
    }
}

/* 8. liste_chainee ajout_lc(int x, liste_chainee L) qui renvoie une nouvelle liste dont le premier élément est x et dont la suite est L. */

liste_chainee ajout_lc(int x, liste_chainee L) {
    liste_chainee new = malloc(sizeof(cellule));
    new->contenu = x;
    new->suivant = L;
    return new;
}

/* Partie III : utilisation de notre type */

/* Dorénavant, on oublie comment sont codées les listes chaînées et on a uniquement le droit d'utiliser les fonctions de la partie II.
Tous les codes devront êtres récursifs :
-- cas de base : la liste est vide
-- cas récursif : la liste se décompose sous la forme head(L) et tail(l).
On pourra créer une liste de la façon suivante.

liste_chainee L = nouvelle_lc();
L = ajout_lc(20, L); head(L) = 20 et tail(L) = NULL
L = ajout_lc(1, L); head(L) = 1 et tail(L) = [20] -> NULL
L = ajout_lc(17, L); head(L) = 17 et tail(L) = [1] -> [20] -> NULL
*/

/* Ecrire et tester les fonctions suivantes : */

/* 9. La fonction affiche_lc qui affiche une liste chaînée. Une fois cette fonction écrite, tester abondamment les fonctions précédentes. 
La liste de l'exemple précédent pourrait être affichée sous la forme : 
[17] -> [1] -> [20] -> NULL */

void affiche_lc(liste_chainee L) {
    if (est_vide(L)) {
        printf("NULL\n");
    } else {
        printf("[%d] -> ", head(L));
        affiche_lc(tail(L));
    }
}

void test_affiche_lc(void) {
    liste_chainee L = nouvelle_lc();
    L = ajout_lc(20, L);
    L = ajout_lc(1, L);
    L = ajout_lc(17, L);
    affiche_lc(L);
    liberer_lc(L);
}

/* 10. la fonction longueur_lc qui affiche le nombre d'éléments de la liste donnée en paramètre. */

int longueur_lc(liste_chainee L) {
    if (est_vide(L)) {
        return 0;
    } else {
        return 1 + longueur_lc(tail(L));
    }
}

void test_longueur_lc(void) {
    liste_chainee L = nouvelle_lc();
    L = ajout_lc(20, L);
    L = ajout_lc(1, L);
    L = ajout_lc(17, L);
    printf("La longueur est %d.\n", longueur_lc(L));
    liberer_lc(L);
}

/* 11. la fonction copie_lc qui renvoie une copie de la liste donnée en paramètre. */

liste_chainee copie_lc(liste_chainee L) {
    if (est_vide(L)) {
        return nouvelle_lc();
    } else {
        return ajout_lc(head(L), copie_lc(tail(L)));
    }
}

void test_copie_lc(void) {
    liste_chainee L = nouvelle_lc();
    L = ajout_lc(20, L);
    L = ajout_lc(1, L);
    L = ajout_lc(17, L);
    affiche_lc(copie_lc(L));
}

int main(void) {
    printf("Test sur la fonction affiche_lc :\n");
    test_affiche_lc();
    printf("Test sur la fonction longueur_lc :\n");
    test_longueur_lc();
    printf("Test sur la fonction copie_lc :\n");
    test_copie_lc();
    return 0;
}
