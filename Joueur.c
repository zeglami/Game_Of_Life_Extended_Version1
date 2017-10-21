#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Joueur.h"
//Afficher la liste des joueurs
void Afficher_list_Joueurs(Joueur* ListJoueur)
{
	Joueur *C;
	int i = 1;
	if(ListJoueur == NULL)
		printf("La liste des joueurs est vide...");
	else
		for(C = ListJoueur, i = 1; C!= NULL ; C =  C->next, i++)
       {
			printf("Joueur N %d \n",i);
			printf("\tIndex: : %d \n", C->Index);
			printf("\tNom : %s \n", C->Nom);
			printf("\n\n");
		}
    return;
}

//L'ajout  des joueures a la listes
Joueur* Ajouter_Joueurs_List(Joueur *ListJoueur, int Indexx, const char* Name,int password)
{
	Joueur *Element = NULL;
	Joueur *C = NULL;

	Element =  (Joueur*)malloc(sizeof(Joueur));
	if(Element == NULL)
	{
	    printf("Erreur d'allocation .");
	    return(NULL);
	}

    C =  (Joueur*)malloc(sizeof(Joueur));
	if(C == NULL)
	{
	    printf("Erreur d'allocation .");
	    return(NULL);
	}
    C = ListJoueur;

	Element->Index = Indexx;
	strcpy(Element->Nom,Name);
	Element->Mot_pass = password;
	Element->next = NULL;

    if(C == NULL)
        C = Element;
    else
    {
        Element->next = C;
        C = Element;
    }
	return(C);
}

//Supprimer un joueur en sisissant son index
Joueur* Supprimer_Joueur_lList_ParIndex(Joueur* ListJoueur, int Indexx)
{
	Joueur *C = NULL;
	Joueur* Element = NULL;

	if(!ListJoueur)
	{
		printf("\t\tCet index ne correspond a aucun joueur puisque la liste des joueurs est vide ! .");
		return(NULL);
	}

	if(ListJoueur->Index == Indexx)
    {
        Element = ListJoueur;
        ListJoueur = Element->next;
        free(Element);
        printf("\nLe Joueur a ete bien supprime !");
        return(ListJoueur);
    }

    for(C = ListJoueur; C->next != NULL; C = C->next)
        if(C->next->Index == Indexx)
        {
            Element = C->next;
            C->next = Element->next;
            free(Element);
            printf("\n\t\tLe Joueur a ete bien supprime !");
            return(ListJoueur);
        }

    printf("\t\tCet index ne correspond a aucun  Joueur\n .");
    return(ListJoueur);
}


//Trier la liste des joures par orde alphabetique
Joueur* Trier_Par_Ordre_Alphabetique(Joueur* ListJoueur)
{
    	Joueur *C = NULL, *Aide = NULL ;
       	int encore = 0;
    if(!ListJoueur)
			return(ListJoueur);

		C = ListJoueur;
        Aide =  (Joueur*)malloc(sizeof(Joueur));
        if(Aide == NULL)
        {
            printf("Erreur d'allocation.");
            return(NULL);
        }

        do
        {
            encore = 0;
			C = ListJoueur;
			while (C->next != NULL)
	        {
	        	if(strcmp(C->Nom,C->next->Nom) == 1)
	        	{

                    strcpy(Aide->Nom,C->Nom);
                    Aide->Index = C->Index;


                    strcpy(C->Nom,C->next->Nom);
                    C->Index = C->next->Index;

                    strcpy(C->next->Nom,Aide->Nom);
                    C->next->Index = Aide->Index;

                    encore = 1;
                }
	        C = C->next;
	        }
        }while(encore == 1);

	    return(ListJoueur);
}
//I,istialiser la liste des joures a partir du fichier
void Initialiser_Fichier_Joueur(Joueur* ListJoueur)
{
	FILE *ME = NULL;
	Joueur* C = NULL;

    ME = fopen("Joueur.txt","w");
    if(ME == NULL)
	{
        printf("Erreur d'ouverture.");
        return;
	}

    for(C =  ListJoueur; C != NULL; C = C->next)
        fprintf(ME,"%d\t\t%s\t\t%d\t\t\n",C->Index,C->Nom,C->Mot_pass);

    fclose(ME);
	return;
}

//Ajouter les joures u fichier
void Ajouter_Joueurs_Fichier(Joueur** ListJoueur, int Indexx, const char* Name,int password)
{
	FILE *ME = NULL;

    ME = fopen("Joueur.txt","a");
    if(ME == NULL)
	{
        printf("Erreur d'ouverture.");
	 	return;
    }

    *ListJoueur = Ajouter_Joueurs_List(*ListJoueur,Indexx,Name,password);


    fprintf(ME,"%d\t\t%s\t\t%d\t\t\n",Indexx,Name,password);

    printf("\n Votre inscription a ete bien fait avec succes.\n Maintenant  vous pouvez jouer :) \n");

    fclose(ME);
    return;
}


//Supprimer un joueur en saisissant son index
void Supprimer_Joueur_Fichier_ParIndex(Joueur** ListJoueur, int Indexx)
{

    *ListJoueur = Supprimer_Joueur_lList_ParIndex(*ListJoueur,Indexx);


    Initialiser_Fichier_Joueur(*ListJoueur);
    return;
}

//Initialiser la list des joueur
Joueur* Initialiser_List_Joueur()
{
	 Joueur* ListJoueur = NULL;
	 Joueur* Q = NULL;
	 FILE *ME = NULL;


     Q =  (Joueur*)malloc(sizeof(Joueur));
     if(Q == NULL)
     {
        printf("Erreur d'allocation .");
        return(NULL);
     }

	 ME = fopen("Joueur.txt","r");

	 if(ME == NULL)
        return(NULL);

 	 while(!feof(ME))
 	 {
 	   fscanf(ME,"%d\t\t%s\t\t%d\n",&Q->Index,&Q->Nom,&Q->Mot_pass);
 	   ListJoueur = Ajouter_Joueurs_List(ListJoueur,Q->Index,Q->Nom,Q->Mot_pass);
 	 }
	 fclose(ME);

	 return(ListJoueur);
}
//chercher un jour en utilisant son inedex
Joueur* Trouver_Joueur(Joueur* ListJoueur,int Indexx)
{
	Joueur* C = NULL;
	Joueur* p = NULL;

	C = (Joueur*)malloc(sizeof(Joueur));
	if(C == NULL)
    {
        printf("Erreur d'allocation.");
        return(NULL);
    }

	p = (Joueur*)malloc(sizeof(Joueur));
	if(p == NULL)
    {
        printf("Erreur d'allocation.");
        return(NULL);
    }
	if(!ListJoueur)
        return(NULL);


    C = ListJoueur;
	while (C != NULL)
	{
        if(C->Mot_pass == Indexx)
        {
            strcpy(p->Nom,C->Nom);
            p->Index = C->Index;
            p->Mot_pass = C->Mot_pass;
            return(p);




        }
    C = C->next;
    }
	return(NULL);
}
