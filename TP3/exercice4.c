#include <stdio.h>
#include <stdlib.h>

/* Dans l'exercice précédent, le tableau était de taille fixe et ne permettait pas d'ajouter plus de note que prévu à l'origine.
Nous allons créer un tableau à la Python dans lequel on peut ajouter et supprimer des éléments à notre guise. */

/* 1. Commencez par créer une structure tableau, contenant trois champs : un pointeur mémoire vers un tableau, 
un entier taille représentant la taille du tableau mémoire et un entier n représentant le nombre de valeurs effectivement stockées. */

typedef struct {
    int *tableau;
    int taille;
    int n;
} tableau;

/* 2. Ecrivez une fonction tableau * nouveau_tableau(int taille) créant un nouveau tableau de taille correspondant mais ne contient pour l'instant aucun élément. */

tableau * nouveau_tableau(int taille) {
    tableau *t = malloc(sizeof(tableau));
    t->tableau = malloc(sizeof(int) * taille);
    t->taille = taille;
    t->n = 0;
    return t;
}

void test_question2(void) {
    tableau *t = nouveau_tableau(10);
    printf("t->taille = %d, t->n = %d\n", t->taille, t->n);
    free(t->tableau);
    free(t);
}

/* 3. Ecrivez la fonction void libérer tableau(tableau *t) libérant la mémoire allouée par le tableau donnée en argument. */

void libérer_tableau(tableau *t) {
    free(t->tableau);
    free(t);
}

void test_question3(void) {
    tableau *t = nouveau_tableau(10);
    printf("t->taille = %d, t->n = %d\n", t->taille, t->n);
    libérer_tableau(t);
}

/* 4. Ecrivez une fonction afficher_tableau(tableau t*) sur le modèle de l'exercice précédent. */

void afficher_tableau(tableau *t) {
    int i;
    printf("Tableau : ");
    for (i = 0; i < t->n; i++) {
        printf("%d ", t->tableau[i]);
    }
    printf("\n");
}

void test_question4(void) {
    tableau *t = nouveau_tableau(10);
    afficher_tableau(t);
    libérer_tableau(t);
}

/* 5. Ecrivez une fonction ajout_simple prenant en argument un pointeur de tableau et un entier valeur et qui ajoute cet entier dans le tableau s'il reste de la place. 
La fonction renverra 0 en cas de succès et -1 en cas d'erreur. */

int ajout_simple(tableau *t, int valeur) {
    if (t->n < t->taille) {
        t->tableau[t->n] = valeur;
        t->n++;
        return 0;
    }
    return -1;
}

void test_question5(void) {
    tableau *t = nouveau_tableau(10);
    int i;
    for (i = 0; i < 3; i++) {
        int value = (i + 1) * 10;
        ajout_simple(t, value);
        afficher_tableau(t);
    }
    
    libérer_tableau(t);
}

/* 6. Ecrivez une fonction void agrandir(tableau *t) qui double la mémoire du tableau t.
Pour cela on affectera au champs mémoire une zone de taille double de la précédente, on copiera les données de l'ancienne vers la nouvelle et on libérera l'ancienne maintenant inutile. 
On s'assurera de garder cohérents les autres champs de notre structure. */

void agrandir(tableau *t) {
    int *tableau = malloc(sizeof(int) * t->taille * 2);
    int i;
    for (i = 0; i < t->n; i++) {
        tableau[i] = t->tableau[i];
    }
    free(t->tableau);
    t->tableau = tableau;
    t->taille *= 2;
}

void test_question6(void) {
    tableau *t = nouveau_tableau(10);
    int value;
    int i;
    printf("La taille du tableau est : %d\n\n", t->taille);
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout_simple(t, value);
        afficher_tableau(t);
    }
    agrandir(t);
    afficher_tableau(t);
    libérer_tableau(t);
    printf("\nLa taille du tableau est : %d\n", t->taille);
}

/* 7. En utilisant les deux fonctions précédentes, 
écrivez une procédure ajout(tableau *t, int valeur) qui ajoute la valeur à la fin du tableau, 
quitte à augmenter la taille de ce dernier*/

void ajout(tableau *t, int valeur) {
    if (t->n == t->taille) {
        agrandir(t);
    }
    ajout_simple(t, valeur);
}

void test_question7(void) {
    tableau *t = nouveau_tableau(10);
    int value;
    int i;
    printf("La taille du tableau est : %d\n\n", t->taille);
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout(t, value);
        afficher_tableau(t);
    }
    libérer_tableau(t);
    printf("\nLa taille du tableau est : %d\n", t->taille);
}

