/**********************************************************************
*                  Projet de fin d'Année                              *
*                  ---------------------                              *
* Groupes N° 4                                                        *
* ---------                                                           *
* Membres du Groupes:                                                 *
* ------------------                                                  *
*                                                                     *
* ADAMAH Kouevi Joseph      LF - IS                                   *
* MAZA Kossivi Renaud       LF - IS                                   *
* SOGNIKIN Kossi Triomphe   LF - IS                                   *
*                                                                     *
* Chargée du cour : Dr AMOUZOU Grâce Dorcas Akpéné et Dr AKAKPO       *
*                                                                     *
* Description: Ce projet est un projet de fin d'année qui nous a été  *
* donné par nos enseignants pour mettre en pratique tout ce que nous  *
* avions apris dans l'année. Ce projet met accent surtous sur les     *
* listes chainées. En effet dans cette projet nous allons définir     *
* une liste chainée puis la manipuler gracer à certaines fonctions    *
* comme AjouterDebut(), Suppreimmer()......                           *
*                                                                     *
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include"nombre.h"

int main()
{
    setlocale(LC_ALL,"");
    Liste* head = NULL;
    //printf("\nWelcome codeur pro");
    int operation;
    printf("\n =============== BIENVENU DANS CE PROGRAMME ==================");
    //il faut que l' utilisateur construise la liste avant toute opération
    printf("\nIl est impératif que contruisez une liste pour pouvoir continuer les manipulation et pour cela , ");
    construction_liste_depart(&head);
    printf("\nDans la suite de ce programme ,pour effectuer une opération ,il suffira juste de choisir le numéro affecte a l' opération ");
    do
    {
        system("cls");
        menu();
        printf("\n\t\tQuelle opération voulez - vous effctuer ? \n");
        printf("\n\t\tReponse : ");
        scanf("%d",&operation);
        switch (operation)
        {
        case 1 :
            system("cls");
            ajout_Debut(&head);
            printf("\nL' opération d'ajout  en début de liste   a été fait avec succès\n");
            system("pause");
            break;

        case 2 :
            system("cls");
            ajout_Fin(&head);
            printf("\nL' opération d'ajout  en fin de liste  a  été fait avec succès\n");
            system("pause");
            break;

        case 3 :
            system("cls");
            ajout_Position(&head);
            system("\npause");
            break;
        case 4:
            system("cls");
            quitter();
            break;

        default:
            system("cls");
            printf("\nVeuillez lire attentivement la consignes de  manipulation  et entrer un numéro valide.\n");
            system("pause");
            break;

        }
    }
    while(operation!=4);
    return 0;
}
