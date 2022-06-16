#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include <ctime>
#include <string>

#include "AuxiliaryMethods.h"

using namespace std;

class BudgetTracker{

    const int LOGGED_USER_ID;

public:
    long int getCurrentDate();
    long int insertDate();
    int checkNumberOfDaysInMonth(int month,int year);
    BudgetTracker(){}
    ~BudgetTracker(){}

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();

};


#endif
