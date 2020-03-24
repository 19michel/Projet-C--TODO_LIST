#include <vector>
#include "task.h"

#pragma once 

class To_Do {
private:
    int nb;
    std::vector<Task> list; 

public: 

    To_Do () ;

    void print () ;

    void print (int p) ;

    vector<string> add (std::string t, std::string d, int p) ;

    vector<string> add_st (std::string st, std::string t, std::string d, int p) ;

    void add_dated (std::string t, std::string d, int p, Date op) ;

    void add_st_dated (std::string st, std::string t, std::string d, int p, Date op) ;

    int pos (std::string t) ;

    int pos_st (std::string st, std::string t) ;

    void change_priority (std::string t, int p) ;

    void add_comments (std::string t, std::string c) ;

    void change_priority_st (std::string st, std::string t, int p) ;

    void add_comments_st (std::string st, std::string t, std::string c) ;

    void change_achiev (std::string t, int a) ;

    void change_achiev_st (std::string st, std::string t, int a) ;

    vector<string> end (std::string t) ;

    vector<string> end_st (std::string st, std::string t) ;

    void end_dated (std::string t, Date cl) ;

    void end_st_dated (std::string st, std::string t, Date cl) ;
};