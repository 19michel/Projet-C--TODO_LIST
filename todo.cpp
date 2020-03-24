#include <iostream>
#include <vector>
#include <algorithm>
#include "task.h"
#include "todo.h"

To_Do::To_Do () : nb(0), list({}) {};

void To_Do::print () {
    int l = list.size();
    for (int i = 0; i < l; i++) {
        list[i].print();
    };
    std::cout << "" << std::endl;
}

void To_Do::print (int p) {
    int l = list.size();
    int i = 0;
    while ((i<l) && (list[i].priority >= p)) {
        list[i].print();
        i++;
    };
    std::cout << "" << std::endl;   
} 

const char** To_Do::add (std::string t, std::string d, int p) {
    list.push_back(Task (t, d, nb, p));
    const char **date = list[list.size() - 1].open.to_str();
    nb++;
    std::sort(list.begin(),list.end(),sort_priority);
    return date;
}

const char** To_Do::add_st (std::string st, std::string t, std::string d, int p) {
    int i = pos(t);
    list[i].subtask.push_back(Task (st, d, nb, p));
    const char** date = list[i].subtask[list[i].subtask.size() - 1].open.to_str();
    nb++;
    std::sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    return date;
}

void To_Do::add_dated (std::string t, std::string d, int p, Date op) {
    list.push_back(Task (t, d, op, nb, p));
    nb++;
    std::sort(list.begin(),list.end(),sort_priority);
}

void To_Do::add_st_dated (std::string st, std::string t, std::string d, int p, Date op) {
    int i = pos(t);
    list[i].subtask.push_back(Task (st, d, op, nb, p));
    nb++;
    std::sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}

int To_Do::pos (std::string t) {
    int i {};
    while (list[i].title != t) {i++;};
    return i;
}

int To_Do::pos_st (std::string st, std::string t) {
    int i = pos(t);
    int j {};
    while (list[i].subtask[j].title != st) {j++;}
    return j;
}

void To_Do::add_comments (std::string t, std::string c) {
    int i = pos(t);
    list[i].comments.push_back(c); 
}

void To_Do::add_comments_st (std::string st, std::string t, std::string c) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].comments.push_back(c); 
}

void To_Do::change_priority (std::string t, int p) {
    int i = pos(t);
    list[i].priority = p;
    std::sort(list.begin(),list.end(),sort_priority);
}

void To_Do::change_achiev (std::string t, int a) {
    int i = pos(t);
    list[i].achiev = a;
}

void To_Do::change_priority_st (std::string st, std::string t, int p) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].priority = p;
    std::sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}

void To_Do::change_achiev_st (std::string st, std::string t, int a) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].achiev = a;
}

const char** To_Do::end (std::string t) {
    int i = pos(t);
    list[i].closing();
    const char** date = list[list.size() - 1].close.to_str();
    std::sort(list.begin(),list.end(),sort_priority);
}

const char** To_Do::end_st (std::string st, std::string t) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].closing();
    const char** date = list[i].subtask[list[i].subtask.size() - 1].close.to_str();
    std::sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}

void To_Do::end_dated (std::string t, Date cl) {
    int i = pos(t);
    list[i].closing_dated(cl);
    std::sort(list.begin(),list.end(),sort_priority);
}

void To_Do::end_st_dated (std::string st, std::string t, Date cl) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].closing_dated(cl);
    std::sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}