/**********************************************************************
*                  Projet de fin d'Ann�e                              *
*                  ---------------------                              *
* Groupes N� 4                                                        *
* ---------                                                           *
* Membres du Groupes:                                                 *
* ------------------                                                  *
*                                                                     *
* ADAMAH Kouevi Joseph      LF - IS                                   *
* MAZA Kossivi Renaud       LF - IS                                   *
* SOGNIKIN Kossi Triomphe   LF - IS                                   *
*                                                                     *
* Charg�e du cour : Dr AMOUZOU Gr�ce Dorcas Akp�n� et Dr AKAKPO       *
*                                                                     *
* Description: Ce projet est un projet de fin d'ann�e qui nous a �t�  *
* donn� par nos enseignants pour mettre en pratique tout ce que nous  *
* avions apris dans l'ann�e. Ce projet met accent surtous sur les     *
* listes chain�es. En effet dans cette projet nous allons d�finir     *
* une liste chain�e puis la manipuler gracer � certaines fonctions    *
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
    //il faut que l' utilisateur construise la liste avant toute op�ration
    printf("\nIl est imp�ratif que contruisez une liste pour pouvoir continuer les manipulation et pour cela , ");
    construction_liste_depart(&head);
    printf("\nDans la suite de ce programme ,pour effectuer une op�ration ,il suffira juste de choisir le num�ro affecte a l' op�ration ");
    do
    {
        system("cls");
        menu();
        printf("\n\t\tQuelle op�ration voulez - vous effctuer ? \n");
        printf("\n\t\tReponse : ");
        scanf("%d",&operation);
        switch (operation)
        {
        case 1 :
            system("cls");
            ajout_Debut(&head);
            printf("\nL' op�ration d'ajout  en d�but de liste   a �t� fait avec succ�s\n");
            system("pause");
            break;

        case 2 :
            system("cls");
            ajout_Fin(&head);
            printf("\nL' op�ration d'ajout  en fin de liste  a  �t� fait avec succ�s\n");
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
            printf("\nVeuillez lire attentivement la consignes de  manipulation  et entrer un num�ro valide.\n");
            system("pause");
            break;

        }
    }
    while(operation!=4);
    return 0;
}
