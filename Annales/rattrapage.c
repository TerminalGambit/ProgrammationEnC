/* 1. Ecrire une fonction longueur qui renvoie la longueur d'une chaîne donnée de caractère donnée en paramètre. */

int longueur(char* chaine) {
    int i = 0;
    while (chaine[i] != '\0') {
        i++;
    }
    return i;
}

/* 2. Écrire une fonction indice_plus_longue qui prend en paramètre un tableau non vide de chaîne de caractères
et un entier représentant la longueur de ce tableau et qui renvoie l’indice du tableau contenant la plus longue chaîne. */

int indice_plus_longue(char** tableau, int taille) {
    int i;
    int indice = 0;
    int indice_max = 0;
    for (i = 0; i < taille; i++) {
        if (longueur(tableau[i]) > indice_max) {
            indice_max = longueur(tableau[i]);
            indice = i;
        }
    }
    return indice_max;
}

/* Regarder le corrigé; pas de temps à perdre sur les révisions. */