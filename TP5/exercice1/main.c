/* Partie i : Préparation du répertoire
1. Dans le répertoire tp5, veillez créer un nouveau repertoire exercice1/. Créez un fichier main.c se contetant
d’afficher « Hello World ! » et un fichier Makefile comme vue dans le cours 5. Une fois que tout marche bien
passez à la question suivante. */


/* 3. Utilisez les deux fonctions précédentes dans votre fichier main.c. */

/* 5. Que se passe-t-il si vous quittez votre fonction main en appelant return bilan();*/
/* Ca execute la fonction bilan. */

/* 6. Ajoutez une option MODE_DEBUG pour choisir à la compilation d’afficher ou non ces messages. */

#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

#ifdef MODE_DEBUG
    #define DEBUG_PRINT(msg) printf("%s\n", msg)
#else
    #define DEBUG_PRINT(msg)
#endif

int main(void) {
    int *ptr = mon_malloc(sizeof(int));
    *ptr = 42;

    DEBUG_PRINT("Debug message: Value is set.");

    printf("Value: %d\n", *ptr);
    mon_free(ptr);
    return bilan();
}
