#include "headers/date.h"

/**
 * Ce fichier permet de gérer l'aspect temporel du projet, en datant les contacts d'un
 * utilisateur, et en définissant les dates de contacts de plus de deux semaine.
 **/

// Fonctions et procédures /////////////////////////////////////

t_date creer_date(int jour, int mois, int an){
    //Variable
    t_date date;

    //Début
    if (mois > 0 && mois <= 12){
        if (jour > 0){
            if (mois == 2 && ((date.an%4 == 0 && date.an%100 != 0) || date.an%400 == 0)){
                if (jour <= 29){
                    date.jour = jour;
                    date.mois = mois;
                    date.an = an;
                    return date;
                }
            }
            else if (jour <= jour_mois[mois-1]){
                date.jour = jour;
                date.mois = mois;
                date.an = an;
                return date;
            }
        }
    }
    //Si la date n'est pas valide, on informe l'utilisateur
    cout << "La date saisie n'est pas valide" << endl;
}

/*****************************************************
 * Rôle : Avance une date d'un nombre de jours donné
 * Préconditions : date valide
 * @param date à avancer
 * @param jour à rajouter
 **/
void avancer_date(t_date &date, unsigned jour){
    //Début
    
    //Si le mois de la date est février et l'année est bissextile
    if (date.mois == 2 && ((date.an%4 == 0 && date.an%100 != 0) || date.an%400 == 0)){
        date.jour = date.jour + jour;
        if (date.jour > 29){
            date.jour = date.jour - 29;
            date.mois = 3;
        }
    }
    else if (date.mois == 12 && date.jour + jour > 31){
        //On vérifie le cas du changement d'année
        date.jour = date.jour + jour - 31;
        date.mois = 1;
        date.an = date.an + 1;
    }
    else{
        //Sinon on utilise la constante des jours dans un mois
        date.jour = date.jour + jour;
        //On vérifie s'il y a un changement de mois dans la même année
        if (date.jour > jour_mois[date.mois-1]){
            date.jour = date.jour - jour_mois[date.mois-1];
            date.mois++;
        }
        //Sinon la mois et l'année sont inchangés
    }
    //Fin
}

/*****************************************************
 * Rôle : Retourne une date deux semaines avant celle donnée (14 jours)
 * Précondition : date valide
 * @param date_ref du jour
 **/
t_date donne_date_butoir(t_date date_ref){
    //Variable
    t_date seuil;

    //Début
    seuil.jour = date_ref.jour-14;
    //Si la nouvelle date est au mois précédent
    if(seuil.jour < 1){
        //Si la date de référence est en mars
        if(date_ref.mois == 3){
            //On vérifie si c'est une année bissextile pour le nombre de jours en février
            if ((date_ref.an%4 == 0 && date_ref.an%100 != 0) || date_ref.an%400 == 0){
                seuil.jour = 29 - seuil.jour;
            }
            else{
                seuil.jour = jour_mois[1] - seuil.jour;
            }
            seuil.mois = 2;
            seuil.an = date_ref.an;
        }
        else if(date_ref.mois == 1){
            //Si la date de référence est en janvier, on change l'année
            seuil.jour = 31 - seuil.jour;
            seuil.mois = 12;
            seuil.an = date_ref.an - 1;
        }
        else{
            //Sinon on calcul le nouveau jour en fonction du nombre de jours dans le mois voulu
            seuil.jour = jour_mois[date_ref.mois - 2] - seuil.jour;
            seuil.mois = date_ref.mois - 1;
            seuil.an = date_ref.an;
        }
    }
    else{
        //Si le jour n'est pas < 1, on recopie le mois et l'année
        seuil.mois = date_ref.mois;
        seuil.an = date_ref.an;
    }

    return seuil;
    //Fin
}

/*****************************************************
 * Rôle : compare deux dates et retourne vrai si la date précède la date de réference, faux sinon
 * Précondition : deux dates valides
 * @param date_ref date de réference
 * @param date à vérifier
 **/
bool comparer_date(t_date date_ref, t_date date){
    //Début
    if (date_ref.an < date.an){
        //La date est plus récente d'au moins un an
        return false;
    }
    else if (date_ref.an == date.an){
        if (date_ref.mois < date.mois){
            //La date est plus récente d'au moins un mois
            return false;
        }
        else if (date_ref.mois == date.mois){
            if (date_ref.jour <= date.jour){
                //La date est plus récente ou égale à celle de référence
                return false;
            }
        }
    }
    //Sinon la date est plus ancienne que celle de référence
    return true;
    //Fin
}

/********************************************************
 * Rôle : Retourne une chaîne de caractères répresentant une date
 * Précondition : date instanciée
 * @param date à afficher
 * @return date au format XX/XX/XXXX
 **/
void afficher_date(t_date date){
    //Variables :
    string jour;
    string mois;
    
    //Début
    jour = to_string(date.jour);
    if (date.jour <10){
        jour = "0"+jour;
    }
    mois = to_string(date.mois);
    if (date.mois < 10){
        mois = "0"+mois;
    }
    cout << jour+"/"+mois+"/"+to_string(date.an) << endl;
    //Fin
}