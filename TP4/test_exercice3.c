void test_supprimer(void) {
    liste L = nouvelle_liste();
    ajout_fin(&L, 20);
    ajout_fin(&L, 1);
    ajout_fin(&L, 17);
    supprimer(L, 1); // Remove the element with value 1
    afficher_liste(L);
    liberer_liste(L);
}