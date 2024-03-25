#include "headers/memoire_centrale.h"

/**
 * Ce fichier défini les fonctions associées à la mémoire centrale de 
 * l'application et à la simulation de son utilisation.
 **/

// Fonctions et procédures /////////////////////////////////////

/**************************************************
 * Rôle : Initialisation de la mémoire centrale
 * Précondition : 
 * @return mémoire centrale vide
 **/
mem_centrale creation_memoire(){
    //Variables
    mem_centrale mem;

    //Début
    mem.cas_contact = NULL;
    return mem;
    //Fin
}

/***************************************************
 * Rôle : Vérifie si deux contacts sont les mêmes
 * Précondition :
 * @param contact_mem dans la mémoire
 * @param contact_util de l'utilisateur
 **/
bool comparer_contact(t_contact contact_mem, t_contact contact_util){
    //Variable
    bool meme_contact;

    //Début
    //Vérificaton de la date
    meme_contact = (contact_mem.date.jour == contact_util.date.jour && contact_mem.date.mois == contact_util.date.mois && contact_mem.date.an == contact_util.date.an);
    //Si la date est la même, on verifie les pseudos (1v1,2v2 et 1v2,2v1)
    if (meme_contact){
        meme_contact = ((contact_mem.pseudo1 == contact_util.pseudo1 && contact_mem.pseudo2 == contact_util.pseudo2)||(contact_mem.pseudo1 == contact_util.pseudo2 && contact_mem.pseudo2 == contact_util.pseudo1));
    }
    return meme_contact;
    //Fin
}

/***************************************************
 * Rôle : Ajout d'une liste de contacts à la mémoire centrale si l'utilisateur se sent malade,
 * et suppression de la liste envoyée côté utilisateur
 * Précondition : Aucune
 * @param memoire centrale de l'application
 * @param liste de contacts à ajouter à la mémoire centrale
 **/
void ajout_liste_contact(t_maillon_contact *&memoire, t_maillon_contact *&liste){
    //Variables
    t_maillon_contact *ptr_list; //Parcours la liste utilisateur
    t_maillon_contact *ptr_mem; //Parcours la mémoire centrale
    t_contact contact; //Recopie du contact à ajouter
    bool est_ajoute;

    //Début
    ptr_list = liste;
    while(ptr_list != NULL){
        //On récupère le contact à ajouter
        contact = ptr_list->contact;
        ptr_mem = memoire;
        est_ajoute = false;
        //Si la mémoire est vide, on l'instancie
        if (ptr_mem == NULL){
            ajouter_contact_debut(memoire, contact);
            est_ajoute = true;
        }
        if (!est_ajoute){
            //On vérifie si le contact est à ajouter au début de la mémoire centrale
            if (comparer_date(ptr_mem->contact.date, contact.date)){
                ajouter_contact_debut(memoire, contact);
                est_ajoute = true;
            }
        }
        //Sinon on recherche où l'insérer dans la mémoire centrale
        while(!est_ajoute){
            //Si le contact est déjà présent, il n'est pas ajouté et on sort de la boucle
            if (comparer_contact(ptr_mem->contact, contact)){
                est_ajoute = true;
            }
            
            //Si la fin de la liste est atteinte et qu'aucune occurrence n'a été trouvé
            //On recopie le contact à la fin de la mémoire centrale
            if (ptr_mem->suivant == NULL && !est_ajoute){
                ajouter_contact_apres(ptr_mem, contact);
                est_ajoute = true;
            }
            
            //Sinon on continu la recherche
            if(!est_ajoute){
                //Si la date est plus ancienne que celle du contact suivant de la mémoire centrale
                if(comparer_date(ptr_mem->suivant->contact.date, contact.date)){
                    //On le recopie dans la mémoire centrale
                    ajouter_contact_apres(ptr_mem, contact);
                    est_ajoute = true;
                }
                else{
                    //Sinon, on verifie le maillon suivant
                    ptr_mem = ptr_mem->suivant;
                }
            }
        }
        ptr_list = ptr_list->suivant;
        supprimer_contact_debut(liste);
    }
    //Fin
}

