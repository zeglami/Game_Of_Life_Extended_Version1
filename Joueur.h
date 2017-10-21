
#define M 30
typedef struct _Joueur
{
	int Index;
	char Nom[M];
	int Mot_pass;
	struct _Joueur *next;
}Joueur;
void Afficher_list_Joueurs(Joueur*);

// Ajouter_Joueurs_List(mot de passe , Non,Index );
Joueur* Ajouter_Joueurs_List(Joueur* , int , const char*,int );
void Ajouter_Joueurs_Fichier(Joueur** , int , const char*,int);



Joueur* Supprimer_Joueur_lList_ParIndex(Joueur* , int);
void Supprimer_Joueur_Fichier_ParIndex(Joueur** , int);


Joueur* Trier_Par_Ordre_Alphabetique(Joueur* );



void Initialiser_Fichier_Joueur(Joueur* );
Joueur* Initialiser_List_Joueur();

Joueur* Trouver_Joueur(Joueur* ,int);
