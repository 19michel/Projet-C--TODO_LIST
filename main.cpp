#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "task.h"
#include "todo.h"
#include "fonctions.h"

int main (int argc, char** argv) {
    std::vector<std::string> extr = extract();
    std::ofstream ofs;
    ofs.open("list.todo",std::ofstream::out | std::ofstream::app);
    To_Do list; 
    list = main_notxt(extr.size(), extr);
    int i = 1;
    while (i<argc) {
        if (std::string(argv[i]) == "print") {
            if (i+1<argc && std::string(argv[i+1]) == "--priority") {
                i=i+2;
                list.print(std::stoi(argv[i]));
                i++;
            }
            else {
                list.print(0);
                i++;
            }
            continue;
        }
        if (std::string(argv[i]) == "add") {
            std::cout << "add" ;
            std::tuple<int,To_Do,const char**> tup = main_add(argc, argv, list, i);
            int inew = std::get<0>(tup);
            list = std::get<1>(tup);
            write(ofs,argv,i,inew-i);
            const char** date = std::get<2>(tup);
            const char* word [1];
            word[0] = "--date";
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            i = inew;
            continue;
        }
        if (std::string(argv[i]) == "close") {
            std::tuple<int,To_Do,const char**> tup = main_close(argc, argv, list, i);
            int inew = std::get<0>(tup);
            list = std::get<1>(tup);
            write(ofs,argv,i,inew-i);
            const char** date = std::get<2>(tup);
            const char* word [1];
            word[0] = "--date";
            write(ofs,word,0,1);
            write(ofs,date,0,6);
            i = inew;
            continue;
        }
        if (std::string(argv[i]) == "del") {
            main_del();
            i += 1;
            To_Do list {};
            continue;
        }
        if (std::string(argv[i]) == "change") {
            std::tuple<int,To_Do> tup = main_change(argc, argv, list, i);
            int inew = std::get<0>(tup);
            list = std::get<1>(tup);
            write(ofs,argv,i,inew-i);
            i = inew;
            continue;
        }
        if (std::string(argv[i]) == "comments") {
            std::tuple<int,To_Do> tup = main_comments(argc, argv, list, i);
            int inew = std::get<0>(tup);
            list = std::get<1>(tup);
            write(ofs,argv,i,inew-i);
            i = inew;
            continue;
        }
    }

    ofs.close();

    return 0;
};
