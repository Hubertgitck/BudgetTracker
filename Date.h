#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class Date{
public:
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int insertDate();
    int checkNumberOfDaysInMonth(int month,int year);

    bool checkDateIntegrity(int year, int month, int day);

};



#endif
