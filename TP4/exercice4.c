/* Exercice 4 — Recodons les utilitaires Unix
Écrivez un programme mywc (qui est une version semblable au wc du Shell), qui compte les lignes, 
les mots et les caractères d’un fichier, et écrit les résultats sur la sortie standard. 

Un mot est une suite de caractères quelconques, encadré par un ou plusieurs espaces.
On fera attention d’avoir un comportement similaire au véritable wc. Les fichiers pourront être lus soit depuis l’entrée
standard soit donnés en paramètre. Dans les deux cas l’affichage doit être le même que celui la commande d’origine. On
implémentera aussi les trois options :
1. -c (ou --bytes),
2. -l (ou --lines),
3. -w (ou --words),*/

#include <stdio.h>
#include <stdlib.h>

void mywc(int argc, char *argv[]) {
    int i;
    for (i=0; i<argc; i++) {
        printf("%s", argv[i])
    }
}

int main(int argc, char *argv[]) {
    /*
    int c, nb_lignes = 0, nb_mots = 0, nb_caracteres = 0;
    FILE *fichier;
    fichier = fopen(argv[1], "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    while ((c = fgetc(fichier)) != EOF) {
        nb_caracteres++;
        if (c == '\n') {
            nb_lignes++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            nb_mots++;
        }
    }
    printf("%d %d %d %s\n", nb_lignes, nb_mots, nb_caracteres, argv[1]);
    fclose(fichier);
    */
   mywc(argc, &argv);
    return 0;
}
