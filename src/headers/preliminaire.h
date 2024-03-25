#ifndef _PRELIMINAIRE
#define _PRELIMINAIRE
#include <iostream>
using namespace std;

// Type utilisé ////////////////////////////////////////

/********************************************
 * Enregistrement d'une maille d'un chaînage de données
 **/
typedef struct t_maille {
    int info;
    t_maille *suiv;
}t_maille;


// Signatures des fonctions et procédures //////////////

void ajout_debut(t_maille *&tete, int info);

void ajout_fin(t_maille *&tete, int info);

void supprimer_debut(t_maille *&tete);

void supprimer_fin(t_maille *&tete);

void afficher_liste(t_maille *liste);

#endif