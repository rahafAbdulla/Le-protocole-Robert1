#include "headers/pseudo_utilisateur.h"

/**
 * Ce fichier défini les fonctions de création et gestion des pseudonymes 
 * des utilisateurs.
 **/

// Fonctions et procédures /////////////////////////////////////

/*****************************************************
 * (Recopie de donne_pseudo_v3.cpp)
 * Rôle : Génère un pseudonyme de manière aléatoire
 * Précondition : Aucune
 * @return pseudo aléatoire
 **/
string donne_pseudo(){
  string pseudo = ""; 

  for (int i=0; i<2; i++){                    //boucle de génération de la chaine de lettres
    pseudo = pseudo + consonne[rand()%20];    //tire au hasard un chiffre entre 0 et 20 puis ajoute la lettre correspondante au pseudo  
    pseudo = pseudo + voyelle[rand()%6];      //tire au hasard un chiffre entre 0 et 6 puis ajoute la lettre correspondante au pseudo  
  }
  for (int i=0; i<2; i++){                    //boucle de génération des deux chiffres
    pseudo = pseudo + to_string(rand()%9);    //tire au hasard un chiffre entre 0 et 9 puis le convertit en chaine de caractères avant de l'ajouter au pseudo  
  }
  return pseudo;
}

/*****************************************************
 * Rôle : Création d'une liste de pseudonymes d'une taille donnée
 * Préconditions : Aucune
 * @param capa taille de la liste à créer
 * @return liste de pseudos de taille capa
 * */
t_pseudo* creer_liste_pseudo(int capa){
    //Variables
    t_pseudo *ptr, *tete;

    //Début
    if (capa > 0){
        tete = new t_pseudo;
        ptr = tete;
        for (int i=1; i < capa; i++){
            ptr->pseudo = donne_pseudo();
            ptr->suiv = new t_pseudo;
            ptr = ptr->suiv;
        
        }
        //valeur nulle en fin de chaînage pour le dernier pseudo
        ptr->pseudo = donne_pseudo();
        ptr->suiv = NULL;
        return tete;
    }
    else{
        return NULL;
    }
    //Fin
}

/******************************************************
 * Rôle : Supprime le premier pseudo du chaînage
 * Préconditions : Aucune
 * @param tete début du chaînage
 * */
void supprimer_premier_pseudo(t_pseudo *&tete){
    //Variables
    t_pseudo *ptr;

    //Début
    if (tete != NULL){
        ptr = tete;
        tete = tete->suiv;
        delete ptr;
    }
    //Fin
}

/*******************************************************
 * Rôle : Supprime le dernier pseudo du chaînage
 * Précondition : Aucune
 * @param tete début du chaînage
 * */
void supprimer_dernier_pseudo(t_pseudo *&tete){
    //Variables
    t_pseudo *ptr, *prec;

    //Début
    if (tete != NULL){
        ptr = tete;
        if (ptr->suiv != NULL){
            while(ptr->suiv != NULL){
                prec = ptr;
                ptr = ptr->suiv;
            }
            delete ptr;
            prec->suiv = NULL;
        }
        else{
            delete ptr;
            tete = NULL;
        }
    }
    //Fin
}

/*********************************************************
 * Rôle : Recharge la liste si sa taille descend en dessous d'un seuil
 * Préconditions : liste en paramètre non vide et seuil < capa
 * @param tete pointeur de la liste
 * @param seuil pour recharger la liste
 * @param capa taille maximale de la liste
 **/
void recharger_liste_pseudo(t_pseudo *tete, unsigned seuil, unsigned capa){
    //Variables
    t_pseudo *ptr;
    int cpt;

    //Début
    ptr = tete;
    cpt = 1;
    //Parcours de la liste pour connaitre sa taille
    while(ptr->suiv != NULL){
        ptr = ptr->suiv;
        cpt ++;
    }
    //Verification par rapport au seuil
    if (cpt < seuil){
        ptr->suiv = creer_liste_pseudo(capa-cpt);
    }
    //Fin
}

/************************************************************
 * Rôle : Affiche une liste de pseudonymes
 * Précondition : Aucune
 * @param liste de pseudos à afficher
 **/
void afficher_liste_pseudo(t_pseudo *liste){
    //Variable
    t_pseudo *ptr;

    //Début
    ptr = liste;
    //Si la liste est vide
    if(ptr == NULL){
        cout << "Aucun pseudonyme enregistré" << endl;
    }
    else{
        //Sinon on parcours la liste pour afficher les pseudos enregistrés
        while(ptr != NULL){
            cout << ptr->pseudo+" ";
            ptr = ptr->suiv;
        }
    }
    cout << endl;
    //Fin
}