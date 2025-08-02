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

//int entrerNombre(); // Sera utiliser pour tout entrer d'ajout

int demandePosition() ;// Fonction sera utiliser pour demander les position d'ajout ou de suppression

void ajout_Debut(Liste** tete);//Fonction d' ajpout en début de liste

void ajout_Position(Liste** tete);//Fonction d' ajpout en début de liste

void ajout_Fin(Liste** tete);//Fonction d' ajpout en début de liste


int longueurListe(Liste* tete);

int EntrerNombre(); // Sera utiliser pour tout entrer d'ajout

int DemandePosition(); // Fonction sera utiliser pour demander les position d'ajout ou de suppression

void AjoutFin(Liste** tete);

//void Supprimer(Nbre** tete, int controle);

void SupprimerTete(Liste** tete);

void SupprimerMilieu(Liste** tete);

void SupprimerQueue(Liste** tete);

void Modifier(Liste** tete);

void SupprimerTout(Liste** tete);

void TrierDecroissant(Liste** tete);
void TrierCroissant(Liste** tete);
void Quitter(Liste** tete);

#endif // NOMBRE_H_INCLUDED
