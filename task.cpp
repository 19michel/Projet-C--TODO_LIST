#include<iostream>
#include<vector>
#include "date.h"
#include "task.h"


bool sort_priority (Task a, Task b) {
    return (a.priority > b.priority);
}

Task::Task (std::string t, std::string d, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), close(Date {}), comments({}), achiev(0), subtask({}) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    open = Date (ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
}

Task::Task (std::string t, std::string d, Date op, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), open(op), close(Date {}), comments({}), achiev(0), subtask({}) {}

void Task::print () {
    std::cout << id << " / " << title << ": " << description << " -> " << status << ", opened on ";
    open.print();
    if (status ==  "close" ) {
        std::cout << " and closed on ";
        close.print();
    } 
    std::cout << ". Priority: " << priority << ". Achievement: " << achiev << "%" << std::endl ;
    if (not(comments.empty())) {
        std::cout << "  Comments:" << std::endl;
        int l=comments.size();
        for (int i {}; i<l; i++) {
            std::cout << "      " << comments[i] << std::endl;
        }
    }

    if (not(subtask.empty())) {
        std::cout << "  TASKS:" << std::endl;
        for (int i {}; i<subtask.size(); i++) {
            subtask[i].print();
        }
    }
    std::cout << std::endl;
}

void Task::closing () {
    status="close";
    time_t now = time(0);
    tm* ltm = localtime(&now);
    close = Date (ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    priority=-1;
    achiev = 100;
}

void Task::closing_dated (Date cl) {
    status="close";
    close=cl;
    priority=-1;
    achiev=100;
}