/******************************************************
 * Rôle : retourne le contact précédant celui d'un possible cas contact d'un utilisateur
 * @param memoire centrale de l'application
 * @param liste de contacts de l'utilisateur
 * @return le contact précédent le cas contact trouvé, null sinon
 **/
t_maillon_contact* verification_cas_contact(mem_centrale &memoire, t_maillon_contact *liste){
    //Variables
    t_maillon_contact *ptr_mem;
    t_maillon_contact *ptr_prec;
    t_maillon_contact *ptr_util;
    
    //Début
    ptr_mem = memoire.cas_contact;
    ptr_prec = ptr_mem;
    while(ptr_mem != NULL){
        ptr_util = liste;
        while(ptr_util != NULL){
            if (comparer_contact(ptr_mem->contact, ptr_util->contact)){
                //Si une ocurence est trouvée, le contact précédent est retourné
                return ptr_prec;
            }
            ptr_util = ptr_util->suivant;
        }
        ptr_prec = ptr_mem;
        ptr_mem = ptr_mem->suivant;
    }
    return NULL;
    //Fin
}

/***************************************************
 * Rôle : Réceptionne la liste des contacts d'un utilisateur
 * Si l'utilisateur se sent malade, sa liste de contacts est stocker par l'application
 * Envoie un message à l'utilisateur en fonction de la situation.
 * Préconditions : mémoire et utilisateur instanciés
 * @param memoire centrale de l'application
 * @param util utilisateur de l'application
 * @param est_malade 
 **/
string envoyer_liste_contact(mem_centrale &memoire, t_utilisateur &util, bool est_malade){
    //Variable
    t_maillon_contact *ptr_contact;
    
    //Début
    //Si l'utilisateur est malade, on ajoute sa liste de contacts à la mémoire centrale
    if (est_malade){
        ajout_liste_contact(memoire.cas_contact, util.liste_contact);
        return "Prenez soin de vous";
    }
    else{
        //Sinon, on verifie s'il est cas contact
        ptr_contact = verification_cas_contact(memoire, util.liste_contact);
        //Si il est cas contact ...
        if (ptr_contact != NULL){
            //.. L'utilisateur est informé, on peut libérer la mémoire de cette information
            //Si le contact est le premier de la mémoire centrale, sinon le suivant
            if (ptr_contact = memoire.cas_contact){
                supprimer_contact_debut(memoire.cas_contact);
            }
            else{
                supprimer_contact_apres(ptr_contact);
            }
            return "Vous êtes cas contact !";
        }
        return "Restez Prudent";
    }
    //Fin
}

/****************************************************
 * Rôle : Fait se dérouler la journée d'un utilisateur
 * @param user utilisateur de l'application
 * @param date du jour
 **/
void passer_une_journee(t_utilisateur &user, t_date date){
    //Variable
    int nombre_contact;

    //Début
    //En début de journée, les anciens contacts sont supprimés
    supprimer_ancien_contact(user.liste_contact, date);
    //Pendant la journée, l'utilisateur rencontre entre 0 et 20 personnes
    nombre_contact = rand()%20;
    for (int i=0; i<nombre_contact; i++){
        ajout_contact_aleatoire(user, date);
    }
    //Fin
}

/******************************************************
 * Rôle : simule la fin de journée d'un utilisateur, et l'envoie de ces informations 
 * à la mémoire centrale.
 * Préconditions : appli et user instanciés
 * @param appli mémoire centrale de l'application
 * @param user utilisateur de l'application
 * @param est_malade vrai si l'utilisateur se sent malade, faux sinon
 **/
void fin_de_journee(mem_centrale &appli, t_utilisateur &user, bool est_malade){
    //Variable
    string mess;

    //Début
    mess = "Message pour "+user.name+" : ";
    mess = mess + envoyer_liste_contact(appli, user, est_malade);
    cout << mess << endl;
    //Fin
}