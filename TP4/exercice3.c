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

/* Partie II : autres fonctions de base */

/* Ecrire et testez les trois fonctions suivantes. On fera bien attention à la gestion mémoire. */

/* 3. void ajout_fin(liste *L, int x) */

void ajout_fin(liste *L, int x) {
    cellule *c = malloc(sizeof(cellule));
    c->contenu = x;
    c->suivant = NULL;
    if (est_vide(*L)) {
        L->premier = c;
    } else {
        cellule *derniere = L->premier;
        while (derniere->suivant != NULL) {
            derniere = derniere->suivant;
        }
        derniere->suivant = c;
    }
}

void test_ajout_fin(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L); /* 20 1 17 */
    liberer_liste(L);
}

int main(void) {
    printf("\nTest sur la partie I :\n");
    test_partie_1();
    printf("\nTest sur la fonction ajout_fin :\n");
    test_ajout_fin();
    return 0;
}
