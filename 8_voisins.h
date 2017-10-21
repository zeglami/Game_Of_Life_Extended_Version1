void saisir_regles_naissance_8_voisins(int B[9]);
void saisir_regles_survies_8_voisins(int S[9]);
int nb_voisins_8_voisins(int**tab, int i, int j, int n, int m);
void generation_suivante_8_voisins(int**tab1, int**tab2, int n, int m, int B[9], int S[9]);
void jeu_8_voisins(int**tab1, int n, int m, int B[9], int S[9], int ng,int Indexx);
//jeu_8_voisins(Tab,longueur,largeur,L[9],D[9],nombre de generation,Indexx);
