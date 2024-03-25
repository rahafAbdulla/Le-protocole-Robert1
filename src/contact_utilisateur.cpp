#include "headers/contact_utilisateur.h"

/**
 * Ce fichier défini les fonctions de gestion des interractions entre utilisateurs
 **/

// Fonctions et procédures /////////////////////////////////////

/***************************************************
 * Rôle : Crée un nouvel utilisateur 
 * Précondition : Aucune (la bonne saisie des valeurs seuil et capa est forcée)
 * @param  name nom de l'utilisateur
 * @param capa capacité mémoire du téléphone (pseudo)
 * @param seuil de nombre de pseudos à avoir dans la liste
 * @return nouvel utilisateur
 **/
t_utilisateur creer_utilisateur(string name, int capa, int seuil){
    //Variable
    t_utilisateur util;

    //Début
    util.name = name;
    if (capa < 1){
        util.capa = 1;
    }
    else{
        util.capa = capa;
    }
    if (seuil < 1){
        util.seuil = 1;
    }
    else if (seuil > capa){
        util.seuil = capa;
    }
    else{
        util.seuil = seuil;
    }
    util.liste_pseudo = creer_liste_pseudo(capa);
    util.liste_contact = NULL;

    return util;
    //Fin
}

/******************************************************
 * Rôle : ajout d'un contact à la fin d'une liste de contacts
 * Précondition : contact instancié
 * @param liste de contacts à élargir
 * @param contact à ajouter
 **/
void ajouter_contact_debut(t_maillon_contact *&liste, t_contact contact){
    //Variable
    t_maillon_contact *ptr;

    //Début
    ptr = new t_maillon_contact;
    ptr->contact = contact;
    ptr->suivant = liste;
    liste = ptr;
    //Fin
}

/******************************************************
 * Rôle : ajout d'un contact à la fin d'une liste de contacts
 * Précondition : contact instancié
 * @param liste de contacts à élargir
 * @param contact à ajouter
 **/
void ajouter_contact_fin(t_maillon_contact *&liste, t_contact contact){
    //Variable
    t_maillon_contact *ptr;

    //Début
    if (liste == NULL){
        liste = new t_maillon_contact;
        liste->contact = contact;
        liste->suivant = NULL;
    }
    else{
        ptr = liste;
        while (ptr->suivant != NULL){
            ptr = ptr->suivant;
        }
        ptr->suivant = new t_maillon_contact;
        ptr = ptr->suivant;
        ptr->contact = contact;
        ptr->suivant = NULL;
    }
    //Fin
}

/******************************************************
 * Rôle : ajout d'un contact après un contact donné d'une liste de contacts
 * Précondition : contact instancié
 * @param maillon après lequel ajouter le contact
 * @param contact à ajouter
 **/
void ajouter_contact_apres(t_maillon_contact *&maillon, t_contact contact){
    //Variable
    t_maillon_contact *ptr;

    //Début
    ptr = maillon->suivant;
    maillon->suivant = new t_maillon_contact;
    maillon->suivant->contact = contact;
    maillon->suivant->suivant = ptr;
    //Fin
}

/******************************************************
 * Rôle : supprime le premier contact d'une liste de contacts
 * Précondition :
 * @param liste de contacts à modifier
 **/
void supprimer_contact_debut(t_maillon_contact *&liste){
    //Variable 
    t_maillon_contact *ptr;

    //Début
    if (liste != NULL){
        ptr = liste;
        liste = liste->suivant;
        delete ptr;
    }
    //Fin
}

/******************************************************
 * Rôle : supprime le dernier contact d'une liste de contacts,
 * liste en modification si elle ne possède qu'un seul élément
 * Précondition : 
 * @param liste de contacts à modifier
 **/
void supprimer_contact_fin(t_maillon_contact *&liste){
    //Variable
    t_maillon_contact *ptr, *prec;

    //Début
    ptr = liste;
    //Si la liste donnée n'est pas nulle
    if (ptr != NULL){
        //Si la liste donnée possède plus d'un élément
        if (ptr->suivant != NULL){
            //On la parcours pour supprimer le dernier élément
            while (ptr->suivant != NULL){
                prec = ptr;
                ptr = ptr->suivant;
            }
            delete ptr;
            prec->suivant = NULL;
        }
        else{
            //Sinon, on vide la liste
            delete ptr;
            liste = NULL;
        }
    }
    //Fin
}

