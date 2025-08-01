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

