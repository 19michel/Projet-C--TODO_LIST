#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "task.h"
#include "todo.h"
#include "fonctions.h"
using namespace std;

int main(int argc, char** argv) {
    vector<string> v_str = c_t_str(argc, argv);
    vector<string> extr;
    ofstream ofs;
    To_Do list;
    string file;
    int i = 1;
    if (v_str.size() > i && v_str[i] == "--help") {
        i++;
        main_man(v_str, i);
        return 0;
    }
    
    if (v_str.size() > i && v_str[i] == "--file") {
        i++;
        file = v_str[i];
        i++;
    }
    else {
        file = "list.todo";
    }
    if (v_str.size() > i-1 && string(argv[i]) == "del")  {
            main_del(file);
            i++;
    }
    extr = extract(file);
    list = main_notxt(extr);
    ofs.open(file,ofstream::out | ofstream::app);
    while (i<v_str.size()) {
        if (v_str[i] == "print") {
            if (i+1<v_str.size() && v_str[i+1] == "--priority") {
                i=i+2;
                list.print(stoi(v_str[i]));
                i++;
            }
            else {
                list.print(0);
                i++;
            }
            continue;
        }
        if (v_str[i] == "add") {
            int j = i;
            vector<string> date = main_add(v_str, list, i);
            write(ofs,v_str,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            continue;
        }
        if (v_str[i] == "close") {
            int j = i;
            vector<string> date = main_close(v_str, list, i);
            write(ofs,v_str,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            continue;
        }
        if (v_str[i] == "del") {
            main_del(file);
            i += 1;
            To_Do list {};
            continue;
        }
        if (v_str[i] == "change") {
            int j = i;
            main_change(v_str, list, i);
            write(ofs,v_str,j,i-j);
            continue;
        }
        if (v_str[i] == "comments") {
            int j = i;
            main_comments(v_str, list, i);
            write(ofs,v_str,j,i-j);
            continue;
        }
    }

    ofs.close();

    return 0;
};
