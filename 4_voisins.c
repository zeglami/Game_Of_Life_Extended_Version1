#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "4_voisins.h"
//saisir es regles de naissances d'une celllule morte a 4 voisinages et on les stocke dans B_N
void saisir_regles_naissances_4_voisins(int B_N[5])
{
	int i;
	for(i=0;i<5;i++)
	{
		do
		{
			printf("\nUne cellule morte ayant %d voisins Une cellule morte ayant %d voisins,la prochaine generation sera MORTE=0 ou VIVANTE=1 :\t",i);
			scanf("%d",&B_N[i]);
		}
		while(B_N[i]!=0 && B_N[i]!=1);
	}
	printf("\n");
}




//saisir es regles de naissances d'une celllule vivantes a 4 voisinages et on les stocke dans B_N

void saisir_regles_survies_4_voisins(int S_N[5])
{
	int i;

	for(i=0;i<5;i++)
	{
		do
		{
		printf("\nUne cellule vivante ayant %d voisins Une cellule morte ayant %d voisins,la prochaine generation sera MORTE=0 ou VIVANTE=1 :\t",i);
		scanf("%d",&S_N[i]);
		}
		while(S_N[i]!=0 && S_N[i]!=1);
	}
	printf("\n");
}




//Nombre de voisinage
int nb_voisins_4_voisins(int**tab, int i, int j, int n, int m)
{
	int nb_voisins=0;

	if (i-1>=0 && tab[i-1][j]==1)
		nb_voisins ++;
	if (j-1>=0 && tab[i][j-1]==1)
		nb_voisins++;
	if (j+1<m && tab[i][j+1]==1)
		nb_voisins++;
	if (i+1<n && tab[i+1][j]==1)
		nb_voisins++;

	return nb_voisins;
}




//Generation en appliquant les reges saisis

void generation_suivante_4_voisins(int**tab1, int**tab2, int n, int m, int B_N[5], int S_N[5])
{
	int i;
	int j;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			int nb_voisins=nb_voisins_4_voisins(tab1,i,j,n,m);
			if (tab1[i][j]==1)
			{
				tab2[i][j]=S_N[nb_voisins];
			}
			else
			{
				tab2[i][j]=B_N[nb_voisins];
			}
		}
	}
}



//Affiches des tableaux(jeu)

void jeu_4_voisins(int**tab1, int n, int m, int B_N[5], int S_N[5], int ng ,int Indexx)
{
	int i;
	int**tab2;



	tab2=malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		tab2[i]=malloc(m*sizeof(int));
	}
affiche_fichier_index(Indexx ,"jeu.txt");
	for(i=0;i<ng;i++)
	{
		dupliquer_tableau(tab1,tab2,n,m);
		generation_suivante_4_voisins(tab1,tab2,n,m,B_N,S_N);
		dupliquer_tableau(tab2,tab1,n,m);
		affiche(tab1,n,m);
		affiche_fichier(tab1,n,m,Indexx,"jeu.txt");
	}



	for(i=0;i<n;i++)
	{
		free(tab2[i]);
	}
	free(tab2);
}
