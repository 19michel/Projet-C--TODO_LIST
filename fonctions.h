#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <tuple>
#include "task.h"
#include "todo.h"
using namespace std;

#pragma once

vector<string> c_t_str (int argc, char**  argv);

vector<string> extract (string file);

void write (ofstream& ofs, const vector<string> & v_str, int i, int nb);

To_Do main_notxt(const vector<string> & v_str);

vector<string> main_add (const vector<string> & v_str, To_Do & list, int & i) ;

vector<string> main_close(const vector<string> & v_str, To_Do & list, int & i);

void main_add_dated (const vector<string> & v_str, To_Do & list, int & i) ;

void main_close_dated (const vector<string> & v_str, To_Do & list, int & i);

void main_change (const vector<string> & v_str, To_Do & list, int & i);

void main_comments (const vector<string> & v_str, To_Do & list, int & i);

void main_del (string file);

void main_man (const vector<string> & v_str, int & i);