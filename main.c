/**********************************************************************/
/*                  Projet de fin d'Ann�e                              *
*                  ---------------------                              *
/* Groupes N�                                                          *
* ---------                                                           *
/* Membres du Groupes:                                                 *
* ------------------                                                  *
*                                                                     *
* ADAMAH Kouevi Joseph      LF - IS                                   *
* MAZA Kossivi Renaud       LF - IS                                   *
* SOGNIKIN Kossi Triomphe   LF - IS                                   *
*                                                                     *
/* Charg�e du cour : Dr AMOUZOU Gr�ce Dorcas Akp�n� et Dr AKAKPO       *
*                                                                     *
/* Description: Ce projet est un projet de fin d'ann�e qui nous a �t�  *
* donn� par nos enseignants pour mettre en pratique tout ce que nous  *
* avions apris dans l'ann�e. Ce projet met accent surtous sur les     *
* listes chain�es. En effet dans cette projet nous allons d�finir     *
* une liste chain�e puis la manipuler gracer � certaines fonctions    *
* comme AjouterDebut(), Suppreimmer()......                           *
                                                                      *
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "nombre.h"

int main()
{
    int controleInit = 0;
    int choix, controle = 0;

    setlocale(LC_ALL,"");
    system("color F1");
    printf("PROGRAMME LISTE CHAINEE");

    // R�servation d'espace pour le premier maillon
    Liste* tete = (Liste*)malloc(sizeof(Liste));

    do
    {
        system("cls");
        // Affichage du menu et choix
        choix = afficheMenu();

        switch(choix)
        {
            case 1:
                system("cls");
                printf("\n===============================INITIALISATION======================================\n");
                Construction_liste(tete, controleInit);
                controleInit = 1; //Controler l'initialisation en s'assurant que �a se fasse en premier et une seule fois
                controle = 1;    //Pour permettre la r�p�tition du menu
                break;

            case 2:
                system("cls");
                printf("\n===============================AJOUT AU DEBUT======================================\n");
                AjoutDebut(&tete, controleInit);
                controle = 1;
                break;

            case 3:
                system("cls");
                printf("\n===============================AJOUT AU MILIEU======================================\n");
                AjoutMilieu(tete, controleInit);
                controle = 1;
                break;

            case 4:
                system("cls");
                printf("\n===============================AJOUT EN FIN======================================\n");
                AjoutFin(tete, controleInit);
                controle = 1;
                break;

            case 5:
                system("cls");
                printf("\n===============================AFFICHAGE======================================\n");
                AfficherListe(tete, controleInit);
                controle = 1;
                break;

            case 6:
                system("cls");
                printf("\n===============================LONGUEUR LISTE======================================\n");
                longueurListe(tete, controleInit);
                controle = 1;
                break;

            case 7:
                system("cls");
                printf("\n===============================SUPPRESSION======================================\n");
                //Supprimer(&tete, controleInit);
                controle = 1;
                break;

            case 8:
                system("cls");
                printf("\n===============================MODIFICATION======================================\n");
                //Modifier(&tete, controleInit);
                controle = 1;
                break;

            case 9:
                system("cls");
                printf("\n===============================SUPRESSION DE LA LISTE======================================\n");
                //SupprimerListe(&tete, controleInit);
                controle = 1;
                controleInit = 0;
                break;

            case 10:
                system("cls");
                printf("\n===============================AUTRES======================================\n");
                //Autre(&tete, controleInit);
                controle = 1;
                break;

            case 11:
                //Quitter(&tete);
                break;

        }
    }while(controle == 1);

    return 0;
}
