#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

typedef struct Liste Liste ;
struct Liste
{
    int data;
    Liste* next ;
};

int afficheMenu();
void Construction_liste();
void AfficherListe(Liste* tete);


void longueurListe(Liste* tete);

int EntrerNombre() // Sera utiliser pour tout entrer d'ajout

int DemandePosition() // Fonction sera utiliser pour demander les position d'ajout ou de suppression

void AjoutDebut(Liste** tete, int controle);

void AjoutMilieu(Liste* tete, int controle);

void AjoutFin(Liste* tete, int controle);

//void Supprimer(Nbre** tete, int controle);

void SupprimerTete(Liste** tete);

void SupprimerMilieu(Liste** tete);

void SupprimerQueue(Liste** tete);

void Modifier(Liste** tete);

void SupprimerTout(Liste** tete);

void Quitter(Liste** tete);


#endif // NOMBRE_H_INCLUDED
