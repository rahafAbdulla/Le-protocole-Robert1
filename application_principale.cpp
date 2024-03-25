#include "src/headers/memoire_centrale.h"

/**
 * Ce fichier simule l'utilisation de l'application selon un scénario prédéfini 
 * et développé dans la fonction main.
 **/

int main(){
    srand(time(0));
    //Deux utilisateurs
    t_utilisateur charles;
    t_utilisateur alice;
    //Une mémoire centrale de l'application
    mem_centrale appli;
    //Référence de la date du jour
    t_date date;

    //initialisation de Charles
    charles = creer_utilisateur("Charles", 10, 5);

    //initialisation de Alice
    alice = creer_utilisateur("Alice", 12, 4);

    //Initialisation de la mémoire centrale
    appli = creation_memoire();

    //Initialisation de la date du jour
    date = creer_date(1, 3, 2020);

    // Début de la simulation ------------------------------------

    // JOUR 1 ----------------------------------------------------
    //Le premier jour, Charles et Alice ne se rencontrent pas :
    passer_une_journee(charles, date);
    passer_une_journee(alice, date);

    //Affichage de la date pour les messages du jours
    cout << "Le "; 
    afficher_date(date);
    //Le soir, ils envoient leurs listes de contacts, ils ne sont pas malade :
    fin_de_journee(appli, charles, false);
    fin_de_journee(appli, alice, false);


    // JOUR 3 ----------------------------------------------------
    avancer_date(date, 2);
    supprimer_ancien_contact(appli.cas_contact, date);
    //Le 3ème jour, ils ne se rencontrent toujours pas.
    passer_une_journee(charles, date);
    passer_une_journee(alice, date);

    //Affichage de la date pour les messages du jours
    cout << "Le ";
    afficher_date(date);
    //En fin de journée, Charles se sent malade
    fin_de_journee(appli, charles, true);
    fin_de_journee(appli, alice, false);


    // JOUR 6 -----------------------------------------------------
    avancer_date(date, 3);
    supprimer_ancien_contact(appli.cas_contact, date);
    //Le 6ème jour, Charles à passé un test négatif, il peut sortir
    passer_une_journee(charles, date);
    passer_une_journee(alice, date);
    //Et Charles et Alice se croisent
    ajout_contact_entre(alice, charles, date);

    //Affichage de la date pour les messages du jours
    cout << "Le "; 
    afficher_date(date);
    //Le soir, ils envoient leurs listes de contacts, ils ne sont pas malade :
    fin_de_journee(appli, charles, false);
    fin_de_journee(appli, alice, false);


    // JOUR 16 -----------------------------------------------------
    avancer_date(date, 10);
    supprimer_ancien_contact(appli.cas_contact, date);
    //Le 16ème jour, ils ne se rencontrent pas
    passer_une_journee(charles, date);
    passer_une_journee(alice, date);

    //Affichage de la date pour les messages du jours
    cout << "Le ";
    afficher_date(date);
    //Mais le soir, Alice se sent malade ...
    fin_de_journee(appli, alice, true);
    fin_de_journee(appli, charles, false);

    // Fin de la simulation ------------------------------------------
}

// Résultat de la simulation ////////////////
/*
Le 01/03/2020
Message pour Charles : Restez Prudent
Message pour Alice : Restez Prudent
Le 03/03/2020
Message pour Charles : Prenez soin de vous
Message pour Alice : Restez Prudent
Le 06/03/2020
Message pour Charles : Restez Prudent
Message pour Alice : Restez Prudent
Le 16/03/2020
Message pour Alice : Prenez soin de vous
Message pour Charles : Vous êtes cas contact !
*/
