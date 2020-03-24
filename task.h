#include <string>
#include <vector>
#include <ctime>
#include "date.h"

#pragma once

class Task {
public:
    std::string title;
    std::string description;
    int id;
    std::string status;
    Date open;
    Date close;
    int priority;
    std::vector<std::string> comments;
    int achiev;
    std::vector<Task> subtask;

    Task (std::string t, std::string d, int i, int p) ;

    Task (std::string t, std::string d, Date op, int i, int p) ;

    void print () ;

    void closing ();

    void closing_dated (Date cl);
};

bool sort_priority (Task a, Task b);