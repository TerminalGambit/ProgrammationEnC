#include <stdio.h>
#include <stdlib.h>

/* 
On veut renprésenter dans une structure de relevé de notes des étudiants. 
Cette structure aura trois champs :
- notes : un tableau d'entiers;
- taille : un entier correspondant à la taille du tableau alloué en mémoire;
- n : un entier correspondnat au nombre de notes effectivement entrées dans le tableau.
*/

/* 1. Créez la structure bulletin avec ces trois champs. */

typedef struct {
    int *notes;
    int taille;
    int n;
} bulletin;

/* 2. Ecrivez uen fonction bulletin nouveau(int taille) renvoyant un nouveau bulletin avec un tableau initialisé à la bonne taille et ne contenant pour l'heure aucune note. */

bulletin nouveau(int taille) {
    bulletin b;
    b.notes = malloc(sizeof(int) * taille);
    b.taille = taille;
    b.n = 0;
    return b;
} 

void test_question2(void) {
    bulletin b = nouveau(10);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    free(b.notes);
}

/* 3. Ecrivez une fonction void libérer_mémoire(bulletin b) qui libère la mémoire allouée sur le tas par la fonction précédente.
Une fois cette fonction utilisée, la variable b passée en paramètre ne devra plus être utilisée
(que se passe-t-il si vous le faites quand même ?) */

void libérer_mémoire(bulletin b) {
    free(b.notes);
}

/* Fonction en plus pour afficher le bulletin de notes. */

void afficher_bulletin_notes(bulletin b) {
    int i;
    printf("Notes : ");
    for (i = 0; i < b.n; i++) {
        printf("%d ", b.notes[i]);
    }
    printf("\n");
}

void test_question3(void) {
    bulletin b = nouveau(10);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    libérer_mémoire(b);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
}

/* 4. Ecrivez une fonction void ajout_simple(bulletin *b, itn note) ajoutant une nouvelle note audit bulletin.
Cette fonction renverra 0 si tout s'est bien passé, -1 si la note n'est pas comprise entre 0 et 20 et -2 si le tableau de notes est plein.
Dans ces deux derniers cas, le bulletin ne sera pas modifié. */

void ajout_simple

int main(void) {
    test_question2();
    printf("\n");
    test_question3();
    return 0;
}

