#include "../src/headers/date.h"

// Jeux de tests des fonctions définies dans date.cpp //

int main(){
    t_date base;
    t_date butoir;

    // Test avancer_date -------------

    //Initialisation au 31/12/2019
    cout << "Initialisation au 31/12/2019" << endl << endl;
    base = creer_date(31, 12, 2019);

    //Changement d'année
    cout << "Test : Changement d'année :" << endl; 
    avancer_date(base, 1);
    afficher_date(base);
    cout << endl;

    //Changement de mois dans la même année
    cout << "test : Changement de mois dans la même année :" << endl;
    avancer_date(base, 31);
    afficher_date(base);
    cout << endl;

    //Aller en mars en année bissextile
    cout << "test : Aller en mars en année bissextile :" << endl;
    avancer_date(base, 29);
    afficher_date(base);
    cout << endl;

    //Aller en mars en année non bissextile
    cout << "test : Aller en mars en année non bissextile :" << endl;
    base = creer_date(1, 2, 2019);
    avancer_date(base, 28);
    afficher_date(base);
    cout << endl;

    // Test donne_date_butoire -----------

    //Initialisation au 14/01/2020
    cout << "Initialisation au 14/01/2020" << endl << endl;
    base = creer_date(14, 1, 2020);

    //Changement d'année
    cout << "Test : Changement d'année pour une date butoir :" << endl; 
    butoir = donne_date_butoir(base);
    afficher_date(butoir);
    cout << endl;

    //Changement de mois dans la même année
    cout << "Test : Changement de mois dans la même année pour une date butoir :" << endl;
    avancer_date(base, 31);
    butoir = donne_date_butoir(base);
    afficher_date(butoir);
    cout << endl;

    //Retourner en février en année bissextile
    cout << "Test : Retourner en février en année bissextile pour une date butoir :" << endl;
    avancer_date(base, 29);
    butoir = donne_date_butoir(base);
    afficher_date(butoir);
    cout << endl;

    //Retourner en février en année non bissextile
    cout << "Test : Retourner en février en année non bissextile pour une date butoir :" << endl;
    base.an = 2019;
    butoir = donne_date_butoir(base);
    afficher_date(butoir);
    cout << endl;

    // Tests comparer_date --------------

    //Dates égale retourne faux (0):
    cout << "Test : Dates égale retourne faux (0) :" << endl;
    butoir = base;
    cout << comparer_date(base, butoir) << endl;
    cout << endl;

    //Date de référence < date à comparer retourne faux (0) :
    cout << "Test : Date de référence < date à comparer retourne faux (0) :" << endl;
    avancer_date(butoir, 1);
    cout << comparer_date(base, butoir) << endl;
    cout << endl;
    
    //Date de référence > date à comparer retourne vrai (1) :
    cout << "Test : Date de référence > date à comparer retourne vrai (1) :" << endl;
    avancer_date(base, 2);
    cout << comparer_date(base, butoir) << endl;
    cout << endl;

    //La fonction afficher_date a été testée au long de ces tests
    //Fin des tests
}

// Résultats des tests ////////////////////
/*
Initialisation au 31/12/2019

Test : Changement d'année :
01/01/2020

test : Changement de mois dans la même année :
01/02/2020

test : Aller en mars en année bissextile :
01/03/2020

test : Aller en mars en année non bissextile :
01/03/2019

Initialisation au 14/01/2020

Test : Changement d'année pour une date butoir :
31/12/2019

Test : Changement de mois dans la même année pour une date butoir :
31/01/2020

Test : Retourner en février en année bissextile pour une date butoir :
29/02/2020

Test : Retourner en février en année non bissextile pour une date butoir :
28/02/2019

Test : Dates égale retourne faux (0) :
0

Test : Date de référence < date à comparer retourne faux (0) :
0

Test : Date de référence > date à comparer retourne vrai (1) :
1
*/