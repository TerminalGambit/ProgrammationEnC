/* Partie i : Préparation du répertoire
1. Dans le répertoire tp5, veillez créer un nouveau repertoire exercice1/. Créez un fichier main.c se contetant
d’afficher « Hello World ! » et un fichier Makefile comme vue dans le cours 5. Une fois que tout marche bien
passez à la question suivante. */


/* 3. Utilisez les deux fonctions précédentes dans votre fichier main.c. */

/* Contenu de allocation.c :
#include <stdio.h>
#include <stdlib.h>

static int NB_ALLOC = 0;

void *mon_malloc(size_t size) {
    NB_ALLOC++;
    return malloc(size);
}

void mon_free(void *ptr) {
    NB_ALLOC--;
    free(ptr);
}

Contenu de allocation.h :
#include <stdio.h>
#include <stdlib.h>

void *mon_malloc(size_t size);
void mon_free(void *ptr);

*/

#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

int main(void) {
    printf("Hello World!");
    int *ptr = mon_malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    mon_free(ptr);
    return 0;
}
