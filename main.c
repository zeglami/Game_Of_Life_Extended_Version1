#include <stdio.h>
#include <stdlib.h>
#include "Joueur.h"
#include "fonctions_communes.h"
#include "Conway.h"
#include "4_voisins.h"
#include "8_voisins.h"
int main()
{
     int Pass,r;
char   Name[M];
int choix,Indexx = 0, password = 0,Back;
    FILE *fichier = NULL;
    FILE *fichier1 = NULL;
  Joueur* ListJoueur = NULL;
//  ListJoueur =  (Joueur*)malloc(sizeof(Joueur));
ListJoueur=Initialiser_List_Joueur();
Joueur* jou = (Joueur*)malloc(sizeof(Joueur));
    if(jou == NULL)
    {
        printf("Erreur d'allocation.");
    }

ListJoueur=Initialiser_List_Joueur();

system("COLOR 5F");
printf("\t\t\t\tProjet C\n\n\n\n");
    printf("\t\t\t    ENSIAS - 2016/2017\n\n\n\n");
    printf("\t\t\t\t\t\tRealise par : \n\n");
    printf("\t\t\t\t\t\t\tAbdelhamid ZEGLAMI\n\n");
    printf("\t\t\t\t\t\t\tKhadija THAMINE \n\n");
    printf("\t\t\t\t\t\tEncadre par : \n\n");
    printf("\t\t\t\t\t\t\tMr M.Elhamlaoui\n\n");
    printf("\n\n\n\t\t\t\tJEU DE LA VIE & APPLICATION \n\n\n\n");
    printf("\t  \n\n");
    printf("\t\t1 - Espace administrateur\n\n");
    printf("\t\t2 - Espace joueur\n\n");
 do{
    printf("\nEntrez votre choix:\n");
 scanf("%d",&choix);
    }while(choix<1 || choix>2);
 if(choix==1){
        int v;
       system("COLOR 4F");system("cls");
 v=password_admin();
 if(v==1){
     int choix1;
      system("COLOR 4F");
        system("cls");
         printf("\n\t\t\t\t\t-ESPACE ADMINISTRATEUR\n\n");
        printf("\n\t\t\t1-Afficher la liste des joueurs:\n\n");
        printf("\t\t\t2-Afficher toutes les parties joues:\n\n");
        printf("\t\t\t3-Afficher les parties joues  en donnant son index:\n\n");
        printf("\t\t\t4-Supprimer un joueur en doannat son index:\n\n");
        printf("\t\t\t5-Trier les joueurs par ordre alphabetique:\n\n");
        printf("\t\t\tEntrez vitre choix:\n\t\t\t");
        scanf("%d",&choix1);
        switch(choix1){
            case 1: system("COLOR 5F");system("cls");
                Afficher_list_Joueurs(ListJoueur);
                retourner_menu(); break;
            case 2:system("COLOR 5F");system("cls");
                Afficher_parties_joues();
                retourner_menu(); break;
            case 3: system("COLOR 5F");system("cls");printf("lOADING");
                printf("\n\n   Mazal masaybthach\n\n\n\n\n\n");
                retourner_menu();
                break;
            case 4:  system("COLOR 5F");
        system("cls");system("COLOR 5F");    printf("   Enter l'index du joueur :\n ");
                         scanf("%d",&Indexx);
                         printf("\n\n");
                         Supprimer_Joueur_lList_ParIndex(ListJoueur,Indexx);
                         printf("\n\n");

                retourner_menu(); break;

            case 5:system("COLOR 4F");

        system("cls"); system("COLOR 5F");printf("La liste des joueurs sorted selon l'ordre alphabetique : \n\n");
                         ListJoueur = Trier_Par_Ordre_Alphabetique(ListJoueur);
                         Initialiser_Fichier_Joueur(ListJoueur);
                         Afficher_list_Joueurs(ListJoueur);
                         retourner_menu();
            break;
            default: break;

        }

 }else{
 system("cls");
 printf("Erreur ! Les donnees que vous avez entre sont incorrectes .. \n\n\n");
main();

 }

 }else{


        int choix2; system("COLOR 4F");
        system("cls");
         printf("\n\t\t1-S'inscrire puis jouer:\n\n");
        printf("\t\t2-S'identifier puis jouer:\n\n");
        printf("\t\t3-Jouer sans s'inscrire:\n\n");
        printf("\t\t\tEntrez votre choix:\n\t\t");
        scanf("%d",&choix2);

        switch(choix2){

    case 1:       system("COLOR 4F");
        system("cls");         printf("\t\t\tEntrer votre nom : ");
                         fflush(stdin);
                         scanf("%s",&Name);
                         printf("\n\t\t\tEntrer index : ");
                         scanf("%d",&Indexx);
                         printf("\n\t\t\tEntrer mot de passe : ");
                         scanf("%d",&password);
                         printf("\n");
                         Ajouter_Joueurs_Fichier(&ListJoueur,Indexx,Name,password);

    menu_jeu(Indexx);retourner_menu();

        break;
    case 2:
        system("cls");
        system("COLOR 1F");

char Login[M];
        printf("\n\n\t\tNom : "); fflush(stdin); scanf("%s",&Login);
        printf("\n\n\t\tMot de Passe : "); fflush(stdin); scanf("%d",&Pass);

        jou = Trouver_Joueur(ListJoueur,Pass);

        if(jou != NULL && strcmp (jou->Nom,Login) == 0 && jou->Mot_pass == Pass){
            //system("cls");
            int s;
            int index_jou;
            index_jou=jou->Index;
            printf("\n\n");
            printf("\t\t\t\t\t****Bienvenue Mr.%s *****",jou->Nom);
            printf("\n\n");
            menu_jeu(index_jou);

            retourner_menu();
            /*
            jou = Trouver_Joueur(ListJoueur,Pass);



            */
        }
        else{
             system("cls");
             printf("Erreur ! Les donnees que vous avez entre sont incorrectes .. \n\n\n");
             retourner_menu();

        }




        break;
    case 3: system("cls"); menu_jeu(0);retourner_menu();break;


 }}

    return 0;
}
