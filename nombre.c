#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "nombre.h"
//Fonction d' affichage  du m�nu
void menu()
{
    printf("\n===============  Voici le m�nu de manipulation =================");
    printf("\n");
    printf("\n1-) Ajout d ' �l�ment au d�dut de la liste.");
    printf("\n");
    printf("\n2-) Ajout d' �l�ment a la fin de la liste.");
    printf("\n");
    printf("\n3-) Ajout  d' �l�ment a une position  quelconque de la liste .");
    printf("\n");
    printf("\n4-)  Affichage de la liste apres une  ou plusieurs op�rations. ");
    printf("\n");
    printf("\n5-) Affichage du nombre d' �l�ment   de la liste " );
    printf("\n");
    printf("\n6-) Quitter . ");
    printf("\n");

}
int EntrerNombre() // Sera utiliser pour tout entrer d'ajout
{
    int nombre, ControleNombre;
    printf("\nVeuillez entrer le nombre � ajouter : ");
    // Do while suivant est utiliser pour controler  l'entrer du nombre
    //En effet la fonction scanf retourne 1 si la valeur saisi est entier sinon elle une valeurs diff�rent de 1
    // Aissi on l'a utiliser pour controler l'entrer des nombres pour que le programme de s'arr�te pas si
    //l'utilisateur entre un caract�re � la place du nombre
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
        printf("\nSupprimer avec succ�s \n");
    }
}
int longueurListe(Liste* tete)
{
    Liste *parcour; // Pour parcourir la liste
    parcour = tete; // initialisation
    int longeur; // Pour stocker la longueur � retourner par la fonction(Longueur de la liste)
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
// Les fonctions suivantes sont des fonctions qui vont trier la liste en utilisant le trie � bulle
void TrierDecroissant(Liste **tete)
{
     bool DesordreListe = true; // Variable du type bool du trier � bulle
    int echangeur; // Variable pour �changer les valeur
    Liste *parcour; // Pour parcourir la liste
    parcour = *tete;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else if (parcour->next == NULL)
    {
        printf("\nIl n'y a qu'un seul �l�ment dans la liste");
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
     bool DesordreListe = true; // Variable du type bool du trie � bulle
    int echangeur;
    Liste *parcour;
    parcour = *tete;
    if (parcour == NULL)
    {
        printf("\nLa liste est vide\n");
    }
    else if (parcour->next == NULL)
    {
        printf("\nIl n'y a qu'un seul �l�ment dans la liste");
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


//Fonction de construction de la  liste de d�but
void construction_liste_depart(Liste **tete)
{
    Liste *tmp=(Liste*)malloc(sizeof(Liste));
    int val ;

    //On v�rifie si le reservation  a �t� fait .
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

//Fonctions d' ajout d' �l�ments dans la liste
//Fonction d' ajout au d�but d' une liste
void ajout_Debut(Liste **tete)
{
    Liste *tmp = (Liste*)malloc(sizeof(Liste)); // Alloue un nouveau n�ud
    if (tmp == NULL)                            // V�rifie si l'allocation a r�ussi
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = EntrerNombre();  // Demande la valeur � ins�rer
    tmp->data = val;           // Stocke la valeur dans le n�ud
    tmp->next = *tete;            // Le nouveau n�ud pointe vers l'ancienne t�te
    *tete = tmp;                  // La t�te devient le nouveau n�ud
    printf("\n");
}

//Fonction d' ajout � une position donn�e d' une liste

void ajout_Position(Liste**tete)   // Fonction qui ajoute un �l�ment � une position donn�e dans la liste
{
    int position = demandePosition();    // Demande � l'utilisateur la position o� ins�rer le nouvel �l�ment
    int tailleListe = longueurListe(*tete);        // Compte le nombre d'�l�ments actuels dans la liste

    // V�rifie si la position est invalide (inf�rieure � 1)
    if (position < 1) {
        printf("Impossible d'effectuer cette op�ration ");
        return;   // On quitte la fonction car la position est incorrecte
    }
    else
        {


    // V�rifie si la liste est vide
    if (*tete == NULL) {
        // Si la liste est vide mais que la position demand�e est 1, on peut ajouter au d�but
        if (position == 1) {
            printf("\nCet ajout se fait au tout d�but de la liste.");
            ajout_Debut(tete);   // Appelle la fonction qui ins�re au d�but
            printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s");
            //return;   // On quitte apr�s l�ajout
        }
        else {
            // Si la liste est vide et que la position est > 1, on refuse l'op�ration
            printf("\nImpossible de faire cette op�ration, v�rifiez la taille de la liste");
            //return;
        }
    }
    else {
        // Si la liste n'est pas vide, on continue le traitement
        printf("\nCette op�ration se fait � la position %d de la liste", position);

        // Cas : insertion dans une position existante (au milieu)
        if (position > 1 && position <= tailleListe) {
            // Cr�ation du nouveau n�ud
            Liste *p, *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));

            // V�rifie si l'allocation m�moire a r�ussi
            if (nouveau == NULL) {
                printf("\nErreur de r�servation.");
                return;
            }

            int valeur = EntrerNombre();  // Demande la valeur � ins�rer
            tmp = *tete;                  // Pointeur temporaire pour parcourir la liste
            nouveau->data = valeur;       // Affecte la valeur saisie au nouveau n�ud

            int k = 1;   // Compteur de position pour atteindre l�endroit o� ins�rer
            while (tmp != NULL && k < position) {
                k++;
                p = tmp;       // p garde l'adresse du n�ud pr�c�dent
                tmp = tmp->next;  // tmp avance dans la liste
            }

            // Ins�re le nouveau n�ud entre p et tmp
            p->next = nouveau;
            nouveau->next = tmp;

            printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s\n");
        }
        else {
            // Cas : insertion � la fin de la liste
            if (position == tailleListe + 1) {
                printf("\nCet ajout se fait en fin de liste.");
                ajout_Fin(tete);   // Appelle la fonction d�insertion en fin
                printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s\n");
            }
            else {
                // Cas : position trop grande
                printf("\nPosition inexsitante, la taille actuelle de la liste est:  %d", tailleListe);
            }
        }
    }
    printf("\n");   // Affiche une ligne vide pour la lisibilit�
}
}
//Fonction d' ajout � la fin d' une liste
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
    nouveau->next = NULL; // Le nouveau n�ud sera en fin de liste

    // Cas o� la liste est vide
    if (*tete == NULL)
    {
        *tete = nouveau; // Le nouveau n�ud devient la t�te
        printf("\n");
        return;
    }

    // Sinon, on parcourt jusqu'au dernier �l�ment
    tmp = *tete;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // tmp pointe maintenant sur le dernier �l�ment
    tmp->next = nouveau; // On ajoute le nouveau n�ud � la fin

    printf("\n");
}