/* Ecrivez une fonction inserer(tableau *t, int i, int valeur) qui ajoute à l'indice i l'entier valeur, 
tous les éléments d'indice supérieur ou égale à i verront leur position être décalée dans le tableau.
La fonction renverra 0 si tout s'est bien passé et -1 si l'indice dépasse le tableau; dans ce cas, ce dernier ne sera pas modifié. */

int inserer(tableau *t, int i, int valeur) {
    if (i > t->n) {
        return -1;
    }
    if (t->n == t->taille) {
        agrandir(t);
    }
    int j;
    for (j = t->n; j > i; j--) {
        t->tableau[j] = t->tableau[j - 1];
    }
    t->tableau[i] = valeur;
    t->n++;
    return 0;
}

void test_question8(void) {
    tableau *t = nouveau_tableau(10);
    int value;
    int i;
    printf("La taille du tableau est : %d\n\n", t->taille);
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout(t, value);
        afficher_tableau(t);
    }
    inserer(t, 5, 100);
    afficher_tableau(t);
    inserer(t, 0, 200);
    afficher_tableau(t);
    inserer(t, 12, 300);
    afficher_tableau(t);
    libérer_tableau(t);
    printf("\nLa taille du tableau est : %d\n", t->taille);
}

/* 9. Ecrivez une fonction int supprimer(tableau *t, int indice, int valeur) qui supprime du tableau l'élément situé à l'indice i, 
tous les éléments d'indice supérieurs ou égale à i verront leur position être décalée dans le tableau. 
La valeur supprimée sera stockée dans le pointeur donné en argument. 
La fonction renverra 0 si tout s'est passé et -1 si l'indice dépasse du tableau; dans ce cas, ce dernier ne sera pas modifié.  */

int supprimer(tableau *t, int indice, int *valeur) {
    if (indice > t->n) {
        return -1;
    }
    *valeur = t->tableau[indice];
    int i;
    for (i = indice; i < t->n - 1; i++) {
        t->tableau[i] = t->tableau[i + 1];
    }
    t->n--;
    return 0;
}

void test_question9(void) {
    tableau *t = nouveau_tableau(10);
    int value;
    int i;
    printf("La taille du tableau est : %d\n\n", t->taille);
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout(t, value);
        afficher_tableau(t);
    }
    int valeur;
    supprimer(t, 5, &valeur);
    printf("valeur supprimée : %d\n", valeur);
    afficher_tableau(t);
    supprimer(t, 0, &valeur);
    printf("valeur supprimée : %d\n", valeur);
    afficher_tableau(t);
    supprimer(t, 12, &valeur);
    printf("valeur supprimée : %d\n", valeur);
    afficher_tableau(t);
    libérer_tableau(t);
    printf("\nLa taille du tableau est : %d\n", t->taille);
}

/* 
10. Ecrivez une fonction int supprimer_doublon(tableau *t) qui supprime tous les éléments présnents en double dans le tableau. 
Par exemple, à partir d'un tableau contenant : [11, 31, 11, 12, 11, 31], le tableau sera modiié en [11, 31, 12].
On travaillera sur place (sans faire de malloc). 
*/

int supprimer_doublon(tableau *t) {
    int i;
    int j;
    int valeur;
    for (i = 0; i < t->n; i++) {
        valeur = t->tableau[i];
        for (j = i + 1; j < t->n; j++) {
            if (t->tableau[j] == valeur) {
                supprimer(t, j, &valeur);
                j--;
            }
        }
    }
    return 0;
}

void test_question10(void) {
    tableau *t = nouveau_tableau(10);
    int value;
    int i;
    printf("La taille du tableau est : %d\n\n", t->taille);
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout(t, value);
        afficher_tableau(t);
    }
    /* Faire une boucle for pour l'ajout. */
    for (i = 0; i < 10; i++) {
        value = (i + 1) * 10;
        ajout(t, value);
        afficher_tableau(t);
    }
    supprimer_doublon(t);
    afficher_tableau(t);
    libérer_tableau(t);
    printf("\nLa taille du tableau est : %d\n", t->taille);
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
    printf("Question 5: \n");
    test_question5();
    printf("\n");
    printf("Question 6: \n");
    test_question6();
    printf("\n");
    printf("Question 7: \n");
    test_question7();
    printf("\n");
    printf("Question 8: \n");
    test_question8();
    printf("\n");
    printf("Question 9: \n");
    test_question9();
    printf("\n");
    printf("Question 10: \n");
    test_question10();
    return 0;
}
