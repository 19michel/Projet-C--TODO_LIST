#include <string>
#include <vector>
#include <ctime>
#include "date.h"
using namespace std;

#pragma once

class Task {
public:
    string title;
    string description;
    int id;
    string status;
    Date open;
    Date close;
    int priority;
    vector<string> comments;
    int achiev;
    vector<Task> subtask;

    Task (string t, string d, int i, int p) ;

    Task (string t, string d, Date op, int i, int p) ;

    void print () ;
    /* Affiche la tâche */

    void print (string str) ;
    /* Affiche la tâche en ajoutant str à la fin */

    void closing ();
    /* Ferme la tâche en mettant la date actuelle comme date de fermeture */

    void closing_dated (Date cl);
    /* Ferme la tâche en mettant la date cl comme date de fermeture */
};

bool sort_priority (Task a, Task b);
/* permet de comparer deux tâches par priorité */