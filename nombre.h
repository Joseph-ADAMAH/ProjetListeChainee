#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED
typedef struct Liste  Liste ;
struct Liste
{
    int data;
    Liste* next ;
};

void  menu();//Fonction d' affichage de menu

void construction_liste_depart(Liste** tete);//Fonction de connstruction de la liste de départ
//void afficher_Liste(Liste*tete);//Fonction d' affichage de liste

//int nbreElement(Liste* tete);

int entrerNombre(); // Sera utiliser pour tout entrer d'ajout

int demandePosition() ;// Fonction sera utiliser pour demander les position d'ajout ou de suppression

void ajout_Debut(Liste** tete);//Fonction d' ajpout en début de liste

void ajout_Position(Liste** tete);//Fonction d' ajpout en début de liste

void ajout_Fin(Liste** tete);//Fonction d' ajpout en début de liste


/*void supprimerTete(Liste** tete);

void supprimerMilieu(Liste** tete);

void supprimerQueue(Liste** tete);

void modifier(Liste** tete);

void supprimerTout(Liste** tete);*/

void quitter();//Fonction pour quitter le programme


#endif // NOMBRE_H_INCLUDED
