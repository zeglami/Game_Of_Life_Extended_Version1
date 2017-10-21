#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "8_voisins.h"
//saisir es regles de naissances d'une celllule morte a 8 voisinages et on les stocke dans B

void saisir_regles_naissance_8_voisins(int B[9])
{
	int i;
	for(i=0;i<9;i++)
	{
		do
		{
			printf("\nUne cellule morte ayant %d voisins,la prochaine generation sera MORTE=0 ou VIVANTE=1 :\t",i);
			scanf("%d",&B[i]);
		}
		while(B[i]!=0 && B[i]!=1);
	}
	printf("\n");
}
//saisir es regles de naissances d'une celllule vivante a 8 voisinages et on les stocke dans B

void saisir_regles_survies_8_voisins(int S[9])
{
	int i;

	for(i=0;i<9;i++)
	{
		do
		{
		printf("\nUne cellule vivante ayant %d voisins,la prochaine generation sera MORTE=0 ou VIVANTE=1 :\t",i);
		scanf("%d",&S[i]);
		}
		while(S[i]!=0 && S[i]!=1);
	}
	printf("\n");
}

//generation apres l'application des regles
void generation_suivante_8_voisins(int**tab1, int**tab2, int n, int m, int B[9], int S[9])
{
	int i;
	int j;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			int nb_voisins=nb_voisins_8_voisins(tab1,i,j,n,m);
			if (tab1[i][j]==1)
			{
				tab2[i][j]=S[nb_voisins];
			}
			else
			{
				tab2[i][j]=B[nb_voisins];
			}
		}
	}
}

//Calcul et l'affichage
void jeu_8_voisins(int**tab1, int n, int m, int B[9], int S[9], int ng,int Indexx)
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
	    int Indexx=5;
		dupliquer_tableau(tab1,tab2,n,m);
		generation_suivante_8_voisins(tab1,tab2,n,m,B,S);
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


int nb_voisins_8_voisins(int**tab, int i, int j, int n, int m)
{
	int nb_voisins=0;

	if (i-1>=0 && j-1>=0 && tab[i-1][j-1]==1)
		nb_voisins++;
	if (i-1>=0 && tab[i-1][j]==1)
		nb_voisins ++;
	if (i-1>=0 && j+1<m && tab[i-1][j+1]==1)
		nb_voisins++;
	if (j-1>=0 && tab[i][j-1]==1)
		nb_voisins++;
	if (j+1<m && tab[i][j+1]==1)
		nb_voisins++;
	if (i+1<n && j-1>=0 && tab[i+1][j-1]==1)
		nb_voisins++;
	if (i+1<n && tab[i+1][j]==1)
		nb_voisins++;
	if (i+1<n && j+1<m && tab[i+1][j+1]==1)
		nb_voisins++;

	return nb_voisins;
}
