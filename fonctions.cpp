#include "fonctions.h"
using namespace std;

vector<string> c_t_str (int argc, char** argv) {
    vector<string> v_str {};
    for (int i {}; i<argc; i++) {
        v_str.push_back(string(argv[i]));
    }
    return v_str;
}

vector<string> main_add (const vector<string> & v_str, To_Do & list, int & i) {
    string title = "No title";
    string description = "No description";
    string st;
    int id;
    int p = 0;
    bool test_st = false;
    bool test_id = false;
    i++;
    while ((i<v_str.size()) && (v_str[i][0]=='-' && v_str[i][1]=='-')) {
        if (v_str[i] == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--description") {
            i++;
            description = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--priority") {
            i++;
            p = stoi(v_str[i]);
            i++;
            continue;
        }
        if (v_str[i] == "--maintask") {
            i++;
            st=v_str[i];
            test_st = true;
            i++;
            continue;
        }
        if (string(v_str[i]) == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    vector<string> date;
    if (test_id) {date = list.add_st(title, id, description, p);}
    else {
        if (test_st) {date = list.add_st(title, st, description, p);}
        else {date = list.add(title, description, p);}
    }
    return date;
}

void main_add_dated (const vector<string> &  v_str, To_Do & list, int & i) {
    string title = "No title";
    string description = "No description";
    string st;
    Date op;
    int id;
    int p = 0;
    bool test_st = false;
    bool test_id = false;
    i++;
    while ((i<v_str.size()) && (v_str[i][0]=='-' && v_str[i][1]=='-')) {
        if (v_str[i] == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--description") {
            i++;
            description = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--priority") {
            i++;
            p = stoi(v_str[i]);
            i++;
            continue;
        }
        if (v_str[i] == "--date") {
            i++;
            int d = stoi(v_str[i]);
            i++;
            int m = stoi(v_str[i]);
            i++;
            int y = stoi(v_str[i]);
            i++;
            int hou = stoi(v_str[i]);
            i++;
            int min = stoi(v_str[i]);
            i++;
            int sec = stoi(v_str[i]);
            op = Date(d, m, y, hou, min, sec);
            i++;
            continue;   
        }
        if (v_str[i] == "--maintask") {
            i++;
            st=v_str[i];
            test_st = true;
            i++;
            continue;
        }
        if (v_str[i] == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_id) {list.add_st_dated(title, id, description, p, op);}
    else {
        if (test_st) {list.add_st_dated(title, st, description, p, op);}
        else {list.add_dated(title, description, p, op);}
    }
}

vector<string> main_close (const vector<string> & v_str, To_Do & list, int & i) {
    string title;
    string st;
    int id;
    bool test_st = false;
    bool test_id = false;
    i++;
    while ((i<v_str.size()) && (string(v_str[i])[0]=='-' && string(v_str[i])[1]=='-')) {
        if (string(v_str[i]) == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (string(v_str[i]) == "--maintask") {
            i++;
            st=string(v_str[i]);
            test_st = true;
            i++;
            continue;
        }
        if (string(v_str[i]) == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    vector<string> date;
    if (test_id) {
        date = list.close(id);
    }
    else {
        if (test_st) {date = list.close_st(title, st);}
        else {date = list.close(title);}
    }
    return date;
}

void main_close_dated (const vector<string> & v_str, To_Do & list, int & i) {
    string title;
    string st;
    Date cl;
    int id;
    bool test_st = false;
    bool test_id = false;
    i++;
    while ((i<v_str.size()) && (v_str[i][0]=='-' && v_str[i][1]=='-')) {
        if (v_str[i] == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--date") {
            i++;
            int d = stoi(v_str[i]);
            i++;
            int m = stoi(v_str[i]);
            i++;
            int y = stoi(v_str[i]);
            i++;
            int hou = stoi(v_str[i]);
            i++;
            int min = stoi(v_str[i]);
            i++;
            int sec = stoi(v_str[i]);
            cl = Date(d, m, y, hou, min, sec);
            i++;
            continue;   
        }
        if (v_str[i] == "--maintask") {
            i++;
            st=v_str[i];
            test_st = true;
            i++;
            continue;
        }
        if (string(v_str[i]) == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_id) {list.close_dated(id, cl);}
    else {
        if (test_st) {list.close_st_dated(title, st, cl);}
        else {list.close_dated(title, cl);}
    }
}

void write (string file, const vector<string> & argv, int i, int nb) {
    ofstream ofs;
    ofs.open(file,ofstream::out | ofstream::app);
    for (int j = 0; j<nb; j++) {
        ofs << argv[i+j] << endl;
    }
    ofs.close();
}


To_Do main_no_write (const vector<string> & v_str) {
    To_Do list; 
    int argc = v_str.size();
    int i = 0;
    while (i<argc) {
        if (v_str[i] == "add") {
            main_add_dated(v_str, list, i);
            continue;
        }
        if (v_str[i] == "close") {
            main_close_dated(v_str, list, i);
            continue;
        }
        if (v_str[i] == "change") {
            main_change(v_str, list, i);
            continue;
        }
        if (v_str[i] == "comments") {
            main_comments(v_str, list, i);
            continue;
        }
    }

    return list;
};

vector<string> extract (string file) {
    ifstream ifs;
    ifs.open(file);
    vector<string> extr {};
    string line;
    while (getline(ifs, line)) {
        extr.push_back(line);
    }
    cout << endl;;
    ifs.close();
    return extr;
}

void main_del (string file) {
    remove(file.c_str());
};

void main_change (const vector<string> & v_str, To_Do & list, int & i) {
    string title;
    string st;
    int id;
    bool test_st = false;
    bool test_id = false;
    int func {};
    int p {};
    int ac {};
    i++;
    while ((i<v_str.size()) && (v_str[i][0]=='-' && v_str[i][1]=='-')) {
        if (v_str[i] == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--priority") {
            i++;
            p = stoi(v_str[i]);
            i++;
            continue;
        }
        if (v_str[i] == "--achiev") {
            i++;
            ac = stoi(v_str[i]);
            func = 1;
            i++;
            continue;
        }
        if (v_str[i] == "--maintask") {
            i++;
            st=v_str[i];
            test_st = true;
            i++;
            continue;
        }
        if (string(v_str[i]) == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_id) {
        if (func == 0) {
            list.change_priority(id, p);
        }
        if (func == 1) {
            list.change_achiev(id, ac);
        }
    }
    else {
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
    }
}

void main_comments (const vector<string> & v_str, To_Do & list, int & i) {
    string title;
    string st;
    string comments;
    int id;
    bool test_st = false;
    bool test_id = false;
    i++;
    while ((i<v_str.size()) && (v_str[i][0]=='-' && v_str[i][1]=='-')) {
        if (v_str[i] == "--title") {
            i++;
            title = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--comments") {
            i++;
            comments = v_str[i];
            i++;
            continue;
        }
        if (v_str[i] == "--maintask") {
            i++;
            st=v_str[i];
            test_st = true;
            i++;
            continue;
        }
        if (string(v_str[i]) == "--id") {
            i++;
            id = stoi(v_str[i]);
            test_id = true;
            i++;
            continue;
        }
        i++;
    }
    if (test_id) {list.add_comments(id, comments);}
    else {
        if (test_st) {list.add_comments_st(title, st, comments);}
        else {list.add_comments(title, comments);} 
    }   
}

void main_man (const vector<string> & v_str, int & i) {
    if (v_str.size() > i && v_str[i] == "add") {
        system("bash manuel/manuel_add.bat");
    }
    else if (v_str.size() > i && v_str[i] == "close") {
        system("bash manuel/manuel_close.bat");
    }
    else if (v_str.size() > i && v_str[i] == "comments") {
        system("bash manuel/manuel_comments.bat");
    }
    else if (v_str.size() > i && v_str[i] == "change") {
        system("bash manuel/manuel_change.bat");
    }
    else if (v_str.size() > i && v_str[i] == "del") {
        system("bash manuel/manuel_del.bat");
    }
    else if (v_str.size() > i && v_str[i] == "print") {
        system("bash manuel/manuel_print.bat");
    }
    else {
        system("bash manuel/manuel_todo.bat");
    }
}