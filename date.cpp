#include <iostream>
#include "date.h"

Date::Date (int day, int month, int year, int hours, int minutes, int seconds) : d{day}, m{month}, y{year}, hou{hours}, min{minutes}, sec{seconds} {}

void Date::print () {std::cout << d << '/' << m << '/' << y << ' ' << hou << ':' << min << ':' << sec;}

const char** Date::to_str () {
    const char* date [6];
    char str;
    str = char(d);
    date[0] = &str;
    str = char(m);
    date[1] = &str;
    str = char(y);
    date[2] = &str;
    str = char(hou);
    date[3] = &str;
    str = char(min);
    date[4] = &str;
    str = char(sec);
    date[5] = &str;
    return date;
}
