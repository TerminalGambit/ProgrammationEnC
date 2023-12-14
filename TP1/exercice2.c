#include <stdio.h>

/* La fonction question1 affiche "Hello World" */

void question1() {
    printf("Hello World\n");
}

/* La focntion question2 qui affiche sur une ligne les entiers de 65 à 90. */

void question2() {
    int i;
    for (i = 65; i <= 90; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* La fonction question3 qui affiche sur une ligne les caractères dont le code ASCII va de 65 à 90. */

void question3() {
    int i;
    for (i = 65; i <= 90; i++) {
        printf("%c ", i);
    }
    printf("\n");
}

/* La fonction question4 qui crée deux variables, une chaîne s="Pi vaut" et un nombre x=3.1415926 puis affichez les avec printf */

void question4() {
    char s[] = "Pi vaut";
    float x = 3.1415926;
    printf("%s %f\n", s, x);
}

void question5() {
    char c = 'a';
    int i = c + 1;
    printf("Valeur de c en caractère est '%c' et son équivalent décimal vaut %d\n", c, c);
    printf("Valeur de i en caractère est '%c' et son équivalent décimal vaut %d\n", i, i);
}

/* La fonction de qui affiche sur une ligne sur une ligne les caractères de 'a' à 'z' (en minuscule) */

void question6() {
    char c;
    for (c = 'a'; c <= 'z'; c++) {
        printf("%c ", c);
    }
    printf("\n");
}

int main(void) {
    question1();
    question2();
    question3();
    question4();
    question5();
    question6();
    return 0;
}

