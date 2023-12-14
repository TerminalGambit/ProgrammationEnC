#include <stdio.h>
#include <stdlib.h>

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

void liberer_liste_allocation(liste_allocation L) {
    cellule_allocation *c = L.premier;
    while (c != NULL) {
        cellule_allocation *suivant = c->suivant;
        free(c);
        c = suivant;
    }
}

int est_vide_allocation(liste_allocation L) {
    return L.premier == NULL;
}

void ajout_debut_allocation(void *ptr, int ligne, char *fichier, liste_allocation *L) {
    cellule_allocation *c = malloc(sizeof(cellule_allocation));
    c->ptr = ptr;
    c->ligne = ligne;
    c->fichier = fichier;
    c->suivant = L->premier;
    L->premier = c;
}

void afficher_liste_allocation(liste_allocation L) {
    cellule_allocation *c = L.premier;
    while (c != NULL) {
        printf("%p ligne %d « %s »\n", c->ptr, c->ligne, c->fichier);
        c = c->suivant;
    }
    printf("\n");
}

/* Définition de la liste chaînée */
liste_allocation liste;

/* Création de allocation_malloc_fonction */
void *allocation_malloc_fonction(size_t taille, int ligne, char *fichier) {
    void *ptr = malloc(taille);
    if (ptr == NULL) {
        printf("Erreur d'allocation mémoire à la ligne %d du fichier %s\n", ligne, fichier);
        exit(1);
    }
    /* ajout à la liste chaînée déjà définie en dehors de la fonction : la taille puis la ligne et puis le fichier. */
    ajout_debut_allocation(ptr, ligne, fichier, &liste);
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
    printf("%ld ligne %d « %s »\n", 0x5646423982a0, 11, "main.c");
    afficher_liste_allocation(nouvelle_liste_allocation());
    printf("== Fin table allocation ==\n\n");
}
/* Création de allocation_free_fonction */

void allocation_free_fonction(void *ptr) {
    free(ptr);
}
