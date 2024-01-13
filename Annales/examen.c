#include <stdio.h>

/* 1. Écrire une fonction nombre_chiffres qui prend en argument une chaîne de caractères et renvoie le nombre de
caractères correspondant à des chiffres. Par exemple nombre_chiffres("abc 45+") renverra 2. */

int nombre_chiffres(char *chaine) {
    int i = 0;
    int nb_chiffres = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] >= '0' && chaine[i] <= '9') {
            nb_chiffres++;
        }
        i++;
    }
    return nb_chiffres;
}

void test_q1(void) {
    char *chaine = "abc 45+";
    printf("Il y a %d chiffres dans la chaine %s\n", nombre_chiffres(chaine), chaine);
}

/* 2. Écrire une procèdure fusion qui prend en argument un entier n et trois tableaux, t1, t2 et t3 de taille n et qui
initialise t3 en affectant chaque t3[i] (avec i<n) à la plus grande des valeurs entre t1[i] et t2[i]. En prenant,
par exemple, n=3, t1 = 12 5 13 et t2 = 20 2 13 , alors t3 devra être initialisé à 20 5 13 . */

void fusion(int n, int t1[], int t2[], int t3[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (t1[i] > t2[i]) {
            t3[i] = t1[i];
        } else {
            t3[i] = t2[i];
        }
    }
}

void test_q2(void) {
    int n = 3;
    int i;
    int t1[] = {12, 5, 13};
    int t2[] = {20, 2, 13};
    int t3[] = {0, 0, 0};
    fusion(n, t1, t2, t3);
    printf("t3 = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", t3[i]);
    }
    printf("\n");
}

/* 3. Que fait le code suivant ? On ne vous demande pas de paraphraser. Vous décrirez sa fonction et vous l’illustrerez
par un exemple.

int mystere(char * c) {
    char * oo = c ;
    while ( *(c++) != '\0') ;
    return c - oo - 1 ;
}
*/

/* le code mystere prend en argument une chaine de caractères et renvoie la longueur de cette chaine de caractères. 
son fonctionnement est le suivant : 
    - on initialise un pointeur oo sur le premier caractère de la chaine de caractères
    - on parcourt la chaine de caractères jusqu'à rencontrer le caractère '\0' (fin de chaine)
    - on renvoie la différence entre le pointeur c (qui pointe sur le caractère '\0') et le pointeur oo (qui pointe sur le premier caractère de la chaine)
*/

/* 4. Écrire une fonction echange, qui prend en argument deux pointeurs vers des flottants et qui échange leurs valeurs. Par exemple, si a pointe vers la valeur 3.5 et b pointe vers la valeur 2.0, l’appel de echange(a,b) fera pointer
a vers 2.0 et b vers 3.5.*/

void echange(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void test_q4(void) {
    float a = 3.5;
    float b = 2.0;
    printf("a = %f, b = %f\n", a, b);
    echange(&a, &b);
    printf("a = %f, b = %f\n", a, b);
}

/* 5. Utiliser la fonction echange pour compléter le code suivant. À la fin, les valeurs de x et y doivent être permutées.
Votre code ne doit pas dépasser une ligne.
float x = 2.0;
float y = 3.0;
/* ligne à compléter pour que x vaille 3.0 et y 2.0 */

void test_q5(void) {
    float x = 2.0;
    float y = 3.0;
    printf("x = %f, y = %f\n", x, y);
    echange(&x, &y);
    printf("x = %f, y = %f\n", x, y);
}

/* Problème (13 points)
On cherche dans cet exercice à implémenter une file à partir de deux tableaux. Ce n’est pas forcément optimal, mais
c’est un prétexte pour faire du C. En pratique, la file est séparée en deux tableaux : un premier auquel on ajoute les
éléments et un second, duquel on les retire. Lorsque le second tableau est vide, on transfère le contenu du premier
vers celui-ci.
Exemple. Prenons la file abstraite suivante : → 3 5 7 2 1 → ; elle sera impléméntée en C par les deux
tableaux ci-dessous.
• entree : 7 5 3 ← (notez comme l’ordre est inversée par rapport à la file)
• sortie : 2 1 →
Les cases vides, représentent des valeurs indéfinies. Pour connaître à chaque instant le nombre de cases effectivement
remplies on ajoute deux variables correspondant à des indices.
— indice_entree represente la dernière case remplie du tableau entree (ici, la troisième case d’indice 2).
— indice_sortie represente la première case vide du tableau sortie (ici aussi, la troisième case d’indice 2).
Ainsi, si j’ajoute l’élément 10 (à la fin de la file) et que je supprime l’élément du début de la file (ici, 1), j’obtiens
comme nouvelle file → 10 3 5 7 2 → La file sera alors codée par :
• entree : 7 5 3 10 ← (et indice_entree vaut maintenant 3)
• sortie : 2 → (et indice_sortie vaut maintenant 1)
On vous donne la structure suivante définissant le type file.

typedef struct {
int entree[N] ;
int indice_entree ;
int sortie[N] ;
int indice_sortie ;
} file ;

1. Définir la valeur N à 10 à l’aide d’une macro (en utilisant le préprocesseur).
*/

#define N 10

typedef struct {
int entree[N] ;
int indice_entree ;
int sortie[N] ;
int indice_sortie ;
} file ;

/* 2. Que faut-il écrire comme code pour créer une nouvelle file sur la pile avec les indices correctement initialisés */

file nouvelle_file(void) {
    file f;
    f.indice_entree = 0;
    f.indice_sortie = 0;
    return f;
}

/* Autre solution :

file nouvelle_file(void) {
    file f;
    int i;
    for (i = 0; i < N; i++) {
        f.entree[i] = 0;
        f.sortie[i] = 0;
    }
    f.indice_entree = 0;
    f.indice_sortie = 0;
    return f;
}
Autre façon de faire avec les flèches :

file nouvelle_file(void) {
    file f;
    int i;
    for (i = 0; i < N; i++) {
        f->entree[i] = 0;
        f->sortie[i] = 0;
    }
    f->indice_entree = 0;
    f->indice_sortie = 0;
    return f;
}

*/

/* 3. Écrire une fonction est_vide qui prend une file en paramètre et renvoie un booléean (c’est-à-dire un entier) pour
indiquer si la file est vide. */

int est_vide(file f) {
    return f.indice_entree == f.indice_sortie;
}

/* 4. Écrire une fonction ajout qui prend une file en paramètre (et non un pointeur) et un entier x et renvoie une
nouvelle file à laquelle on a ajouté l’entier x. Si la tableau entree est déjà complet, la fonction renverra NULL. */

file ajout(file f, int x) {
    if (f.indice_entree == N) {
        return f;
    }
    f.entree[f.indice_entree] = x;
    f.indice_entree++;
    return f;
}

int main(void) {
    printf("Question 1\n");
    test_q1();
    printf("\nQuestion 2\n");
    test_q2();
    printf("\nQuestion 4\n");
    test_q4();
    return 0;
}