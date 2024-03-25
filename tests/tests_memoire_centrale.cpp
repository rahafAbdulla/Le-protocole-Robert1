#include "../src/headers/memoire_centrale.h"

// Jeux de tests des fonctions définies dans memoire_centrale.cpp //

int main(){
    srand(time(0));
    mem_centrale mem = creation_memoire();
    t_utilisateur paul = creer_utilisateur("Paul", 3, 2);
    t_utilisateur tom = creer_utilisateur("Tom", 3, 2);
    t_date date;
    date.jour = 1;
    date.mois = 1;
    date.an = 2020;
    
    // Les fonctions d'ajout, de suppression et de comparaison ont été testées dans les fichiers précédents

    // Test creation_memoire

    cout << "Test : La mémoire créée est bien vide :" << endl;
    cout << "- Contacts mémoire centrale :" << endl;
    afficher_contact(mem.cas_contact);
    cout << endl;

    // Tests comparer_contact

    cout << "test : comparer deux contacts égaux (1):" << endl;
    ajout_contact_entre(paul, tom, date);
    cout << comparer_contact(paul.liste_contact->contact, tom.liste_contact->contact) << endl;
    cout << endl;

    cout << "test : comparer deux contacts de même date mais non égaux (0):" << endl;
    ajout_contact_aleatoire(paul, date);
    cout << comparer_contact(paul.liste_contact->suivant->contact, tom.liste_contact->contact) << endl;
    cout << endl;

    cout << "test : comparer deux contacts totalement différents (0):" << endl;
    avancer_date(date, 1);
    ajout_contact_aleatoire(paul, date);
    cout << comparer_contact(paul.liste_contact->suivant->suivant->contact, tom.liste_contact->contact) << endl;
    cout << endl;

    // Tests ajouter_liste_contact

    cout << "Test : ajout d'une liste vide :" << endl;
    supprimer_contact_debut(tom.liste_contact);
    ajout_liste_contact(mem.cas_contact, tom.liste_contact);
    cout << "- Contacts mémoire centrale :" << endl;
    afficher_contact(mem.cas_contact);
    cout << endl;

    cout << "Test : ajout d'une liste non vide :" << endl;
    ajout_liste_contact(mem.cas_contact, paul.liste_contact);
    cout << "- Contacts mémoire centrale :" << endl;
    afficher_contact(mem.cas_contact);
    cout << endl;

    cout << "Test : ajout chronologique au sein de la liste :" << endl;
    date.jour -= 1;
    ajout_contact_aleatoire(tom, date);
    ajout_liste_contact(mem.cas_contact, tom.liste_contact);
    cout << "- Contacts mémoire centrale :" << endl;
    afficher_contact(mem.cas_contact);
    cout << endl;

    cout << "Test : ajout en fin de liste, et doublon entre les listes :" << endl;
    avancer_date(date, 2);
    ajout_contact_aleatoire(tom, date);
    ajout_liste_contact(mem.cas_contact, tom.liste_contact);
    cout << "- Contacts mémoire centrale :" << endl;
    afficher_contact(mem.cas_contact);
    cout << endl;

    // Verification_cas_contact, envoyer_liste_contact, passer_une journée et fin_de_journée sont testées dans l'application principale.
}

// Résultats des tests ////////////////////
/*
Test : La mémoire créée est bien vide :
- Contacts mémoire centrale :
Liste vide

test : comparer deux contacts égaux (1):
1

test : comparer deux contacts de même date mais non égaux (0):
0

test : comparer deux contacts totalement différents (0):
0

Test : ajout d'une liste vide :
- Contacts mémoire centrale :
Liste vide

Test : ajout d'une liste non vide :
- Contacts mémoire centrale :
Le 01/01/2020
meda82 et tigy14
Le 01/01/2020
lupe17 et gifi76
Le 02/01/2020
qufu15 et waxe54

Test : ajout chronologique au sein de la liste :
- Contacts mémoire centrale :
Le 01/01/2020
meda82 et tigy14
Le 01/01/2020
lupe17 et gifi76
Le 01/01/2020
xyri80 et vube63
Le 02/01/2020
qufu15 et waxe54

Test : ajout en fin de liste, et doublon entre les listes :
- Contacts mémoire centrale :
Le 01/01/2020
meda82 et tigy14
Le 01/01/2020
lupe17 et gifi76
Le 01/01/2020
xyri80 et vube63
Le 02/01/2020
qufu15 et waxe54
Le 03/01/2020
veci85 et qicu40
*/