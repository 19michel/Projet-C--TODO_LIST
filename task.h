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

    void print (string str) ;

    void closing ();

    void closing_dated (Date cl);
};

bool sort_priority (Task a, Task b);