#include <stdio.h>
#include <stdlib.h>
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
int entrerNombre() // Sera utiliser pour tout entrer d'ajout
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
//Fonction de construction de la  liste de d�but
void construction_liste_depart(Liste **L)
{
    Liste *tmp=(Liste*)malloc(sizeof(Liste));
    int val,result ;


    //On v�rifie si le reservation  a �t� fait .
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

//Fonctions d' ajout d' �l�ments dans la liste
//Fonction d' ajout au d�but d' une liste
void ajout_Debut(Liste **L)
{
    Liste *tmp = (Liste*)malloc(sizeof(Liste)); // Alloue un nouveau n�ud
    if (tmp == NULL)                            // V�rifie si l'allocation a r�ussi
    {
        printf("\nErreur de reservation.");
        return;
    }

    int val = entrerNombre();  // Demande la valeur � ins�rer
    tmp->data = val;           // Stocke la valeur dans le n�ud
    tmp->next = *L;            // Le nouveau n�ud pointe vers l'ancienne t�te
    *L = tmp;                  // La t�te devient le nouveau n�ud
    printf("\n");
}

//Fonction d' ajout � une position donn�e d' une liste

void ajout_Position(Liste**L)   // Fonction qui ajoute un �l�ment � une position donn�e dans la liste
{
    int pos = demandePosition();    // Demande � l'utilisateur la position o� ins�rer le nouvel �l�ment
    int n = nbreElement(*L);        // Compte le nombre d'�l�ments actuels dans la liste

    // V�rifie si la position est invalide (inf�rieure � 1)
    if (pos < 1) {
        printf("Impossible d'effectuer cette op�ration ");
        return;   // On quitte la fonction car la position est incorrecte
    }

    // V�rifie si la liste est vide
    if (*L == NULL) {
        // Si la liste est vide mais que la position demand�e est 1, on peut ajouter au d�but
        if (pos == 1) {
            printf("\nCet ajout se fait au tout d�but de la liste.");
            ajout_Debut(L);   // Appelle la fonction qui ins�re au d�but
            printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s");
            return;   // On quitte apr�s l�ajout
        }
        else {
            // Si la liste est vide et que la position est > 1, on refuse l'op�ration
            printf("\nImpossible de faire cette op�ration, v�rifiez la taille de la liste");
            return;
        }
    }
    else {
        // Si la liste n'est pas vide, on continue le traitement
        printf("\nCette op�ration se fait � la position %d de la liste", pos);

        // Cas : insertion dans une position existante (au milieu)
        if (pos > 1 && pos <= n) {
            // Cr�ation du nouveau n�ud
            Liste *p, *tmp, *nouveau = (Liste*)malloc(sizeof(Liste));

            // V�rifie si l'allocation m�moire a r�ussi
            if (nouveau == NULL) {
                printf("\nErreur de r�servation.");
                return;
            }

            int val = entrerNombre();  // Demande la valeur � ins�rer
            tmp = *L;                  // Pointeur temporaire pour parcourir la liste
            nouveau->data = val;       // Affecte la valeur saisie au nouveau n�ud

            int k = 1;   // Compteur de position pour atteindre l�endroit o� ins�rer
            while (tmp != NULL && k < pos) {
                k++;
                p = tmp;       // p garde l'adresse du n�ud pr�c�dent
                tmp = tmp->next;  // tmp avance dans la liste
            }

            // Ins�re le nouveau n�ud entre p et tmp
            p->next = nouveau;
            nouveau->next = tmp;

            printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s\n");
            return;
        }
        else {
            // Cas : insertion � la fin de la liste
            if (pos == n + 1) {
                printf("\nCet ajout se fait en fin de liste.");
                ajout_Fin(L);   // Appelle la fonction d�insertion en fin
                printf("\nL'op�ration d'ajout � la position souhait�e a �t� effectu�e avec succ�s\n");
                return;
            }
            else {
                // Cas : position trop grande
                printf("\nLa taille actuelle de la liste ne permet pas une op�ration d'ajout � cette position. "
                       "Assurez-vous d'avoir construit une liste contenant au moins %d �l�ments.", pos - 1);
                return;
            }
        }
    }
    printf("\n");   // Affiche une ligne vide pour la lisibilit�
}
//Fonction d' ajout � la fin d' une liste
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
    nouveau->next = NULL; // Le nouveau n�ud sera en fin de liste

    // Cas o� la liste est vide
    if (*L == NULL)
    {
        *L = nouveau; // Le nouveau n�ud devient la t�te
        printf("\n");
        return;
    }

    // Sinon, on parcourt jusqu'au dernier �l�ment
    tmp = *L;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    // tmp pointe maintenant sur le dernier �l�ment
    tmp->next = nouveau; // On ajoute le nouveau n�ud � la fin

    printf("\n");
}
//Fonction quitter
void quitter()
{
    printf("\nMerci pour votre participation et � la prochaine .");
    printf("\n");
    return;
}
