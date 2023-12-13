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

void mywc(FILE *fichier, int *nb_lignes, int *nb_mots, int *nb_caracteres) {
    int c;
    int mot = 0;
    while ((c = fgetc(fichier)) != EOF) {
        if (c == '\n') {
            (*nb_lignes)++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            mot = 0;
        } else if (mot == 0) {
            mot = 1;
            (*nb_mots)++;
        }
        (*nb_caracteres)++;
    }
}

int main(void) {
    int nb_lignes = 0;
    int nb_mots = 0;
    int nb_caracteres = 0;
    mywc(stdin, &nb_lignes, &nb_mots, &nb_caracteres);
    printf("%d %d %d\n", nb_lignes, nb_mots, nb_caracteres);
    return 0;
}