#include "headers/preliminaire.h"

/**
 * Ce fichier défini les fonctions de gestion d'un chaînage de données. 
 * (travail préliminaire)
 **/

// Fonctions et procédures /////////////////////////////////////

/**************************************************
* Rôle : Ajout d'un élément au début du chaînage
* Préconditions : Aucune
* @param tete début du chaînage
* @param ajout t_maille à ajouter
* */
void ajout_debut(t_maille *&tete, int info){
    //Variable
    t_maille *ptr;

    //Début
    ptr = new t_maille;
    ptr->info = info;
    ptr->suiv = tete;
    tete = ptr;
    //Fin
}

/***************************************************
 * Rôle : Ajout d'un élément à la fin du chaînage
 * Préconditions : Aucune
 * @param tete début du chaînage
 * @param ajout t_maille à ajouter
 * */
void ajout_fin(t_maille *&tete, int info){
    //Variable
    t_maille *ptr;

    //Début
    if (tete != NULL){
        ptr = tete;
        while(ptr->suiv != NULL){
            ptr = ptr->suiv;
        }
        ptr->suiv = new t_maille;
        ptr = ptr->suiv;
        ptr->info = info;
        ptr->suiv = NULL;
    }
    else{
        tete = new t_maille;
        tete->info = info;
        tete->suiv = NULL;
    }
    //Fin
}

/*****************************************************
 * Rôle : Supprime un élément au début du chaînage
 * Préconditions : Aucune
 * @param tete début du chaînage
 * */
void supprimer_debut(t_maille *&tete){
    //Variable
    t_maille *ptr;

    //Début
    if (tete != NULL){
        ptr = tete;
        tete = tete->suiv;
        delete(ptr);
    }
    //Fin
}

/*****************************************************
 * Rôle : Supprime un élément à la fin du chaînage
 * Préconditions : Aucune
 * @param tete début du chaînage
 * */
void supprimer_fin(t_maille *&tete){
    //Variable
    t_maille *ptr, *prec;

    //Début
    //Si le chaînage est non null
    if (tete != NULL){
        ptr = tete;
        //Si le chaînage possède plus d'un élément
        if (ptr->suiv != NULL){
            //On parcours le chaînage
            while (ptr->suiv != NULL){
                prec = ptr;
                ptr = ptr->suiv;
            }
            //Et on supprime le dernier élément
            delete ptr;
            prec->suiv = NULL;
        }
        else{
            //Sinon la chaînage devient null
            delete ptr;
            tete = NULL;
        }
    }
    //Fin
}

/******************************************************
 * Rôle : Affiche une liste chaînée pour jeux de tests
 * Précondition : Aucune
 * @param liste à afficher
 **/
void afficher_liste(t_maille *liste){
    //Variable
    t_maille *ptr;

    //Début
    ptr = liste;
    if (ptr == NULL){
        cout << "La liste est vide" << endl;
    }
    else{
        while (ptr != NULL){
            cout << ptr->info;
            ptr = ptr->suiv;
        }
        cout << endl;
    }
    //Fin
}