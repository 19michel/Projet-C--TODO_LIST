#include "fonctions.h"

std::tuple<int,To_Do,const char**> main_add (int argc, char** argv, To_Do list, int i) {
    std::string title;
    std::string description;
    std::string st;
    int p;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--description") {
            i++;
            description = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--priority") {
            i++;
            p = std::stoi(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    const char** date;
    if (test_st) {date = list.add_st(title, st, description, p);}
    else {date = list.add(title, description, p);}
    std::cout << date;
    std::tuple<int,To_Do,const char**> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    std::get<2>(out) = date;
    return out;
}

std::tuple<int,To_Do> main_add_str (int argc, std::vector<std::string> argv, To_Do list, int i) {
    std::string title;
    std::string description;
    std::string st;
    Date op;
    int p;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--description") {
            i++;
            description = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--priority") {
            i++;
            p = std::stoi(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--date") {
            i++;
            int d = std::stoi(argv[i]);
            i++;
            int m = std::stoi(argv[i]);
            i++;
            int y = std::stoi(argv[i]);
            i++;
            int hou = std::stoi(argv[i]);
            i++;
            int min = std::stoi(argv[i]);
            i++;
            int sec = std::stoi(argv[i]);
            op = Date(d, m, y, hou, min, sec);
            i++;
            continue;   
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {list.add_st_dated(title, st, description, p, op);}
    else {list.add_dated(title, description, p, op);}
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;
}

std::tuple<int,To_Do,const char**> main_close (int argc, char** argv, To_Do list, int i) {
    std::string title;
    std::string st;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    const char** date;
    if (test_st) {date = list.end_st(title, st);}
    else {date = list.end(title);}
    std::tuple<int,To_Do,const char**> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    std::get<2>(out) = date;
    return out;
}

std::tuple<int,To_Do> main_close_str (int argc, std::vector<std::string> argv, To_Do list, int i) {
    std::string title;
    std::string st;
    Date cl;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--date") {
            i++;
            int d = std::stoi(argv[i]);
            i++;
            int m = std::stoi(argv[i]);
            i++;
            int y = std::stoi(argv[i]);
            i++;
            int hou = std::stoi(argv[i]);
            i++;
            int min = std::stoi(argv[i]);
            i++;
            int sec = std::stoi(argv[i]);
            cl = Date(d, m, y, hou, min, sec);
            i++;
            continue;   
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {list.end_st_dated(title, st, cl);}
    else {list.end_dated(title, cl);}
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;
}

void write (std::ofstream& ofs, char** argv, int i, int nb) {
    for (int j = 0; j<nb; j++) {
        ofs << argv[i+j] << std::endl;
    }
}

void write (std::ofstream& ofs, const char** argv, int i, int nb) {
    for (int j = 0; j<nb; j++) {
        ofs << argv[i+j] << std::endl;
    }
}

To_Do main_notxt (int argc, std::vector<std::string> extr) {
    To_Do list; 
    int nb = extr.size();
    int i = 0;
    while (i<nb) {
        if (std::string(extr[i]) == "add") {
            std::tuple<int,To_Do> tup = main_add_str(argc, extr, list, i);
            i = std::get<0>(tup);
            list = std::get<1>(tup);
            continue;
        }
        if (std::string(extr[i]) == "close") {
            std::tuple<int,To_Do> tup = main_close_str(argc, extr, list, i);
            i = std::get<0>(tup);
            list = std::get<1>(tup);
            continue;
        }
        if (std::string(extr[i]) == "del") {
            main_del();
            i += 1;
            To_Do list {};
            continue;
        }
        if (std::string(extr[i]) == "change") {
            std::tuple<int,To_Do> tup = main_change_str(argc, extr, list, i);
            i = std::get<0>(tup);
            list = std::get<1>(tup);
            continue;
        }
        if (std::string(extr[i]) == "comments") {
            std::tuple<int,To_Do> tup = main_comments_str(argc, extr, list, i);
            i = std::get<0>(tup);
            list = std::get<1>(tup);
            continue;
        }
    }

    return list;
};

std::vector<std::string> extract () {
    std::ifstream ifs;
    ifs.open("list.todo");
    std::vector<std::string> extr {};
    std::string line;
    while (std::getline(ifs, line)) {
        extr.push_back(line);
    }
    std::cout << std::endl;;
    ifs.close();
    return extr;
}

void main_del () {
    std::ofstream ofs;
    ofs.open("list.todo", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
};

std::tuple<int,To_Do> main_change (int argc, char** argv, To_Do list, int i) {
    std::string title;
    std::string st;
    bool test_st = false;
    int func {};
    int p {};
    int ac {};
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--priority") {
            i++;
            p = std::stoi(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--achiev") {
            i++;
            ac = std::stoi(argv[i]);
            func = 1;
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {
        if (func == 0) {
            list.change_priority_st(title, st, p);
        }
        if (func == 1) {
            list.change_achiev_st(title, st, ac);
        }
    }
    else {
        if (func == 0) {
            list.change_priority(title, p);
        }
        if (func == 1) {
            list.change_achiev(title, ac);
        }
    }
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;
}

std::tuple<int,To_Do> main_change_str (int argc, std::vector<std::string> argv, To_Do list, int i) {
    std::string title;
    std::string st;
    bool test_st = false;
    int func {};
    int p {};
    int ac {};
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = argv[i];
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--priority") {
            i++;
            p = std::stoi(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--achiev") {
            i++;
            ac = std::stoi(argv[i]);
            func = 1;
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {
        if (func == 0) {
            list.change_priority_st(title, st, p);
        }
        if (func == 1) {
            list.change_achiev_st(title, st, ac);
        }
    }
    else {
        if (func == 0) {
            list.change_priority(title, p);
        }
        if (func == 1) {
            list.change_achiev(title, ac);
        }
    }
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;
}

std::tuple<int,To_Do> main_comments (int argc, char** argv, To_Do list, int i) {
    std::string title;
    std::string st;
    std::string comments;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = std::string(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--comments") {
            i++;
            comments = std::string(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {list.add_comments_st(title, st, comments);}
    else {list.add_comments(title, comments);}
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;    
}

std::tuple<int,To_Do> main_comments_str (int argc, std::vector<std::string> argv, To_Do list, int i) {
    std::string title;
    std::string st;
    std::string comments;
    bool test_st = false;
    i++;
    while ((i<argc) && (std::string(argv[i])[0]=='-' && std::string(argv[i])[1]=='-')) {
        if (std::string(argv[i]) == "--title") {
            i++;
            title = std::string(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--comments") {
            i++;
            comments = std::string(argv[i]);
            i++;
            continue;
        }
        if (std::string(argv[i]) == "--subtask") {
            i++;
            st=std::string(argv[i]);
            test_st = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_st) {list.add_comments_st(title, st, comments);}
    else {list.add_comments(title, comments);}
    std::tuple<int,To_Do> out;
    std::get<0>(out) = i;
    std::get<1>(out) = list;
    return out;    
}