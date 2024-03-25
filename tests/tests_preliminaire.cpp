#include "../src/headers/preliminaire.h"

// Jeux de tests des fonctions définies dans preliminaire.cpp //

int main(){
    t_maille *liste = NULL;

    // Tests ajout_debut

    cout << "Test : ajout début d'une liste vide :" << endl;
    ajout_debut(liste, 2);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : ajout début d'une liste non vide :" << endl;
    ajout_debut(liste, 1);
    afficher_liste(liste);
    cout << endl;

    // Tests supprimer_debut

    cout << "Test : supprimer début d'une liste non vide :" << endl;
    supprimer_debut(liste);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : supprimer début d'une liste vide :" << endl;
    supprimer_debut(liste);
    supprimer_debut(liste);
    afficher_liste(liste);
    cout << endl;

    // Tests ajout_fin

    cout << "Test : ajout fin d'une liste vide :" << endl;
    ajout_fin(liste, 1);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : ajout fin d'une liste d'un seul élément :" << endl;
    ajout_fin(liste, 2);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : ajout fin d'une liste de plus d'un élément :" << endl;
    ajout_fin(liste, 3);
    afficher_liste(liste);
    cout << endl;

    // Tests supprimer_fin

    cout << "Test : supprimer fin d'une liste de plus d'un élément :" << endl;
    supprimer_fin(liste);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : supprimer fin d'une liste d'un seul élément :" << endl;
    supprimer_fin(liste);
    supprimer_fin(liste);
    afficher_liste(liste);
    cout << endl;

    cout << "Test : supprimer fin d'une liste vide :" << endl;
    supprimer_fin(liste);
    afficher_liste(liste);
    cout << endl;

    // Fin des tests et nettoyage mémoire
    delete liste;
}

// Résultats des tests ////////////////////

/*
Test : ajout début d'une liste vide :
2

Test : ajout début d'une liste non vide :
12

Test : supprimer début d'une liste non vide :
2

Test : supprimer début d'une liste vide :
La liste est vide

Test : ajout fin d'une liste vide :
1

Test : ajout fin d'une liste d'un seul élément :
12

Test : ajout fin d'une liste de plus d'un élément :
123

Test : supprimer fin d'une liste de plus d'un élément :
12

Test : supprimer fin d'une liste d'un seul élément :
La liste est vide

Test : supprimer fin d'une liste vide :
La liste est vide
*/