#include <vector>
#include <string>
using namespace std;

#pragma once

class Date {
private:
    int d;
    int m;
    int y;
    int hou;
    int min;
    int sec;
public:
    Date (int day = 01, int month = 01, int year = 2000, int hours = 0, int minutes = 0, int seconds = 0);
    void print ();
    vector<string> d_t_str ();
};



