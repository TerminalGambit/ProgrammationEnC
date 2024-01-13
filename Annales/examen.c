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

int main(void) {
    print("Question 1\n");
    test_q1();
    return 0;
}