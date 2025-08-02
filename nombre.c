#include <stdio.h>
#include <stdlib.h>
#include "nombre.h"

int EntrerNombre() // Sera utiliser pour tout entrer d'ajout
{
    int nombre, ControleNombre;
    // Do while suivant est utiliser pour controler  l'entrer du nombre
    //En effet la fonction scanf retourne 1 si la valeur saisi est entier sinon elle une valeurs différent de 1
    // Aissi on l'a utiliser pour controler l'entrer des nombres pour que le programme de s'arrête pas si
    //l'utilisateur entre un caractère à la place du nombre
    do
    {
        printf("\n\tNombre : ");
        ControleNombre = scanf("%d", &nombre);
        if (ControleNombre != 1)
        {
            printf("\nVous avez saisi un nombre invalide \n\n");
            while (getchar() != '\n'); // Vide le tampon
        }
    }
    while(ControleNombre != 1);
    return nombre;
}

int afficheMenu()
{
    int ControleNombre, choix;
    do
    {
        printf("\n===============================MENU PRINCIPAL======================================\n");
        printf("\n\t1-) Construire la tête de la liste chainée\n");
        printf("\n\t2-) Ajouter une valeur au début de la liste chainée\n");
        printf("\n\t3-) Ajouter une valeur au milieu de la liste chainée\n");
        printf("\n\t4-) Ajouter une valeur à la fin de la liste chainée\n");
        printf("\n\t5-) Afficher les valeur saisie\n");
        printf("\n\t6-) Afficher la longueur de la liste\n");
        printf("\n\t7-) Supprimer une valeur de la liste chainée\n");
        printf("\n\t8-) Modifier une valeur dans la liste chainée\n");
        printf("\n\t9-) Supprimer toute la liste\n");
        printf("\n\t10-) Autres\n");
        printf("\n\t11-) Quitter");
        printf("\n\n Choix : _");
        ControleNombre = scanf("%d", &choix);
        if (ControleNombre != 1)
        {
            printf("\nVous avez saisi un nombre invalide \n\n");
            while (getchar() != '\n'); // Vide le tampon
        }
    }while(ControleNombre != 1);

    return choix;

}

void Construction_liste(Liste* tete, int controle)
{
    int nbSaisie;

    if (controle == 1)
    {
        printf("\nL'initialisation a étè déjà faite\n\n");

    }
    else
    {
        printf("\nEntrez le premier nombre de la liste");
        nbSaisie = EntrerNombre();

        // Réservation d'espace
        tete->data = nbSaisie;
        tete->next = NULL;

        printf("\nOpération réussie !\n\n");
    }
    system("pause");
}

int DemandePosition()
{
    int position, ControlePosition;
    do
    {
        printf("\nVeuillez entrer la position \n\tPosition : ");
        ControlePosition = scanf("%d", &position);
        if (ControlePosition != 1)
        {
            printf("\nVous avez saisi un nombre invallide.\n");
            while(getchar() != '\n');
        }
    }
    while(ControlePosition != 1);
    return position;
}

void AjoutDebut(Liste** tete, int controle)
{
    if (controle != 1)
    {
        printf("\nListe vide ! Construsiez d'abord la liste avec (1) !\n\n");
    }
    else
    {
        Liste* nb = (Liste*)malloc(sizeof(Liste));

        printf("\nEntrez le nombre que vous désirez mettre au debut de la liste : ");
        &nb->data = EntrerNombre();

        Liste* p = *tete;
        // liaison
        nb->next = p;
        *tete = nb;

        printf("\nOpération réussie !\n");
    }
    system("pause");
}

void AjoutMilieu(Liste* tete, int controle)
{
    if (controle != 1)
    {
        printf("\nListe vide ! Construsiez d'abord la liste avec (1) !\n\n");
    }
    else
    {
        int position;
        char reponse[2];
        int i = 1;
        Liste* nb = (Liste*)malloc(sizeof(Liste));
        position = DemandePosition();

        Liste* p = tete;
        Liste* q;

        if (position == 1)
        {
            printf("Vouliez vous ajouter le nombre au debut de la liste ?(O/N) : ");
            scanf("%s", reponse);

            if(strcmp(reponse, "O")== 0 || strcmp(reponse, "o")== 0)
            {
                AjoutDebut(&tete, controle);
            }
            else
            {
                position = DemandePosition();
            }
        }
        else
        {
            printf("\nEntrez le nombre que vous désirez mettre dans la liste : ");
            &nb->data = EntrerNombre();

            while((p != NULL) && (i < position))
            {
                q = p;
                p = p->next;
                i++;
            }
            if (i < position)
            {
                printf("\nPosition inexistant !!\n");
            }
            else
            {
                q->next = nb;
                nb->next = p;
            }
        }
        printf("\nOpération réussie !\n");
    }
    system("pause");
}

void AjoutFin(Liste* tete, int controle)
{
    if (controle != 1)
    {
        printf("\nListe vide ! Construsiez d'abord la liste avec (1) !\n\n");
    }
    else
    {
        Liste* q, *p = tete;
        Liste* nb = (Liste*)malloc(sizeof(Liste));

        printf("\nEntrez le nombre que vous désirez mettre à la fin de la liste");
        &nb->data = EntrerNombre();

        while (p != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = nb;
        nb->next = p;

        printf("\nOpération réussie !\n");
    }
    system("pause");
}


void AfficherListe(Liste* tete, int controle)
{
    if (controle != 1)
    {
        printf("\nListe vide ! Construsiez d'abord la liste avec (1) !\n\n");
        system("pause");
    }
    else
    {
        Liste* p = tete;
        int cpt;
        while (p != NULL)
        {
            cpt += 1;
            printf("\nValeur %d : %d \n", cpt, (*p).data);
            p = p->next;
        }
        system("pause");
    }

}

void longueurListe(Liste* tete, int controle)
{
    if (controle != 1)
    {
        printf("\nListe vide ! Construsiez d'abord la liste avec (1) !\n");
    }
    else
    {
        Liste* p = tete;
        int longueur;

        longueur = 0;
        while(p != NULL)
        {
            longueur += 1;
            p = p->next;
        }
        printf("\nLa longueur de la liste est %d\n", longueur);
    }
    system("pause");

}