/******************************************************
 * Rôle : supprime le contact après le maillon donné
 * Précondition : contact donné et suivant non null
 * @param maillon après lequel supprimer
 **/
void supprimer_contact_apres(t_maillon_contact *&maillon){
    //Variable
    t_maillon_contact *ptr;

    //Début
    ptr = maillon->suivant;
    maillon->suivant = ptr->suivant;
    delete ptr;
    //Fin
}

/******************************************************
 * Rôle : Ajout d'un contact aléatoire à la fin de la liste de contacts d'un utilisateur 
 * Précondition : liste de pseudo non vide, date instanciée et >= aux dates des contacts présents dans la liste
 * @param util utilisateur en contact
 * @param date du jour
 **/
void ajout_contact_aleatoire(t_utilisateur &util, t_date date){
    //Variable
    t_contact contact;

    //Début
    contact.pseudo1 = util.liste_pseudo->pseudo;
    contact.pseudo2 = donne_pseudo();
    contact.date = date;
    //Ajoute le contact à la liste de l'utilisateur
    ajouter_contact_fin(util.liste_contact, contact);
    //Supprime le pseudo utilisé par l'utilisateur
    supprimer_premier_pseudo(util.liste_pseudo);
    //Recharge la liste si nécéssaire
    recharger_liste_pseudo(util.liste_pseudo, util.seuil, util.capa);
    //Fin
}

/*********************************************************
 * Rôle : Ajout d'un contact entre deux utilisateur 
 * Précondition : utilisateurs et date instanciés
 * @param utilA 1er utilisateur
 * @param utilB 2ème utilisateur
 * @param date du jour
 **/
void ajout_contact_entre(t_utilisateur &utilA, t_utilisateur &utilB, t_date date){
    //Variable
    t_contact contact;

    //Début
    contact.pseudo1 = utilA.liste_pseudo->pseudo;
    contact.pseudo2 = utilB.liste_pseudo->pseudo;
    contact.date = date;
    //Ajout le contact aux listes de utilisateurs
    ajouter_contact_fin(utilA.liste_contact, contact);
    ajouter_contact_fin(utilB.liste_contact, contact);
    //Supprime les pseudos utilisés des utilisateurs
    supprimer_premier_pseudo(utilA.liste_pseudo);
    supprimer_premier_pseudo(utilB.liste_pseudo);
    //Recharge les listes si nécéssaire
    recharger_liste_pseudo(utilA.liste_pseudo, utilA.seuil, utilA.capa);
    recharger_liste_pseudo(utilB.liste_pseudo, utilB.seuil, utilB.capa);
    //Fin
}

/*****************************************************
 * Rôle : supprime les contact de plus de deux semaines (14 jours) 
 * Précontition : date valide, liste dans l'ordre chronologique
 * @param liste de contacts de l'utilisateur
 * @param date du jour
 **/
void supprimer_ancien_contact(t_maillon_contact *&liste, t_date date){
    //Variables
    t_maillon_contact *ptr;
    t_date seuil;
    bool verif_date;

    //Début
    //Récupération de la date seuil
    seuil = donne_date_butoir(date);
    ptr = liste;
    //Si la liste n'est pas vide, on rentre dans la boucle
    verif_date = (ptr != NULL);
    while(verif_date && ptr != NULL){
        //Si la date est antérieure à la date seuil ...
        verif_date = comparer_date(seuil, ptr->contact.date);
        //... On supprime le contact du chaînage
        if (verif_date){
            supprimer_contact_debut(liste);
            ptr = liste;
        }
    }
    //Fin
}

/********************************************************
 * Rôle : Affiche une liste de contacts pour jeux de tests
 * Précondition : Aucune
 * @param liste de contact à afficher
 **/
void afficher_contact(t_maillon_contact *liste){
    //Variable
    t_maillon_contact *ptr;

    //Début
    if (liste == NULL){
        cout << "Liste vide" << endl;
    }
    else{
        ptr = liste;
        while (ptr != NULL){
            cout << "Le ";
            afficher_date(ptr->contact.date);
            cout << ptr->contact.pseudo1+" et "+ptr->contact.pseudo2 << endl;
            ptr = ptr->suivant;
        }
    }
    //Fin
}