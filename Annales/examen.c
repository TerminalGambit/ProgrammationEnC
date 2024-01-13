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

int main(void) {
    printf("Question 1\n");
    char chaine[] = "abc 45+";
    printf("%d\n", nombre_chiffres(chaine));
    return 0;
}