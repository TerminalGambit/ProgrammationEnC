/* Partie i : Préparation du répertoire
1. Dans le répertoire tp5, veillez créer un nouveau repertoire exercice1/. Créez un fichier main.c se contetant
d’afficher « Hello World ! » et un fichier Makefile comme vue dans le cours 5. Une fois que tout marche bien
passez à la question suivante. */


/* 3. Utilisez les deux fonctions précédentes dans votre fichier main.c. */

#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

int main(void) {
    int *ptr = mon_malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    mon_free(ptr);
    return bilan();
}

/* 4. Que se passe-t-il si vous quittez votre fonction main en appelant return bilan();*/