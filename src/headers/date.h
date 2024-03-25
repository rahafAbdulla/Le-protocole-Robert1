#ifndef _DATE
#define _DATE
#include <iostream>
#include <cstring>
using namespace std;

// Type utilisé ////////////////////////////////////////

/****************************************
 * Enregistrement d'une date
 **/
typedef struct t_date{
    int jour;
    int mois; 
    int an; 
}t_date;

/*****************************************
 * Constante de nombre de jours par mois
 **/
const int jour_mois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


// Signatures des fonctions et procédures //////////////

t_date creer_date(int jour, int mois, int an);

void avancer_date(t_date &date, unsigned jour);

t_date donne_date_butoir(t_date date_ref);

bool comparer_date(t_date date_ref, t_date date);

void afficher_date(t_date date);

#endif