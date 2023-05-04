#pragma once
#ifndef ATHLETES_H
#include <string>
using namespace std;

struct Athletes {
    string name;
    string score;
    string school;
    double feet;
    double inches;
    string max;
    string throw1, throw2, throw3;
    string bestThrow;
    int flightNum = 0;
    double bestDouble;
};

#endif
