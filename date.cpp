#include <iostream>
#include "date.h"
using namespace std;

Date::Date (int day, int month, int year, int hours, int minutes, int seconds) : d{day}, m{month}, y{year}, hou{hours}, min{minutes}, sec{seconds} {}

void Date::print () {cout << d << '/' << m << '/' << y << ' ' << hou << ':' << min << ':' << sec;}

vector<string> Date::d_t_str () {
    vector<string> date {};
    string str;
    str = to_string(d);
    date.push_back(str);
    str = to_string(m);
    date.push_back(str);
    str = to_string(y);
    date.push_back(str);
    str = to_string(hou);
    date.push_back(str);
    str = to_string(min);
    date.push_back(str);
    str = to_string(sec);
    date.push_back(str);
    return date;
}
