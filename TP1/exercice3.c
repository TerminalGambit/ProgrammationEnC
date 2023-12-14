#include <stdio.h>

/* Ecrire une fonction qui utilise getchar() et qui lit un entier sur la sortie standard et renvoie sa valeur. Si la valeur lue n'est pas un entier, la fonction renverra -1. 
Pour plus de visibilité, on utilisera comme invite de commande la chaîne "entier>". */

int question1(void) {
    int i;
    char c;
    int n = 0;
    printf("entier> ");
    while ((c=getchar()) != '\n' && c!= EOF) {
        i = c - '0';
        if (i > 9 || i < 0) {
            return -1;
        }
        n = n*10 + i;
    }
    return n;
}

/* En utilisant la question précédente, écrire une procédure qui lit un entier en sortie standard et affiche sa parité. 
On traitera le cas où la valeur lue ne correspond pas à un nombre. */

/*De même écrire une fonction moyenne_stdin qui lit des notes sur l'entrée standard et renvoie la moyenne. 
Si uen note n'est pas valide (plus grande que 20), elle sera ignorée. On s'arrête lorsque la valeur lue n'est pas un entier. */


float moyenne_stdin(void) {
    int n = 0;
    int total = 0;
    int i;
    while ((i = question1()) != -1) {
        if (i <= 20) {
            total += i;
            n++;
        }
    }
    if (n == 0) {
        return -1;
    } else {
        return (float) total / n;
    }
}

/* Ecrire une fonction qui prend en paramètre deux entiers, a et b et affiche le résultat de la division euclidienne. 
Par exemple, avec a=25 et b=10, on afffichera "25 = 2*10 + 5". On traitera proprement le cas où b est nul. */

void division_euclidienne(int a, int b) {
    int q = 0;
    int r = a;
    while (r >= b) {
        r -= b;
        q++;
    }
    printf("%d = %d*%d + %d\n", a, q, b, r);
}

/* Même question avec la division décimale. Par exemple avec a=25 et b=10 on affichera "25 = 2.5 * 10".*/

void division_decimale(int a, int b) {
    int q = 0;
    int r = a;
    while (r >= b) {
        r -= b;
        q++;
    }
    printf("%d = %d.%d * %d\n", a, q, r, b);
}

/* Ecrire une fonction affichant le résultat de la division, sous forme d'entier lorsque a est divisible par b et sous forme décimale sinon.
On affichera soit une chaîne de la forme "25/10 = 2.5 (apporchée)" ou "30/10 = 3 (exacte)"*/

void division(int a, int b) {
    int q = 0;
    int r = a;
    while (r >= b) {
        r -= b;
        q++;
    }
    if (r == 0) {
        printf("%d/%d = %d (exacte)\n", a, b, q);
    } else {
        printf("%d/%d = %d.%d (approximée)\n", a, b, q, r);
    }
}

int main(void) {
    /*
    int a;
    a=question1();
    printf("%d\n",a);
    if (a != -1) {
        if (a % 2 == 0) {
            printf("L'entier %d est pair\n", a);
        } else {
            printf("L'entier %d est impair\n", a);
        }
    }
    */
    /*
    float b;
    b=moyenne_stdin();
    printf("%f\n",b);
    */
    int a = 25;
    int b = 10;
    division_euclidienne(a, b);

    division_decimale(a, b);

    division(a, b);
    return 0;
}
