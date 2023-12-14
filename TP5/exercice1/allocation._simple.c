/* Partie ii : Écriture de la bibliothèque
On veut s’assurer que notre gestion de la mémoire est correcte. Une première stratégie revient à définir une
variable statique NB_ALLOC initialisée à 0. On définira catte variable en dehors de toute fonction.
Lorsqu’une allocation est faite, on incrémente cette variable. On la décremente lors de l’appel de free. Pour le faire
automatiquement sans se soucier de NB_ALLOC, on utilisera dans notre code principal les fonctions mon_malloc
et mon_free à la place des fonctions malloc et free.
2. Dans un fichier allocation_simple.c écrire les deux fonctions suivantes. 
Ces fonctions se contenteront d’appeler les fonctions correspondantes de la bibliothèque stdlib.h en gérant la variable statique NB_ALLOC.
(a) void *mon_malloc(size_t size)
(b) void mon_free(void *ptr)*/

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
