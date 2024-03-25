#ifndef _CONTACT_UTILISATEUR
#define _CONTACT_UTILISATEUR
#include "pseudo_utilisateur.h"
#include "date.h"

// Types utilisés //////////////////////////////////////

/********************************************
 * Enregistrement d'un contact entre utilisateurs
 **/
typedef struct t_contact{
    string pseudo1;
    string pseudo2;
    t_date date;
}t_contact;

/********************************************
 * Enregistrement d'un chaînage de contacts entre utilisateurs
 **/
typedef struct t_maillon_contact{
    t_contact contact;
    t_maillon_contact *suivant;
}t_maillon_contact;

/********************************************
 * Enregistrement d'un utilisateurs de l'application
 **/
typedef struct t_utilisateur{
    string name;
    t_pseudo *liste_pseudo;
    t_maillon_contact *liste_contact;
    int capa;
    int seuil;
}t_utilisateur;


// Signatures des fonctions et procédures //////////////

t_utilisateur creer_utilisateur(string name, unsigned capa, unsigned seuil);

void ajouter_contact_debut(t_maillon_contact *&liste, t_contact contact);

void ajouter_contact_fin(t_maillon_contact *&liste, t_contact contact);

void ajouter_contact_apres(t_maillon_contact *&maillon, t_contact contact);

void supprimer_contact_debut(t_maillon_contact *&liste);

void supprimer_contact_fin(t_maillon_contact *&liste);

void supprimer_contact_apres(t_maillon_contact *&maillon);

void ajout_contact_aleatoire(t_utilisateur &util, t_date date);

void ajout_contact_entre(t_utilisateur &utilA, t_utilisateur &utilB, t_date date);

void supprimer_ancien_contact(t_maillon_contact *&liste, t_date date);

void afficher_contact(t_maillon_contact *liste);

#endif