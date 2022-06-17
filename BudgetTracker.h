#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>

#include "AuxiliaryMethods.h"
#include "Operation.h"

using namespace std;

class BudgetTracker{

    vector <Operation> operations;
    const int LOGGED_USER_ID;

    bool checkDateIntegrity(int year, int month, int day);
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

public:
    int getCurrentDate();
    int insertDate();
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
