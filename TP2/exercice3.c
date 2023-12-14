#include <stdio.h>

/* Partie 1 : Création des types */

/* Créez un nouveau type enum contenant deux valeurs : entier et decimal. 
Renommer ce nouveau type typage avec typedef. */

/* Exercice 7 : question 1 : Créer un type fraction à partir d'une structure ayant deux champs entiers: numerateur et denominateur. */

typedef struct {
    int numerateur;
    int denominateur;
} fraction;

/* Exercice 7 : question 2 : ajouter un typage rationelle dans l'enum énumerant les typages. Modifier le type nombre en conséquent.*/

typedef enum {
    entier, 
    decimal,
    rationelle
} typage;

/* Créez une union contenant deux champs : ent de type int et dec de typ float. Ce type s'appellera valeur. */

typedef union {
    int ent;
    float dec;
} valeur;

/* Enfin, créez une structure contenant deux champs : le premier de tupe typage et le second de type valeur. 
Le type créé sera dénommé nombre. */

typedef struct {
    typage t;
    valeur v;
} nombre;

/* Ecrire maintenat les cinq fonctions suivantes (on utilisera des switch lorsqu'on testera la valeur du champs typage). 
- nombre nombre_entier(int i)
- nombre nombre_decimal(float f)
- int est_entier(nombre n) Renvoie un booléen
- int est_decimal(nombre n) Renvoie un booléen
- void afficher_nombre(nombre n) 2 chiffres après la virgule si décimal
*/

nombre nombre_entier(int i) {
    nombre n;
    n.t = entier;
    n.v.ent = i;
    return n;
}

void test_nombre_entier(void) {
    nombre n = nombre_entier(5);
    printf("%d\n", n.v.ent);
}

nombre nombre_decimal(float f) {
    nombre n;
    n.t = decimal;
    n.v.dec = f;
    return n;
}

void test_nombre_decimal(void) {
    nombre n = nombre_decimal(5.5);
    printf("%f\n", n.v.dec);
}

int est_entier(nombre n) {
    return n.t == entier;
}

void test_est_entier(void) {
    nombre n1 = nombre_entier(5);
    nombre n2 = nombre_decimal(5.5);
    printf("%d\n", est_entier(n1));
    printf("%d\n", est_entier(n2));
}

int est_decimal(nombre n) {
    return n.t == decimal;
}

void test_est_decimal(void) {
    nombre n1 = nombre_entier(5);
    nombre n2 = nombre_decimal(5.5);
    printf("%d\n", est_decimal(n1));
    printf("%d\n", est_decimal(n2));
}

void afficher_nombre(nombre n) {
    switch (n.t) {
        case entier:
            printf("%d\n", n.v.ent);
            break;
        case decimal:
            printf("%.2f\n", n.v.dec);
            break;
    }
}

void test_afficher_nombre(void) {
    nombre n1 = nombre_entier(5);
    nombre n2 = nombre_decimal(5.5);
    afficher_nombre(n1);
    afficher_nombre(n2);
}

/*
int main(void) {
    test_nombre_entier();
    test_nombre_decimal();
    test_est_entier();
    test_est_decimal();
    test_afficher_nombre();
    return 0;
}
*/

/* Partie 2 : calculs sur les nombres */

/* Création d'une fonction Flottant qui prend en paramètre un nombre et le transforme en flottant. 
Si c'est un flottant, on ne change rien. Si c'est un entier, on le cast en flottant. */

float Flottant(nombre n) {
    float f;
    if (est_entier(n)) {
        f = (float) n.v.ent;
    } else {
        f = n.v.dec;
    }
    return f;
}

/* 1. Ecrire une fonction nombre somme(nombre a, nombre b) calculant la somme de deux nombres.
On part du principe que la somme de deux entiers est un entier, la somme de deux décimaux est un décimal et que la somme d'un entier avec un décimal est un décimal. */

nombre somme(nombre a, nombre b) {
    nombre n;
    if (est_entier(a) && est_entier(b)) {
        n = nombre_entier(a.v.ent + b.v.ent);
    } else if (est_decimal(a) && est_decimal(b)) {
        n = nombre_decimal(a.v.dec + b.v.dec);
    } else {
        n = nombre_decimal(Flottant(a) + Flottant(b));
    }
    return n;
}

void test_somme(void) {
    nombre n1 = nombre_entier(5);
    nombre n2 = nombre_decimal(5.5);
    nombre n3 = nombre_decimal(5.5);
    afficher_nombre(somme(n1, n2));
    afficher_nombre(somme(n2, n3));
    afficher_nombre(somme(n1, n3));
}

/* Ecrire une fonction nombre division(nombre a, nombre b) calculant le quotient de deux nombres. Si les deux nombres sont du typage entier et que a est un multiple de b, 
alors le résultat sera de typage entier; dans tous les autres cas, le typage sera décimal*/

nombre division(nombre a, nombre b) {
    nombre n;
    if (est_entier(a) && est_entier(b) && a.v.ent % b.v.ent == 0) {
        n = nombre_entier(a.v.ent / b.v.ent);
    } else {
        n = nombre_decimal(Flottant(a) / Flottant(b));
    }
    return n;
}

void test_division(void) {
    nombre n1 = nombre_entier(5);
    nombre n2 = nombre_decimal(5.5);
    nombre n3 = nombre_decimal(5.5);
    afficher_nombre(division(n1, n2));
    afficher_nombre(division(n2, n3));
    afficher_nombre(division(n1, n3));
}

/* Ecrire une fonction nombre moyenne(nombre notes[], int taille) calculant la moyenne du tableau. 
On s'assurera que les trois notes "10, 15, 5" renvoie bien une moyenne de typage entier 
et que les cinq notes "10, 5, 15, 12, 9" renvoie une moyenne décimal.*/

nombre moyenne(nombre notes[], int taille) {
    nombre n;
    int i;
    nombre sum = nombre_entier(0);
    for (i = 0; i < taille; i++) {
        sum = somme(notes[i], sum);
    }
    if (est_entier(sum)) {
        n = division(sum, nombre_entier(taille));
    } else {
        n = division(sum, nombre_decimal((float) taille));
    }
    return n;
}

void test_moyenne(void) {
    nombre notes1[3];
    nombre notes2[5];

    notes1[0] = nombre_entier(10);
    notes1[1] = nombre_entier(5);
    notes1[2] = nombre_entier(15);

    notes2[0] = nombre_entier(10);
    notes2[1] = nombre_entier(5); 
    notes2[2] = nombre_entier(15);
    notes2[3] = nombre_entier(12);
    notes2[4] = nombre_entier(9);

    
    afficher_nombre(moyenne(notes1, 3));
    afficher_nombre(moyenne(notes2, 5));
}


int main(void) {
    test_somme();
    printf("\n");
    test_division();
    printf("\n");
    test_moyenne();
    return 0;
}
