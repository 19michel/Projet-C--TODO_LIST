#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "task.h"
#include "todo.h"
using namespace std;

To_Do::To_Do () : nb(0), list({}) {};

void To_Do::print () {
    int l = list.size();
    for (int i = 0; i < l; i++) {
        list[i].print();
    };
    cout << endl;
}

void To_Do::print (int p) {
    int l = list.size();
    int i = 0;
    while ((i<l) && (list[i].priority >= p)) {
        list[i].print();
        i++;
    };
    cout << "" << endl;   
} 

vector<string> To_Do::add (string t, string d, int p) {
    list.push_back(Task (t, d, nb, p));
    vector<string> date = list[list.size() - 1].open.d_t_str();
    nb++;
    sort(list.begin(),list.end(),sort_priority);
    return date;
}

vector<string> To_Do::add_st (string st, string t, string d, int p) {
    int i = pos(t);
    list[i].subtask.push_back(Task (st, d, nb, p));
    vector<string> date = list[i].subtask[list[i].subtask.size() - 1].open.d_t_str();
    nb++;
    sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    return date;
}

void To_Do::add_dated (string t, string d, int p, Date op) {
    list.push_back(Task (t, d, op, nb, p));
    nb++;
    sort(list.begin(),list.end(),sort_priority);
}

void To_Do::add_st_dated (string st, string t, string d, int p, Date op) {
    int i = pos(t);
    list[i].subtask.push_back(Task (st, d, op, nb, p));
    nb++;
    sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}

int To_Do::pos (string t) {
    int i {};
    while (list[i].title != t) {i++;};
    return i;
}

tuple<int,int> To_Do::pos (int ide) {
    int i {};
    int j {};
    for (i; i<list.size(); i++) {
        if (list[i].id == ide) {
            j = -1;
            break;
        }
        bool test = false;
        for (j=0; j<list[i].subtask.size(); j++) {
            if (list[i].subtask[j].id == ide) {
                test = true;
                break;
            } 
        }
        if (test) {break;}
    }
    tuple<int,int> tup;
    get<0>(tup) = i;
    get<1>(tup) = j;
    return tup;
}

int To_Do::pos_st (string st, string t) {
    int i = pos(t);
    int j {};
    while (list[i].subtask[j].title != st) {j++;}
    return j;
}

void To_Do::add_comments (string t, string c) {
    int i = pos(t);
    list[i].comments.push_back(c); 
}

void To_Do::add_comments (int ide, string c) {
    tuple<int,int> tup = pos(ide);
    int i = get<0>(tup);
    int j = get<1>(tup);
    if (j == -1) {
        list[i].comments.push_back(c); 
    }
    else {
        list[i].subtask[j].comments.push_back(c);
    }
}

void To_Do::add_comments_st (string st, string t, string c) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].comments.push_back(c); 
}

void To_Do::change_priority (string t, int p) {
    int i = pos(t);
    list[i].priority = p;
    sort(list.begin(),list.end(),sort_priority);
}

void To_Do::change_priority (int ide, int p) {
    tuple<int,int> tup = pos(ide);
    int i = get<0>(tup);
    int j = get<1>(tup);
    if (j == -1) {
        list[i].priority = p;
        sort(list.begin(),list.end(),sort_priority); 
    }
    else {
        list[i].subtask[j].priority = p;
        sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    }
}

void To_Do::change_achiev (string t, int a) {
    int i = pos(t);
    list[i].achiev = a;
}

void To_Do::change_achiev (int ide, int a) {
    tuple<int,int> tup = pos(ide);
    int i = get<0>(tup);
    int j = get<1>(tup);
    if (j == -1) {
        list[i].achiev = a; 
    }
    else {
        list[i].subtask[j].achiev = a;
    }
}

void To_Do::change_priority_st (string st, string t, int p) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].priority = p;
    sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}

void To_Do::change_achiev_st (string st, string t, int a) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].achiev = a;
}

vector<string> To_Do::end (string t) {
    int i = pos(t);
    list[i].closing();
    vector<string> date = list[i].close.d_t_str();
    sort(list.begin(),list.end(),sort_priority);
    return date;
}

vector<string> To_Do::end (int ide) {
    tuple<int,int> tup = pos(ide);
    int i = get<0>(tup);
    int j = get<1>(tup);
    vector<string> date;
    if (j == -1) {
        list[i].closing();
        date = list[i].close.d_t_str();
        sort(list.begin(),list.end(),sort_priority); 
    }
    else {
        list[i].subtask[j].closing();
        date = list[i].subtask[j].close.d_t_str();
        sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    }
    return date;
}

vector<string> To_Do::end_st (string st, string t) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].closing();
    vector<string> date = list[i].subtask[j].close.d_t_str();
    sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    return date;
}

void To_Do::end_dated (string t, Date cl) {
    int i = pos(t);
    list[i].closing_dated(cl);
    sort(list.begin(),list.end(),sort_priority);
}

void To_Do::end_dated (int ide, Date cl) {
    tuple<int,int> tup = pos(ide);
    int i = get<0>(tup);
    int j = get<1>(tup);
    vector<string> date;
    if (j == -1) {
        list[i].closing_dated(cl);
        sort(list.begin(),list.end(),sort_priority); 
    }
    else {
        list[i].subtask[j].closing_dated(cl);
        sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
    }
}

void To_Do::end_st_dated (string st, string t, Date cl) {
    int i = pos(t);
    int j = pos_st(st,t);
    list[i].subtask[j].closing_dated(cl);
    sort(list[i].subtask.begin(),list[i].subtask.end(),sort_priority);
}