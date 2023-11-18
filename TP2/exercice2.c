#include <stdio.h>

/* Définissez une structure de type struct horaire_struct contenant trois champ de type short pour les heures, minutes et secondes.
Avec typedef, renommez ce type horaire. */

typedef struct horaire_struct {
    short heures;
    short minutes;
    short secondes;
} horaire;

/* 2. Créez une fonction horaire nouvel_horaire(short h, short m, short s) renvoyant un nouvel horaire à partir des trois valeurs données en paramètre. */

horaire nouvel_horaire(short h, short m, short s) {
    horaire h1;
    h1.heures = h;
    h1.minutes = m;
    h1.secondes = s;
    return h1;
}

void question2(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);
    horaire h2 = nouvel_horaire(22, 40, 0);
    printf("%dh %dm %ds\n", h1.heures, h1.minutes, h1.secondes);
    printf("%dh %dm %ds\n", h2.heures, h2.minutes, h2.secondes);
}

/* 3. Créez une fonction void afficher_horaire(horaire h) qui affiche proprement l'horaire sur une ligne de la forme :
12h 23m 15s*/

void afficher_horaire(horaire h){
    printf("%dh %dm %ds\n", h.heures, h.minutes, h.secondes);
}

void question3(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);
    horaire h2 = nouvel_horaire(22, 40, 0);
    afficher_horaire(h1);
    afficher_horaire(h2);
}

/* 4. Ecrivez une fonction horaire ajout(horaire h1, horaire h2) 
qui renvoie un nouvel horaire résultat de la somme des deux paramètres. 
On rappelle que 1h20m35s + 22h40m0s = 0h0m35s*/

horaire ajout(horaire h1, horaire h2) {
    horaire h;
    int total_secondes = h1.secondes + h2.secondes + (h1.minutes + h2.minutes) * 60 + (h1.heures + h2.heures) * 3600;
    h.heures = (total_secondes / 3600) % 24;
    h.minutes = (total_secondes / 60) % 60;
    h.secondes = total_secondes % 60;
    return h;
}

void question4(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);
    horaire h2 = nouvel_horaire(22, 40, 0);
    afficher_horaire(h1);
    afficher_horaire(h2);
    afficher_horaire(ajout(h1, h2));
}
/* 5. Ecrivez une fonction seconde_vers_horaire(int s) qui à partir du nombre de secondes écoulées depuis 0h0m0s renvoie l'horaire correspondant. */

horaire secondes_vers_horaire(int s) {
    horaire h;
    h.heures = (s / 3600) % 24;
    h.minutes = (s / 60) % 60;
    h.secondes = s % 60;
    return h;
}

void question5(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);
    horaire h2 = nouvel_horaire(22, 40, 0);
    afficher_horaire(h1);
    afficher_horaire(h2);
    afficher_horaire(ajout(h1, h2));
    afficher_horaire(secondes_vers_horaire(73235));
}

/* 6. Ecrivez uen fonction int horaire_vers_secondee(horaire) qui faisant l'inverse de la précédente. */

int horaire_vers_secondes(horaire h) {
    int total_secondes = h.secondes + h.minutes * 60 + h.heures * 3600;
    return total_secondes;
}

void question6(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);
    horaire h2 = nouvel_horaire(22, 40, 0);
    afficher_horaire(h1);
    afficher_horaire(h2);
    afficher_horaire(ajout(h1, h2));
    printf("%d\n", horaire_vers_secondes(h1));
}

int main(void) {
    horaire h1 = nouvel_horaire(1, 20, 35);

    question2();
    printf("\n");
    question3();
    printf("\n");
    question4();
    printf("\n");
    question5();
    printf("\n");
    question6();
    printf("\n");

    afficher_horaire(secondes_vers_horaire(horaire_vers_secondes(h1)));
    printf("\n");
    return 0;
}
