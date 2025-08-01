#include <stdio.h>
#include <stdlib.h>
#include "nombre.h"
//Fonction d' affichage  du ménu
void menu()
{
    printf("\n===============  Voici le ménu de manipulation =================");
    printf("\n");
    printf("\n1-) Ajout d ' élément au dédut de la liste.");
    printf("\n");
    printf("\n2-) Ajout d' élément a la fin de la liste.");
    printf("\n");
    printf("\n3-) Ajout  d' élément a une position  quelconque de la liste .");
    printf("\n");
    printf("\n4-)  Affichage de la liste apres une  ou plusieurs opérations. ");
    printf("\n");
    printf("\n5-) Affichage du nombre d' élément   de la liste " );
    printf("\n");
    printf("\n6-) Quitter . ");
    printf("\n");

}
int entrerNombre() // Sera utiliser pour tout entrer d'ajout
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

int demandePosition()
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
//Fonction de construction de la  liste de début
void construction_liste_depart(Liste **L)
{
    Liste *tmp=(Liste*)malloc(sizeof(Liste));
    int val,result ;


    //On vérifie si le reservation  a été fait .
    if (tmp==NULL)
    {
        printf("\nErreur de reservation.");
        return;
    }

    do
    {
        printf("\nVeuillez entrer un entier pour valeur  : ");
        result = scanf("%d", &val);
        if (result != 1)
        {
            printf("\nVous avez saisi un nombre invallide (Entrez un entier).\n");
            while(getchar() != '\n');
        }
    }
    while(result != 1);
    tmp->data=val;
    tmp->next=*L;
    *L=tmp;
    printf("\n");
}

//Fonctions d' ajout d' éléments dans la liste
//Fonction d' ajout au début d' une liste
void ajout_Debut(Liste **L)
{
    Liste *tmp = (Liste*)malloc(sizeof(Liste)); // Alloue un nouveau nœud
    if (tmp == NULL)                            // Vérifie si l'allocation a réussi
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = entrerNombre();  // Demande la valeur à insérer
    tmp->data = val;           // Stocke la valeur dans le nœud
    tmp->next = *L;            // Le nouveau nœud pointe vers l'ancienne tête
    *L = tmp;                  // La tête devient le nouveau nœud
    printf("\n");
}

//Fonction d' ajout à une position donnée d' une liste

void ajout_Position(Liste**L)   // Fonction qui ajoute un élément à une position donnée dans la liste
{
    int pos = demandePosition();    // Demande à l'utilisateur la position où insérer le nouvel élément
    int n = nbreElement(*L);        // Compte le nombre d'éléments actuels dans la liste

    // Vérifie si la position est invalide (inférieure à 1)
    if (pos < 1) {
        printf("Impossible d'effectuer cette opération ");
        return;   // On quitte la fonction car la position est incorrecte
    }

    // Vérifie si la liste est vide
    if (*L == NULL) {
        // Si la liste est vide mais que la position demandée est 1, on peut ajouter au début
        if (pos == 1) {
            printf("\nCet ajout se fait au tout début de la liste.");
            ajout_Debut(L);   // Appelle la fonction qui insère au début
            printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès");
            return;   // On quitte après l’ajout
        }
        else {
            // Si la liste est vide et que la position est > 1, on refuse l'opération
            printf("\nImpossible de faire cette opération, vérifiez la taille de la liste");
            return;
        }
    }
    else {
        // Si la liste n'est pas vide, on continue le traitement
        printf("\nCette opération se fait à la position %d de la liste", pos);

        // Cas : insertion dans une position existante (au milieu)
        if (pos > 1 && pos <= n) {
            // Création du nouveau nœud
            Liste *p, *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));

            // Vérifie si l'allocation mémoire a réussi
            if (nouveau == NULL) {
                printf("\nErreur de réservation.");
                return;
            }

            int val = entrerNombre();  // Demande la valeur à insérer
            tmp = *L;                  // Pointeur temporaire pour parcourir la liste
            nouveau->data = val;       // Affecte la valeur saisie au nouveau nœud

            int k = 1;   // Compteur de position pour atteindre l’endroit où insérer
            while (tmp != NULL && k < pos) {
                k++;
                p = tmp;       // p garde l'adresse du nœud précédent
                tmp = tmp->next;  // tmp avance dans la liste
            }

            // Insère le nouveau nœud entre p et tmp
            p->next = nouveau;
            nouveau->next = tmp;

            printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès\n");
            return;
        }
        else {
            // Cas : insertion à la fin de la liste
            if (pos == n + 1) {
                printf("\nCet ajout se fait en fin de liste.");
                ajout_Fin(L);   // Appelle la fonction d’insertion en fin
                printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès\n");
                return;
            }
            else {
                // Cas : position trop grande
                printf("\nLa taille actuelle de la liste ne permet pas une opération d'ajout à cette position. "
                       "Assurez-vous d'avoir construit une liste contenant au moins %d éléments.", pos - 1);
                return;
            }
        }
    }
    printf("\n");   // Affiche une ligne vide pour la lisibilité
}
//Fonction d' ajout à la fin d' une liste
void ajout_Fin(Liste **L)
{
    Liste  *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));
    if (nouveau == NULL)
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = entrerNombre();
    nouveau->data = val;
    nouveau->next = NULL; // Le nouveau nœud sera en fin de liste

    // Cas où la liste est vide
    if (*L == NULL)
    {
        *L = nouveau; // Le nouveau nœud devient la tête
        printf("\n");
        return;
    }

    // Sinon, on parcourt jusqu'au dernier élément
    tmp = *L;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // tmp pointe maintenant sur le dernier élément
    tmp->next = nouveau; // On ajoute le nouveau nœud à la fin

    printf("\n");
}
//Fonction quitter
void quitter()
{
    printf("\nMerci pour votre participation et à la prochaine .");
    printf("\n");
    return;
}
