#include "../src/headers/pseudo_utilisateur.h"

// Jeux de tests des fonctions définies dans pseudo_utilisateur.cpp //

int main(){
    srand(time(0));
    int capa = 5;
    t_pseudo *liste = NULL;

    //Affichage vide
    cout << "Test : Affichage vide" << endl;
    afficher_liste_pseudo(liste);

    //Création d'une liste de 5 pseudos
    cout << "Test : Création d'une liste de 5 pseudos" << endl;
    liste = creer_liste_pseudo(capa);
    afficher_liste_pseudo(liste);
    cout << endl;

    //Suppression du premier pseudo
    cout << "Test : Suppression du premier pseudo" << endl;
    supprimer_premier_pseudo(liste);
    afficher_liste_pseudo(liste);
    cout << endl;
    
    //Suppression du dernier pseudo
    cout << "Test : Suppression du dernier pseudo" << endl;
    supprimer_dernier_pseudo(liste);
    afficher_liste_pseudo(liste);
    cout << endl;

    //Tente de recharger avec condition non respectée
    cout << "Test : Tente de recharger avec condition non respectée" << endl;
    recharger_liste_pseudo(liste, 3, 5);
    afficher_liste_pseudo(liste);
    cout << endl;

    //Tente de recharger avec condition respectée
    cout << "Test : Tente de recharger avec condition respectée" << endl;
    recharger_liste_pseudo(liste, 4, 5);
    afficher_liste_pseudo(liste);
    cout << endl;

    //La procédure afficher_liste_pseudo à été testée au long de ces tests

    //Fin des tests et nettoyage mémoire
    for (int i=0; i<5; i++){
        supprimer_premier_pseudo(liste);
    }
    delete liste;
}

// Résultats des tests ////////////////////
/*
Test : Affichage vide
Aucun pseudonyme enregistré

Test : Création d'une liste de 5 pseudos
pali82 sygi44 poci72 zyqo33 zumo40 

Test : Suppression du premier pseudo
sygi44 poci72 zyqo33 zumo40 

Test : Suppression du dernier pseudo
sygi44 poci72 zyqo33 

Test : Tente de recharger avec condition non respectée
sygi44 poci72 zyqo33 

Test : Tente de recharger avec condition respectée
sygi44 poci72 zyqo33 duja64 vify81 
*/