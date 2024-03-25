#include "../src/headers/contact_utilisateur.h"

// Jeux de tests des fonctions définie dans contact_utilisateur.cpp //

int main(){
    srand(time(0));
    t_utilisateur tom = creer_utilisateur("Tom", 5, 3);
    t_utilisateur paul = creer_utilisateur("Paul", 7, 4);
    t_date date;
    date.jour = 1;
    date.mois = 1;
    date.an = 2020;

    //Les fonctions d'ajout et de suppression ont le même schéma que celles testées dans pseudo_utilisateur

    // Test afficher_contact

    cout << "Test : Affichage d'une liste de contacts vide :" << endl;
    cout << "- Contact de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    // Tests ajout_contact_aleatoire

    cout << "Test : Ajout d'un contact aléatoire à une liste vide :" << endl;
    ajout_contact_aleatoire(tom, date);
    cout << "- Contact de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    cout << "Test : Ajout d'un contact aléatoire à une liste non vide :" << endl;
    ajout_contact_aleatoire(tom, date);
    cout << "- Contacts de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    // Test ajout_contact_entre

    cout << "Test : Ajout d'un contact entre utilisateur avec liste vide et non vide :" << endl;
    ajout_contact_entre(tom, paul, date);
    cout << "- Contacts de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << "- Contact de Paul :" << endl;
    afficher_contact(paul.liste_contact);
    cout << endl;

    // Tests supprimer_ancien_contact

    cout << "Test : Non suppression des contacts du même jour :" << endl;
    supprimer_ancien_contact(tom.liste_contact, date);
    cout << "- Contacts de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    cout << "Test : Non suppression des contacts de moins de 14 jours :" << endl;
    avancer_date(date, 14);
    supprimer_ancien_contact(tom.liste_contact, date);
    cout << "- Contacts de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    cout << "Test : Suppression des contacts de plus de 14 jours :" << endl;
    avancer_date(date, 1);
    supprimer_ancien_contact(tom.liste_contact, date);
    cout << "- Contacts de Tom :" << endl;
    afficher_contact(tom.liste_contact);
    cout << endl;

    // Fin des tests et nettoyage mémoire
    supprimer_contact_debut(paul.liste_contact);
    delete paul.liste_contact;
    delete tom.liste_contact;
    while (paul.liste_pseudo != NULL && tom.liste_pseudo != NULL){
        supprimer_premier_pseudo(tom.liste_pseudo);
        supprimer_premier_pseudo(paul.liste_pseudo);
    }
    delete paul.liste_pseudo;
    delete tom.liste_pseudo;
}

// Résultats des tests ////////////////////
/*
Test : Affichage d'une liste de contacts vide :
- Contact de Tom :
Liste vide

Test : Ajout d'un contact aléatoire à une liste vide :
- Contact de Tom :
Le 01/01/2020
taze17 et tusi68

Test : Ajout d'un contact aléatoire à une liste non vide :
- Contacts de Tom :
Le 01/01/2020
taze17 et tusi68
Le 01/01/2020
haqo08 et sawy37

Test : Ajout d'un contact entre utilisateur avec liste vide et non vide :
- Contacts de Tom :
Le 01/01/2020
taze17 et tusi68
Le 01/01/2020
haqo08 et sawy37
Le 01/01/2020
nyde44 et lowa87
- Contact de Paul :
Le 01/01/2020
nyde44 et lowa87

Test : Non suppression des contacts du même jour :
- Contacts de Tom :
Le 01/01/2020
taze17 et tusi68
Le 01/01/2020
haqo08 et sawy37
Le 01/01/2020
nyde44 et lowa87

Test : Non suppression des contacts de moins de 14 jours :
- Contacts de Tom :
Le 01/01/2020
taze17 et tusi68
Le 01/01/2020
haqo08 et sawy37
Le 01/01/2020
nyde44 et lowa87

Test : Suppression des contacts de plus de 14 jours :
- Contacts de Tom :
Liste vide
*/