#include <stdio.h>
#include <stdlib.h>

/* 
Dans cet exercice, on conserve le type cellule de l'exercice précédent, mais cette fois-ci, une liste sera une structure 
contenant un unique champs 'premier' pointant  vers la première cellule de la liste.

La différence avec l'exercice précédent est qu'ici, l'objet L ne changera pas (même si la mémoire à laquelle il pointe évoluera au fil du temps).
Si les deux structures sont proches, l'usage va être assez différent car dans cet exercice la récursion est interdite.

On pourra créer une liste de la façon suivante.
liste L = nouvelle_liste();
ajout_debut(&L, 20);
ajout_debut(&L, 1);
ajout_debut(&L, 17);
*/

/* Partie I : création des types*/

/* 1. Créez ainsi un type liste contenant un champs de type cellule* */

typedef struct cellule_t {
    int contenu;
    struct cellule_t *suivant;
} cellule;

typedef struct liste_t {
    cellule *premier;
} liste;

/* 2. Ecrire les 5 fonctions suivantes et testez les proprement. */

/* (a) void nouvelle_liste() */

liste nouvelle_liste(void) {
    liste L;
    L.premier = NULL;
    return L;
}

/* (b) void liberer_liste(liste L) */

void liberer_liste(liste L) {
    free(L.premier);
}

/* (c) int est_vide(liste L) */

int est_vide(liste L) {
    return L.premier == NULL;
}

/* (d) void ajout_debut(int x, liste *L) */

void ajout_debut(int x, liste *L) {
    cellule *c = malloc(sizeof(cellule));
    c->contenu = x;
    c->suivant = L->premier;
    L->premier = c;
}

/* (e) void afficher_liste(liste L) */

void afficher_liste(liste L) {
    cellule *c = L.premier;
    while (c != NULL) {
        printf("%d ", c->contenu);
        c = c->suivant;
    }
    printf("\n");
}

void test_partie_1(void) {
    liste L = nouvelle_liste();
    printf("La liste est vide : %d\n", est_vide(L));
    ajout_debut(20, &L);
    ajout_debut(1, &L);
    ajout_debut(17, &L);
    afficher_liste(L);
    printf("La liste est vide : %d\n", est_vide(L));
    liberer_liste(L);
}

int main(void) {
    test_partie_1();
    return 0;
}
