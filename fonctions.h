#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <tuple>
#include "task.h"
#include "todo.h"

#pragma once


std::vector<std::string> extract ();

void write (std::ofstream& ofs, char** argv, int i, int nb);

void write (std::ofstream& ofs, const char** argv, int i, int nb);

To_Do main_notxt(int argc, std::vector<std::string> extr);

std::tuple<int,To_Do,const char**> main_add (int argc, char** argv, To_Do list, int i) ;

std::tuple<int,To_Do,const char**> main_close(int argc, char** argv, To_Do list, int i);

std::tuple<int,To_Do> main_add_str (int argc, std::vector<std::string> argv, To_Do list, int i) ;

std::tuple<int,To_Do> main_close_str (int argc, std::vector<std::string> argv, To_Do list, int i);

std::tuple<int,To_Do> main_change (int argc, char** argv, To_Do list, int i);

std::tuple<int,To_Do> main_comments (int argc, char** argv, To_Do list, int i);

std::tuple<int,To_Do> main_change_str (int argc, std::vector<std::string> argv, To_Do list, int i) ;

std::tuple<int,To_Do> main_comments_str (int argc, std::vector<std::string> argv, To_Do list, int i);

void main_del ();