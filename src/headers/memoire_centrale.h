#ifndef _MEMOIRE_CENTRALE
#define _MEMOIRE_CENTRALE
#include "contact_utilisateur.h"

// Type utilisé ////////////////////////////////////////

/********************************************
 * Enregistrement de la mémoire centrale de l'application
 **/
typedef struct mem_centrale{
    t_maillon_contact *cas_contact;
}mem_centrale;


// Signatures des fonctions et procédures //////////////

mem_centrale creation_memoire();

bool comparer_contact(t_contact contact_mem, t_contact contact_util);

void ajout_liste_contact(t_maillon_contact *&memoire, t_maillon_contact *&liste);

t_maillon_contact* verification_cas_contact(mem_centrale &memoire, t_maillon_contact *liste);

string envoyer_liste_contact(mem_centrale &memoire, t_utilisateur &util, bool est_malade);

void passer_une_journee(t_utilisateur &user, t_date date);

void fin_de_journee(mem_centrale &appli, t_utilisateur &user, bool est_malade);

#endif