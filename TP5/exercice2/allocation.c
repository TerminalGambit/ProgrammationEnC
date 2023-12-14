#include <stdio.h>
#include <stdlib.h>

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

/* void supprimer(liste L, int f(int)) supprime de la liste L toutes les valeurs x telles que f(x) soit vrai. */

void supprimer(liste *L, int g(int)) {
    cellule *c = L->premier;
    cellule *prev = NULL;
    while (c != NULL) {
        if (g(c->contenu)) {
            if (prev == NULL) {
                L->premier = c->suivant;
                free(c);
                c = L->premier;
            } else {
                prev->suivant = c->suivant;
                free(c);
                c = prev->suivant;
            }
        } else {
            prev = c;
            c = c->suivant;
        }
    }
}

/* Création de la liste chaînée où on va stocker dans une liste chaînée tous les pointeurs alloués et non encore libérés. 
On stockera aussi la ligne et le fichier à laquelle l’allocation a été faite.*/

typedef struct cellule_allocation_t {
    void *ptr;
    int ligne;
    char *fichier;
    struct cellule_allocation_t *suivant;
} cellule_allocation;

typedef struct liste_allocation_t {
    cellule_allocation *premier;
} liste_allocation;

/* Création de la liste à partir des fonctions définies précédemment. */

liste_allocation nouvelle_liste_allocation(void) {
    liste_allocation L;
    L.premier = NULL;
    return L;
}

/* Création de allocation_malloc_fonction */
void *allocation_malloc_fonction(size_t taille, int ligne, char *fichier) {
    void *ptr = malloc(taille);
    if (ptr == NULL) {
        printf("Erreur d'allocation mémoire à la ligne %d du fichier %s\n", ligne, fichier);
        exit(1);
    }
    return ptr;
}

/* Création de allocation_bilan_fonction */
/* Exemple de output :
0 free/1 malloc
== Début table allocation ==
0x5646423982a0 ligne 11 « main.c »
== Fin table allocation ==
*/
void allocation_bilan_fonction(void) {
    printf("%d free /%d malloc\n", 0, 1);
    printf("== Début table allocation ==\n");
    printf("== Fin table allocation ==\n");
}
/* Création de allocation_free_fonction */

void allocation_free_fonction(void *ptr) {
    free(ptr);
}
