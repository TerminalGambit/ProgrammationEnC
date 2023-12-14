#include <stdio.h>
#include <limits.h>

/* 1. Ecrire, avec une boucle (et non en récursif) une fonction en signature "int fibo_naif(int n)" calculant le n^e élément de la suie de Fibonnaci.*/

int fibo_naif(int n) {
    int a = 0;
    int b = 1;
    int c;
    int i;
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int lire_entier(void) {
    int n = 0;
    char c;
    int i;
    printf("Entier> ");
    while ((c = getchar()) != '\n') {
        i = c - '0';
        if (i > 9 || i < 0) {
            return -1;
        }
        n = n * 10 + i;
    }
    if (n == 0) {
        return -1;
    }
    return n;
}

/* 2. Afficher la valeur pour n=50. Qu'observez-vous ? Que s'est-il passé ? */

/* On observe que la valeur affichée est négative. 
Cela est dû au fait que les entiers sont codés sur 4 bits et que la valeur de fibo_naif(50) est supérieure. */

/* 3. Ecrire une fonction de signature "int somme(int a, int b) qui renvoie a+b si possible et -1 en cas de débordement. 
On utilisera la valeur INT_MAX de la bibliotèque limits.h" */

int somme(int a, int b) {
    if (a > INT_MAX - b) {
        return -1;
    } else {
        return a + b;
    }
}

/* 4. Ecrivez une nouvelle fonction fibonnaci semblable à cell de la question 1, mais qui renvoie -1 en cas de débordement d'entier.*/

int fibonnaci(int n) {
    int a = 0;
    int b = 1;
    int c;
    int i;
    if (n == 0) return 0;
    for (i = 1; i < n; i++) {
        c = somme(a, b);
        if (c == -1) {
            return -1;
        }
        a = b;
        b = c;
    }
    return b;
}

/* 5. En utilisant cette fonction, affichez la première valeur de n pour laquelle fibonnaci(n) ne donen pas une valeur correcte. */

int question5(void) {
    int i = 0;
    while (fibonnaci(i) != -1) {
        i++;
    }
    return i;
}


/* Ajoutez à votre programme une boucle qui demande un entier à l'utilisateur et 
affiche soit la valeur associée dans la suite Fibonnaci soit un message d'erreur.*/

int main(void) {
    /*
    int n;
    int i = 0;
    while ((n = lire_entier()) != -1) {
        printf("%d\n", fibo_naif(n));
    }
    while (fibonnaci(i) != -1) {
        printf("%d\n", fibonnaci(i));
        i++;
    }
    */
    int a;
    a = question5();
    printf("%d\n", a);
    return 0;
}
