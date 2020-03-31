#include<iostream>
#include<vector>
#include "date.h"
#include "task.h"
using namespace std;


bool sort_priority (Task a, Task b) {
    return (a.priority > b.priority);
}

Task::Task (string t, string d, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), close(Date {}), comments({}), achiev(0), subtask({}) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    open = Date (ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
}

Task::Task (string t, string d, Date op, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), open(op), close(Date {}), comments({}), achiev(0), subtask({}) {}

void Task::print () {
    cout << id << " / " << title << ": " << description << " -> " << status << ", opened on ";
    open.print();
    if (status ==  "close" ) {
        cout << " and closed on ";
        close.print();
    } 
    cout << ". Priority: " << priority << ". Achievement: " << achiev << "%" << endl ;
    if (not(comments.empty())) {
        cout << "  Comments:" << endl;
        int l=comments.size();
        for (int i {}; i<l; i++) {
            cout << "      " << comments[i] << endl;
        }
    }

    if (not(subtask.empty())) {
        cout << "  TASKS:" << endl;
        for (int i {}; i<subtask.size(); i++) {
            subtask[i].print();
        }
    }
}

void Task::print (string str) {
    cout << id << " / " << title << ": " << description << " -> " << status << ", opened on ";
    open.print();
    if (status ==  "close" ) {
        cout << " and closed on ";
        close.print();
    } 
    cout << ". Priority: " << priority << ". Achievement: " << achiev << "%" << endl ;
    if (not(comments.empty())) {
        cout << "  Comments:" << endl;
        int l=comments.size();
        for (int i {}; i<l; i++) {
            cout << "      " << comments[i] << endl;
        }
    }

    if (not(subtask.empty())) {
        cout << "  TASKS:" << endl;
        for (int i {}; i<subtask.size(); i++) {
            subtask[i].print();
        }
        cout << endl;
    }
    cout << str;
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



