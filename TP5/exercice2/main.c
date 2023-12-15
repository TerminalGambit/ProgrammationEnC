/* Même exercice que le précédent. Cette fois-ci, au lieu de simplement compter le nombre d’allocations et de libérations,
on va stocker dans une liste chaînée tous les pointeurs alloués et non encore libérés. On stockera aussi la ligne et le
fichier à laquelle l’allocation a été faite.
Attention, cette exercice est complexe et non guidé. 
C’est à vous de créer les fichiers nécessaires, vos propres bibliothèques, réfléchir à comment utiliser les macro, etc.
Voici, page suivante, un exemple de fichier main.c utilisant notre bibliothèque */

/*
#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

int main(void) {
    int *p;
    int *q;
    int *r;

    p = allocation_malloc(sizeof(int));
    allocation_bilan();

    q = allocation_malloc(sizeof(int));
    r = allocation_malloc(sizeof(int));
    allocation_bilan();

    allocation_free(q);
    allocation_bilan();

    allocation_free(r);
    allocation_bilan();

    allocation_free(p);
    allocation_bilan();

    return 0;
} 

Et voici l’affichage correspondant.
stdin/stdout

0 free/1 malloc
== Début table allocation ==
0x5646423982a0 ligne 11 « main.c »
== Fin table allocation ==

0 free/3 malloc
== Début table allocation ==
0x564642398340 ligne 13 « main.c »
0x5646423982f0 ligne 12 « main.c »
0x5646423982a0 ligne 11 « main.c »
== Fin table allocation ==

1 free/3 malloc
== Début table allocation ==
0x564642398340 ligne 13 « main.c »
0x5646423982a0 ligne 11 « main.c »
== Fin table allocation ==

2 free/3 malloc
== Début table allocation ==
0x5646423982a0 ligne 11 « main.c »
== Fin table allocation ==

3 free/3 malloc
== Début table allocation ==
== Fin table allocation ==
*/

#include <stdio.h>
#include <stdlib.h>
#include "allocation.h"

int main(void) {
    int *p;
    int *q;
    int *r;

    p = allocation_malloc(sizeof(int));
    allocation_bilan();

    q = allocation_malloc(sizeof(int));
    r = allocation_malloc(sizeof(int));
    allocation_bilan();

    allocation_free(q);
    allocation_bilan();

    allocation_free(r);
    allocation_bilan();

    allocation_free(p);
    allocation_bilan();

    return 0;
}
