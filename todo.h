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

    void print (int p) ;

    vector<string> add (string t, string d, int p) ;

    vector<string> add_st (string st, string t, string d, int p) ;

    vector<string> add_st (string st, int ide, string d, int p) ;

    void add_dated (string t, string d, int p, Date op) ;

    void add_st_dated (string st, string t, string d, int p, Date op) ;

    void add_st_dated (string st, int ide, string d, int p, Date op) ;

    int pos (string t) ;

    tuple<int,int> pos (int ide) ;

    int pos_st (string st, string t) ;

    void change_priority (string t, int p) ;

    void change_priority (int ide, int p) ;

    void add_comments (string t, string c) ;

    void add_comments (int ide, string c) ;

    void change_priority_st (string st, string t, int p) ;

    void add_comments_st (string st, string t, string c) ;

    void change_achiev (string t, int a) ;

    void change_achiev (int ide, int a) ;

    void change_achiev_st (string st, string t, int a) ;

    vector<string> end (string t) ;

    vector<string> end (int ide) ;

    vector<string> end_st (string st, string t) ;

    void end_dated (string t, Date cl) ;

    void end_dated (int ide, Date cl) ;

    void end_st_dated (string st, string t, Date cl) ;
};