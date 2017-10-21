#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Conway.h"

//Calcul et l'affichge des tableaux
void jeu_conway(int**tab1, int n, int m,int ng,int Indexx)
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
		generation_suivante_Conway(tab1,tab2,n,m);
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

//En utiisant le cas general(8 voisins) on remplie les tabeaux de seris et la mort des cellules
void generation_suivante_Conway(int**tab1, int**tab2, int n, int m)
{
	int i;
	int j;
	int B[9]={0,0,0,1,0,0,0,0,0};
	int S[9]={0,0,1,1,0,0,0,0,0};

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

