#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
            parcour = parcour->next;
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
        parcour = parcour->next;
    }
    return longeur;
}

void AfficherListe(Liste* tete)
{
    Liste *parcour; // Pour parcourir la liste
    parcour = tete;
    int i = 1; //Pour compter les nombre
    if (parcour == NULL)
    {
        printf("\n\nLa liste est vide pour le moment\n\n ");
    }
    while(parcour != NULL )
    {
        printf("\nNombre %d : %d \n", i, parcour->data);
        parcour = parcour->next;
        i++;
    }
    printf("\n");
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
    else if (parcour->next == NULL)
    {
        printf("\nIl n'y a qu'un seul élément dans la liste");
    }
    else
    {
        while(DesordreListe)
        {
            DesordreListe = false;
            parcour = *tete;

            while(parcour->next != NULL)
            {

                if (parcour->data <  parcour->next->data)
                {
                    echangeur = parcour->data;
                    parcour->data = parcour->next->data;
                    parcour->next->data = echangeur;
                    DesordreListe = true;
                }
                parcour = parcour->next;
            }
        }
    }
}

void TrierCroissant(Liste **tete)
{
     bool DesordreListe = true; // Variable du type bool du trie à bulle
    int echangeur;
    Liste *parcour;
    parcour = *tete;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else if (parcour->next == NULL)
    {
        printf("\nIl n'y a qu'un seul élément dans la liste");
    }
    else
    {
        while(DesordreListe)
        {
            DesordreListe = false;
            parcour = *tete;

            while(parcour->next != NULL)
            {

                if (parcour->data >  parcour->next->data)
                {
                    echangeur = parcour->data;
                    parcour->data = parcour->next->data;
                    parcour->next->data = echangeur;
                    DesordreListe = true;
                }
                parcour = parcour->next;
            }
        }
    }
}

void Quitter(Liste **tete)
{
    Liste *precedent, *parcour = *tete;

    while(parcour != NULL)
    {
        precedent = parcour;
        parcour = parcour->next;
        free(precedent);
    }
    printf("\nA la prochaine !!\n");
}


//Fonction de construction de la  liste de début
void construction_liste_depart(Liste **tete)
{
    Liste *tmp=(Liste*)malloc(sizeof(Liste));
    int val ;

    //On vérifie si le reservation  a été fait .
    if (tmp==NULL)
    {
        printf("\nErreur de reservation.");
        return;
    }else
    {
    val =   EntrerNombre();
    tmp->data=val;
    tmp->next=*tete;
    *tete = tmp;
    printf("\n");
}
}

//Fonctions d' ajout d' éléments dans la liste
//Fonction d' ajout au début d' une liste
void ajout_Debut(Liste **tete)
{
    Liste *tmp = (Liste*)malloc(sizeof(Liste)); // Alloue un nouveau nœud
    if (tmp == NULL)                            // Vérifie si l'allocation a réussi
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = EntrerNombre();  // Demande la valeur à insérer
    tmp->data = val;           // Stocke la valeur dans le nœud
    tmp->next = *tete;            // Le nouveau nœud pointe vers l'ancienne tête
    *tete = tmp;                  // La tête devient le nouveau nœud
    printf("\n");
}

//Fonction d' ajout à une position donnée d' une liste

void ajout_Position(Liste**tete)   // Fonction qui ajoute un élément à une position donnée dans la liste
{
    int position = demandePosition();    // Demande à l'utilisateur la position où insérer le nouvel élément
    int tailleListe = longueurListe(*tete);        // Compte le nombre d'éléments actuels dans la liste

    // Vérifie si la position est invalide (inférieure à 1)
    if (position < 1) {
        printf("Impossible d'effectuer cette opération ");
        return;   // On quitte la fonction car la position est incorrecte
    }
    else
        {


    // Vérifie si la liste est vide
    if (*tete == NULL) {
        // Si la liste est vide mais que la position demandée est 1, on peut ajouter au début
        if (position == 1) {
            printf("\nCet ajout se fait au tout début de la liste.");
            ajout_Debut(tete);   // Appelle la fonction qui insère au début
            printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès");
            //return;   // On quitte après l’ajout
        }
        else {
            // Si la liste est vide et que la position est > 1, on refuse l'opération
            printf("\nImpossible de faire cette opération, vérifiez la taille de la liste");
            //return;
        }
    }
    else {
        // Si la liste n'est pas vide, on continue le traitement
        printf("\nCette opération se fait à la position %d de la liste", position);

        // Cas : insertion dans une position existante (au milieu)
        if (position > 1 && position <= tailleListe) {
            // Création du nouveau nœud
            Liste *p, *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));

            // Vérifie si l'allocation mémoire a réussi
            if (nouveau == NULL) {
                printf("\nErreur de réservation.");
                return;
            }

            int valeur = EntrerNombre();  // Demande la valeur à insérer
            tmp = *tete;                  // Pointeur temporaire pour parcourir la liste
            nouveau->data = valeur;       // Affecte la valeur saisie au nouveau nœud

            int k = 1;   // Compteur de position pour atteindre l’endroit où insérer
            while (tmp != NULL && k < position) {
                k++;
                p = tmp;       // p garde l'adresse du nœud précédent
                tmp = tmp->next;  // tmp avance dans la liste
            }

            // Insère le nouveau nœud entre p et tmp
            p->next = nouveau;
            nouveau->next = tmp;

            printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès\n");
        }
        else {
            // Cas : insertion à la fin de la liste
            if (position == tailleListe + 1) {
                printf("\nCet ajout se fait en fin de liste.");
                ajout_Fin(tete);   // Appelle la fonction d’insertion en fin
                printf("\nL'opération d'ajout à la position souhaitée a été effectuée avec succès\n");
            }
            else {
                // Cas : position trop grande
                printf("\nPosition inexsitante, la taille actuelle de la liste est:  %d", tailleListe);
            }
        }
    }
    printf("\n");   // Affiche une ligne vide pour la lisibilité
}
}
//Fonction d' ajout à la fin d' une liste
void ajout_Fin(Liste **tete)
{
    Liste  *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));
    if (nouveau == NULL)
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = EntrerNombre();
    nouveau->data = val;
    nouveau->next = NULL; // Le nouveau nœud sera en fin de liste

    // Cas où la liste est vide
    if (*tete == NULL)
    {
        *tete = nouveau; // Le nouveau nœud devient la tête
        printf("\n");
        return;
    }

    // Sinon, on parcourt jusqu'au dernier élément
    tmp = *tete;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // tmp pointe maintenant sur le dernier élément
    tmp->next = nouveau; // On ajoute le nouveau nœud à la fin

    printf("\n");
}
