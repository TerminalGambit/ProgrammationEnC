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

/* 6. Afin de tester le deux questions précédentes, écrire une fonction afficher_bulletin qui affiche le nombre de note actuel sur la taille du tableau suivi des éventuelles notes. 
L'affichage pourra par exemple ressembler à cela :
0/3 []
1/3 [15]
2/3 [15, 9]
3/3 [15, 9, 10]
*/

void afficher_bulletin(bulletin b) {
    int i;
    printf("%d/%d [", b.n, b.taille);
    for (i = 0; i < b.n; i++) {
        printf("%d", b.notes[i]);
        if (i < b.n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void test_question3(void) {
    bulletin b = nouveau(10);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    libérer_mémoire(b);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
}

/* 4. Ecrivez une fonction int ajout_simple(bulletin *b, int note) ajoutant une nouvelle note audit bulletin.
Cette fonction renverra 0 si tout s'est bien passé, -1 si la note n'est pas comprise entre 0 et 20 et -2 si le tableau de notes est plein.
Dans ces deux derniers cas, le bulletin ne sera pas modifié. */

int ajout_simple(bulletin *b, int note) {
    if (note < 0 || note > 20) {
        return -1;
    }
    if (b->n == b->taille) {
        return -2;
    }
    b->notes[b->n] = note;
    b->n++;
    return 0;
}

void test_question4(void) {
    bulletin b = nouveau(10);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple(&b, 10);
    printf("%d\n", ajout_simple(&b, 10));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple(&b, 20);
    printf("%d\n", ajout_simple(&b, 20));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple(&b, 30);
    printf("%d\n", ajout_simple(&b, 30));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple(&b, -10);
    printf("%d\n", ajout_simple(&b, -10));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    libérer_mémoire(b);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
}

/* 5. Essayer d'écrire la fonction précédente en vous passant de pointeur. Est-ce possible ? Pourquoi ? */

int ajout_simple2(bulletin b, int note) {
    if (note < 0 || note > 20) {
        return -1;
    }
    if (b.n == b.taille) {
        return -2;
    }
    b.notes[b.n] = note;
    b.n++;
    return 0;
}

void test_question5(void) {
    bulletin b = nouveau(10);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple2(b, 10);
    printf("%d\n", ajout_simple2(b, 10));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple2(b, 20);
    printf("%d\n", ajout_simple2(b, 20));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple2(b, 30);
    printf("%d\n", ajout_simple2(b, 30));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    ajout_simple2(b, -10);
    printf("%d\n", ajout_simple2(b, -10));
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
    libérer_mémoire(b);
    printf("b.taille = %d, b.n = %d\n", b.taille, b.n);
    afficher_bulletin_notes(b);
    afficher_bulletin(b);
}

/* 7. Ecrivez une fonction ajout qui ajoute une nouvelle note au bulletin. 
Cependant, si le tableau est plein, on remplace la plus mauvaise note du tableau par celle donnée en paramètre (si cette dernière est meilleure, évidemment). 
On utilisera la fonction ajout_simple et on renverra 0 si l'ajout s'est fait sans problème, 
1 si le tableau était plein, la pire note a été remplacée, 
2 si le tableau est plein, la nouvelle note a été ignorée car trop mauvaise et -1 en cas de note non valide. 
Remarque : vous avez le droit de créer des fonctions auxiliaires pour simplifier le code. */

int ajout(bulletin *b, int note) {
    int i;
    int min = 0;
    int min_index = 0;
    int ajout_simple_retour;
    if (note < 0 || note > 20) {
        return -1;
    }
    if (b->n == b->taille) {
        for (i = 0; i < b->n; i++) {
            if (b->notes[i] < min) {
                min = b->notes[i];
                min_index = i;
            }
        }
        if (note > min) {
            b->notes[min_index] = note;
            return 1;
        }
        return 2;
    }
    ajout_simple_retour = ajout_simple(b, note);
    if (ajout_simple_retour == 0) {
        return 0;
    }
    return -1;
}

void test_question7(void) {
    bulletin b = nouveau(10);
    afficher_bulletin(b);
    ajout(&b, 10);
    afficher_bulletin(b);
    ajout(&b, 20);
    afficher_bulletin(b);
    ajout(&b, 30);
    afficher_bulletin(b);
    ajout(&b, -10);
    afficher_bulletin(b);
    ajout(&b, 15);
    afficher_bulletin(b);
    ajout(&b, 15);
    afficher_bulletin(b);
    ajout(&b, 5);
    afficher_bulletin(b);
    ajout(&b, 25);
    afficher_bulletin(b);
    libérer_mémoire(b);
}

int main(void) {
    printf("Question 2 :\n");
    test_question2();
    printf("\n");
    printf("Question 3 :\n");
    test_question3();
    printf("\n");
    printf("Question 4 :\n");
    test_question4();
    printf("\n");
    printf("Question 5 :\n");
    test_question5();
    printf("\n");
    printf("Question 7 :\n");
    test_question7();
    return 0;
}


