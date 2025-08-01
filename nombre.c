#include <stdio.h>
#include <stdlib.h>
#include "nombre.h"

int EntrerNombre() // Sera utiliser pour tout entrer d'ajout
{
    int nombre, ControleNombre;
    printf("\nVeuillez entrer le nombre à ajouter : ");
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
void SupprimerTout(Liste** tete)
{
    Liste *parcour = *tete;
    Liste *precedent;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide \n");
    }
    else
    {
        while(parcour != NULL )
        {
            precedent = parcour;
            parcour = parcour->suivant;
            free(precedent);
        }
        (*tete) = NULL;
        printf("\nSupprimer avec succès \n");
    }
}
int longueurListe(Liste* tete)
{
    Liste *parcour; // Pour parcourir la liste
    parcour = tete; // initialisation
    int longeur; // Pour stocker la longueur à retourner par la fonction(Longueur de la liste)
    longeur = 0; // Initialisaton
    while(parcour != NULL )
    {
        longeur++; // Pour compter la longeur de la liste
        parcour = parcour->suivant;
    }
    return longeur;
}

void AfficherListe(Liste* tete)
{
    Liste *parcour; // Pour parcourir la liste
    parcour = tete;
    int i; //Pour compter les nombre
    i = 1;
    if (parcour == NULL)
    {
        printf("\n\nLa liste est vide pour le moment\n\n ");
    }
    while(parcour != NULL )
    {
        printf("\nNombre %d : %d\n", i, parcour->nombre);
        parcour = parcour->suivant;
        i++;
    }
    printf("\n")
}
// Les fonctions suivantes sont des fonctions qui vont trier la liste en utilisant le trie à bulle
void TrierDecroissant(Liste **tete)
{
     bool DesordreListe = true; // Variable du type bool du trier à bulle
    int echangeur; // Variable pour échanger les valeur
    Liste *parcour; // Pour parcourir la liste
    parcour = *tete;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else if (parcour->suivant == NULL)
    {
        printf("\nIl n'y a qu'un seul élément dans la liste");
    }
    else
    {
        while(DesordreListe)
        {
            DesordreListe = false;
            parcour = *tete;

            while(parcour->suivant != NULL)
            {

                if (parcour->nombre <  parcour->suivant->nombre)
                {
                    echangeur = parcour->nombre;
                    parcour->nombre = parcour->suivant->nombre;
                    parcour->suivant->nombre = echangeur;
                    DesordreListe = true;
                }
                parcour = parcour->suivant;
            }
        }
    }
}

void TrierCroissant(Liste **tete)
{
     bool DesordreListe = true; // Variable du type bool du trier à bulle
    int echangeur;
    Liste *parcour;
    parcour = *tete;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else if (parcour->suivant == NULL)
    {
        printf("\nIl n'y a qu'un seul élément dans la liste");
    }
    else
    {
        while(DesordreListe)
        {
            DesordreListe = false;
            parcour = *tete;

            while(parcour->suivant != NULL)
            {

                if (parcour->nombre >  parcour->suivant->nombre)
                {
                    echangeur = parcour->nombre;
                    parcour->nombre = parcour->suivant->nombre;
                    parcour->suivant->nombre = echangeur;
                    DesordreListe = true;
                }
                parcour = parcour->suivant;
            }
        }
    }
}



