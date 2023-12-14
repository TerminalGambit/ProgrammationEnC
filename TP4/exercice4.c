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
#include <string.h>

void mywc(int argc, char *argv[]) {
    int i;
    int estBytes = 1;
    int estLines = 1;
    int estWords = 1;
    FILE *fichier;
    int c, nb_lignes = 0, nb_mots = 0, nb_caracteres = 0;
    for (i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            estBytes = 0;
        } 
        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            estLines = 0;
        } 
        if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            estWords = 0;
            printf("Test\n");
        }
    }
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
    if (estBytes == 0 && estLines == 0 && estWords == 0) {
        printf("%d %d %d %s\n", nb_lignes, nb_mots, nb_caracteres, argv[1]);
    } else if (estBytes == 1 && estLines == 1 && estWords == 1) {
        printf("%d %d %d %s\n", nb_lignes, nb_mots, nb_caracteres, argv[1]);
    } else if (estBytes == 0) {
        printf("%d %s\n", nb_caracteres, argv[1]);
    } else if (estLines == 0) {
        printf("%d %s\n", nb_lignes, argv[1]);
    } else if (estWords == 0) {
        printf("%d %s\n", nb_mots, argv[1]);
    } else if (estWords == 0 && estLines == 0) {
        printf("%d %d %s\n", nb_lignes, nb_mots, argv[1]);
    } else if (estWords == 0 && estBytes == 0) {
        printf("%d %d %s\n", nb_caracteres, nb_mots, argv[1]);
    } else if (estLines == 0 && estBytes == 0) {
        printf("%d %d %s\n", nb_caracteres, nb_lignes, argv[1]);
    }
    fclose(fichier);
}

int main(int argc, char *argv[]) {
    mywc(argc, argv);
    return 0;
}
