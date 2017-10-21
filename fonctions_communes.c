#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fonctions_communes.h"

//dimension du tableau
void dimension_du_tableau(int*n, int*m)
{
	printf("Entrez les dimensions du tapi de jeu:\n");
	do
	{
		printf("Nombre de ligne:");
		scanf("%d",n);
	}
	while(*n<1);
	do
	{
		printf("Nombre de colonnes:");
		scanf("%d",m);
	}
	while(*m<1);
}
//Affichage du tableau
void affiche(int**tab, int n, int m)
{
	int i;
	int j;

	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(tab[i][j]==0)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}
	printf("\n");
}
//duplication de tabeau
void dupliquer_tableau(int**tab1, int**tab2, int n, int m)
{
	int i;
	int j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			tab2[i][j]=tab1[i][j];
		}
	}
}
//Sauvegarder les parties jouees dans un fichier(jeu.txt)
void affiche_fichier_index(int Indexx ,char*nom){

FILE* fichier=fopen("jeu.txt","a");

fprintf(fichier,"L'index du joueur: %d\n-----------------------------------------------------------------------------------------------\n",Indexx);
fputs("\n",fichier);
fclose(fichier);
}
//Sauvegarder les index des joueurs
void affiche_fichier(int**tab, int n, int m,int Indexx ,char*nom)
{
	int i;
	int j;


	FILE* fichier=fopen("jeu.txt","a");

	//fprintf(fichier,"L'index du joueur: %d\n",Indexx);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(tab[i][j]==0)
				fputs("0 ",fichier);
			else
				fputs("1 ",fichier);
		}
		fputs("\n",fichier);
	}
	fputs("\n",fichier);
	fclose(fichier);
}
//Nombre de generation
int nombre_generation()
{
	int n;

	do
	{
		printf("Entrez le nombre de generation:");
		scanf("%d",&n);
	}
	while(n<1);
	return n;
}
//inistialisation et remplissage du tableau(tapi de jeu)
void initialisation_par_zero_un(int **tab, int n, int m)
{
	int i,j,c1,c2,nbr_cel=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			tab[i][j]=0;
		}
	}
	while (nbr_cel<1)
	{
		printf("Entrez le nombre de cellule vivante: ");
		scanf("%d",&nbr_cel);
	}
	for(i=0;i<nbr_cel;i++)
	{
		do
		{
			printf("Entrez les coordonees de la cellule %d: ",i+1);
			scanf("%d%d",&c1,&c2);
		}
		while(c1<1 || c1>n || c2<1 || c2>m || tab[c1-1][c2-1]==1);
		tab[c1-1][c2-1]=1;
	}
	printf("\n");
}
//Comparer deux chaine de caractere
int comparer_deux_chaine(char S1[N1],char S2[N2]){
    int T1,T2,i,c;
	while(S1[T1]!='\0') T1++;
	while(S2[T2]!='\0') T2++;

	if(T1!=T2)
					return 0;

	else
		{
		for(i=0; S1[i]!='\0' && S2[i]!='\0'; i++)
			if(S1[i] != S2[i])
				{
				c = 0;
				break;
				}

		if(c==1)
			{
			return 1;// s1=s2
			}
		else
			return 0;
		}

}

//Fonction pour protger l'espace admin, admin doit saisir son login et son password
int password_admin(){
  int i;
    char ch, name[20];
char pasword[10];
char x;
printf("Entrer login: ");
scanf("%s",name);
printf("\n\nEntrer mot de passe : ");

 for(i=0;i<6;i++)
 {
  ch = getch();
  pasword[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }

 pasword[i] = '\0';

if (strcmp(name, "ensias") == 0 && strcmp(pasword, "ensias") == 0)
 return 1;  //Access granted
else  return 0;


}

//Afficher les differentes parties jouees
void Afficher_parties_joues()
{
FILE* fichier = NULL;
int caractereActuel = 0;
printf("\t\t\t\t\tLes parties jouees:\n\n");
fichier = fopen("jeu.txt", "r");
if (fichier != NULL)
{
do
{
caractereActuel = fgetc(fichier);
printf("%c", caractereActuel);
} while (caractereActuel != EOF);
fclose(fichier);
}
}
//Pour simplifier on a utilise cet fonction pour retourner au meni principal
void retourner_menu(){
    int r;
printf("Taper 0 pour revenir au menu precedent, et tout autre caractere pour sortir .. \n\n\n");
            scanf("%d",&r);
             if(r==0){
                main();
                 }else{exit(1);
             }

}
