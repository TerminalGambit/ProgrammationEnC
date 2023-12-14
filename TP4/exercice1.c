/*
Le but de cet exercice est de réimplémenter la commande nl d'Unix.
Cette commande, comme son nom l'indique, Numérote les Lignes d'un fichier.
Concrètement, il y a deux façons de l'utiliser.

Premièrement via l'entrée standard; par exemple la commande echo -n ”ligne1\nligne2\nligne3\n" | ./nl devra afficher :
1: ligne1
2: ligne2
2: ligne3

Deuxièmement en indiquant en paramètre le nom du fichier : ./nl Makefile affichera ainsi :
1: CC = gcc
2: OPTIONS = -Wall -pedantic -ansi
3: 
4: all : nl
5:
6: \%:\%.c
7:      $(CC) $(OPTIONS) $< -o $@

Si plusieurs fichier sont donnés en paramètre, 
il faudra les afficher les uns à la suite des autres (en continuant à incrémenter les numéros de lignes).
Si un fichier des exercices en paramètre ne peut pas être ouvert, 
il faudra afficher une erreur avant de quitter proprement le programme.
*/

#include <stdio.h>
#include <stdlib.h>

void affichage(FILE *fichier) {
    int c;
    static int i = 1;
    while ((c = fgetc(fichier)) != EOF)
    {
        printf("%4d: ", i);
        while (c != '\n' && c != EOF)
        {
            printf("%c", c);
            c = fgetc(fichier);
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char* argv[]) {
    FILE *fichier;
    int i;
    if (argc == 1) {
        affichage(stdin);
    } else {
        for (i = 1; i < argc; i++) {
            fichier = fopen(argv[i], "r");
            affichage(fichier);
            fclose(fichier);
        }
    }
    return 0;
}
