#include <vector>
#include <tuple>
#include "task.h"
using namespace std;

#pragma once 

class To_Do {
private:
    int nb;
    vector<Task> list; 

public: 

    To_Do () ;

    void print () ;
    /* Affiche les tâches en cours de la to-do liste */

    void print (int p) ;
    /* Affiche les tâches ayant une priorité supérieure à p de la to-do liste.
    On a donc print(0) = print() */

    vector<string> add (string t, string d, int p) ;
    /* ajoute une tache avec la date actuelle comme date d'ouverture */

    vector<string> add_st (string st, string t, string d, int p) ;
    /* ajoute une sous-tache en désignant la tache principale avec son titre avec la date actuelle comme date d'ouverture */

    vector<string> add_st (string st, int ide, string d, int p) ;
    /* ajoute une sous-tache en désignant la tache principale avec son id unique avec la date actuelle comme date d'ouverture */

    void add_dated (string t, string d, int p, Date op) ;
    /* ajoute une tache avec la date op comme date d'ouverture */

    void add_st_dated (string st, string t, string d, int p, Date op) ;
    /* ajoute une sous-tache en désignant la tache principale avec son titre avec la date op comme date d'ouverture */

    void add_st_dated (string st, int ide, string d, int p, Date op) ;
    /* ajoute une sous-tache en désignant la tache principale avec son id unique avec la date op comme date d'ouverture */

    int pos (string t) ;
    /* donne la position dans la liste de la première tache nommée t */

    tuple<int,int> pos (int ide) ;
    /* donne la position dans la liste de la tache ou de la sous-tache identifiée par ide.
    Elle renvoie un couple ou le premier élément correspond à la position de la tache et le deuxième à celui de la sous-tache.
    Le deuxième vaut -1 s'il s'agit d'une tache */

    int pos_st (string st, string t) ;
    /* donne la position dans la liste de la première sous-tache nommée st et ayant pour tache principale une tache nommée t */

    void change_priority (string t, int p) ;
    /* change la priorité d'une tache désignée par son titre t */

    void change_priority (int ide, int p) ;
    /* change la priorité d'une tache ou d'une sous-tache désignée par son id ide */

    void change_priority_st (string st, string t, int p) ;
    /* change la priorité d'une sous-tache désignée par son titre st et celui de sa tache principale t */

    void add_comments (string t, string c) ;
    /* ajoute à un commentaire à une tache désigné par son titre t */

    void add_comments (int ide, string c) ;
    /* ajoute à un commentaire à une tache ou d'une sous-tache désignée par son id ide */

    void add_comments_st (string st, string t, string c) ;
    /* ajoute à un commentaire à une sous-tache désignée par son titre st et celui de sa tache principale t */

    void change_achiev (string t, int a) ;
    /* change l'avancement d'une tache désignée par son titre t */

    void change_achiev (int ide, int a) ;
    /* change l'avancement d'une tache ou d'une sous-tache désignée par son id ide */

    void change_achiev_st (string st, string t, int a) ;
    /* change l'avancement d'une sous-tache désignée par son titre st et celui de sa tache principale t */

    vector<string> close (string t) ;
    /* ferme une tache désignée par son titre t à la date actuelle.
    De plus, cette date est renvoyée afin d'être écrite dans le fichier d'enregistrement */

    vector<string> close (int ide) ;
    /* ferme une tache ou une sous-tache désignée par son id i à la date actuelle */

    vector<string> close_st (string st, string t) ;
    /* ferme une sous-tache désignée par son titre st et celui de sa tache principale t à la date actuelle */

    void close_dated (string t, Date cl) ;
    /* ferme une tache désignée par son titre t à la date cl */

    void close_dated (int ide, Date cl) ;
    /* ferme une tache ou une sous-tache désignée par son id i à la date cl */

    void close_st_dated (string st, string t, Date cl) ;
    /* ferme une sous-tache désignée par son titre st et celui de sa tache principale t à la date cl */
};