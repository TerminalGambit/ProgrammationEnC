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
    cellule *c = L.premier;
    while (c != NULL) {
        cellule *suivant = c->suivant;
        free(c);
        c = suivant;
    }
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

/* int longueur(liste L) */

int longueur(liste L) {
    int n = 0;
    cellule *c = L.premier;
    while (c != NULL) {
        n++;
        c = c->suivant;
    }
    return n;
}

void test_longueur(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L); /* 20 1 17 */
    printf("La liste a une longueur de %d\n", longueur(L));
    liberer_liste(L);
}

/* int pop_liste(liste *L, int *x) : supprime le premier élément de la liste et le stocke dans le pointeur x. 
Renvoie -1 en cas d'erreur. */

int pop_liste(liste *L, int *x) {
    cellule *c = L->premier;
    if (est_vide(*L)) {
        return -1;
    }
    *x = c->contenu;
    L->premier = c->suivant;
    free(c);
    return 0;   
}

void test_pop_liste(void) {
    liste L = nouvelle_liste();
    int x;
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L); /* 20 1 17 */
    pop_liste(&L, &x);
    printf("x = %d\n", x);
    afficher_liste(L); /* 1 17 */
    liberer_liste(L);
}

/* Partie III : fonctions plus avancées */

/* 6. liste tableau_vers_liste(int tableau[], int taille) construit une liste à partir d'un tableau. */

liste tableau_vers_liste(int tableau[], int taille) {
    liste L = nouvelle_liste();
    int i;
    for (i = 0; i < taille; i++) {
        ajout_fin(&L, tableau[i]);
    }
    return L;
}

void test_tableau_vers_liste(void) {
    int tableau[] = {20, 1, 17};
    liste L = tableau_vers_liste(tableau, 3);
    afficher_liste(L);
    liberer_liste(L);
}

/* int lire_valeur(liste L, int i, int *x) lit la valeur d'indice i de la liste et la stocke dans le pointeur x. 
Renvoie -1 en cas d'erreur. */

int lire_valeur(liste L, int i, int *x) {
    int n = 0;
    cellule *c = L.premier;
    while (c != NULL) {
        if (n == i) {
            *x = c->contenu;
            return 0;
        }
        n++;
        c = c->suivant;
    }
    return -1;
}

void test_lire_valeur(void) {
    int x;
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L); /* 20 1 17 */
    lire_valeur(L, 1, &x);
    printf("x = %d\n", x);
    liberer_liste(L);
} 

/* 8. int inserer(liste *L, int x, int i). Insère une valeur à l'indice i demandé. Renvoie -1 si l'indice n'est pas valide. */

int inserer(liste *L, int x, int i) {
    int n = 0;
    cellule *c = L->premier;
    cellule *prev = NULL;
    while (c != NULL) {
        if (n == i) {
            cellule *d = malloc(sizeof(cellule));
            d->contenu = x;
            d->suivant = c;
            if (prev == NULL) {
                L->premier = d;
            } else {
                prev->suivant = d;
            }
            return 0;
        }
        n++;
        prev = c;
        c = c->suivant;
    }
    return -1;
}

void test_inserer(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L);
    inserer(&L, 5, 0);
    afficher_liste(L);
    liberer_liste(L);
}

/* int max(liste L, int *x) stocke dans x la plus grande valeur de la liste L. Si la liste renvoie -1.
Sinon, renvoie l'indice de cette valeur. */

int max(liste L, int *x) {
    int n = 0;
    int max = 0;
    int indice = -1;
    cellule *c = L.premier;
    while (c != NULL) {
        if (c->contenu > max) {
            max = c->contenu;
            indice = n;
        }
        n++;
        c = c->suivant;
    }
    *x = max;
    return indice;
}

void test_max(void) {
    liste L = nouvelle_liste();
    liste L1 = nouvelle_liste();
    int x = 0;
    int y = 0;
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L);
    printf("max(L, &x) = %d\n", max(L, &x));
    printf("x = %d\n", x);
    liberer_liste(L);

    afficher_liste(L1);
    printf("max(L, &x) = %d\n", max(L1, &y));
    printf("x = %d\n", y);
    liberer_liste(L1);
}

/* void map(liste L, int f(int)) applique la fonction f à chaque élément de L. */

void map(liste L, int f(int)) {
    cellule *c = L.premier;
    while (c != NULL) {
        c->contenu = f(c->contenu);
        c = c->suivant;
    }
}

int f(int x) {
    return x*x;
}

void test_map(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    afficher_liste(L);
    map(L, f);
    afficher_liste(L);
    liberer_liste(L);
}

/* void supprimer(liste L, int f(int)) supprime de la liste L toutes les valeurs x telles que f(x) soit vrai. */

void supprimer(liste L, int g(int)) {
    cellule *c = L.premier;
    cellule *prev = NULL;
    while (c != NULL) {
        if (g(c->contenu)) {
            if (prev == NULL) {
                L.premier = c->suivant;
            } else {
                prev->suivant = c->suivant;
            }
            free(c);
            c = prev->suivant;
        } else {
            prev = c;
            c = c->suivant;
        }
    }
}

int g(int x) { /* Fonction est_pair*/
    return 1 - (x%2);
}

void test_supprimer(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    supprimer(L, 1);
    afficher_liste(L);
    liberer_liste(L);
}

int main(void) {
    printf("\nTest sur la partie I :\n");
    test_partie_1();
    printf("\nTest sur la fonction ajout_fin :\n");
    test_ajout_fin();
    printf("\nTest sur la fonction longueur :\n");
    test_longueur();
    printf("\nTest sur la fonction pop_liste :\n");
    test_pop_liste();
    printf("\nTest sur la fonction tableau_vers_liste :\n");
    test_tableau_vers_liste();
    printf("\nTest sur la fonction lire_valeur :\n");
    test_lire_valeur();
    printf("\nTest sur la fonction inserer :\n");
    test_inserer();
    printf("\nTest sur la fonction max :\n");
    test_max();
    printf("\nTest sur la fonction map :\n");
    test_map();
    printf("\nTest sur la fonction supprimer :\n");
    test_supprimer();
    return 0;
}
