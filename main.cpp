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
    vector<string> extr = extract();
    ofstream ofs;
    ofs.open("list.todo",ofstream::out | ofstream::app);
    To_Do list; 
    list = main_notxt(extr);
    int size = v_str.size();
    int i = 1;
    while (i<size) {
        if (string(v_str[i]) == "print") {
            if (i+1<size && string(v_str[i+1]) == "--priority") {
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
        if (string(v_str[i]) == "add") {
            int j = i;
            vector<string> date = main_add(v_str, list, i);
            write(ofs,v_str,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            continue;
        }
        if (string(v_str[i]) == "close") {
            int j = i;
            vector<string> date = main_close(v_str, list, i);
            write(ofs,v_str,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            continue;
        }
        if (string(v_str[i]) == "del") {
            main_del();
            i += 1;
            To_Do list {};
            continue;
        }
        if (string(v_str[i]) == "change") {
            int j = i;
            main_change(v_str, list, i);
            write(ofs,v_str,j,i-j);
            continue;
        }
        if (string(v_str[i]) == "comments") {
            int j = i;
            main_comments(v_str, list, i);
            write(ofs,v_str,j,i-j);
            continue;
        }
    }

    ofs.close();

    return 0;
};
