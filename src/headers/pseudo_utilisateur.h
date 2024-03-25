#ifndef _PSEUDO_UTILISATEUR
#define _PSEUDO_UTILISATEUR
#include <iostream>
#include <cstring>
#include <random>
#include <ctime>
using namespace std;

// Types utilisés //////////////////////////////////////

/****************************************
 * Enregistrement d'un chaînage de pseudonymes
 **/
typedef struct t_pseudo{
    string pseudo;
    t_pseudo *suiv;
}t_pseudo;

/*****************************************
 * Constantes des consonnes et voyelles pour la création de pseudonymes aléatoires
 **/
const char consonne[20] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
const char voyelle[6] = {'a','e','i','o','u','y'};            


// Signatures des fonctions et procédures //////////////

string donne_pseudo();

t_pseudo* creer_liste_pseudo(int capa);

void supprimer_premier_pseudo(t_pseudo *&tete);

void supprimer_dernier_pseudo(t_pseudo *&tete);

void recharger_liste_pseudo(t_pseudo *tete, unsigned seuil, unsigned capa);

void afficher_liste_pseudo(t_pseudo *liste);

#endif