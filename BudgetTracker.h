#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "AuxiliaryMethods.h"
#include "Operation.h"
#include "BudgetTrackerFile.h"

using namespace std;

class BudgetTracker{

    vector <Operation> operations;
    BudgetTrackerFile budgetTrackerFile;
    const int LOGGED_USER_ID;
    bool checkDateIntegrity(int year, int month, int day);
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int insertDate();
    int checkNumberOfDaysInMonth(int month,int year);
    int getNewOperationId();
    string formatDateToReadable(int dateInteger);
    void operationsSort();

public:
    BudgetTracker(string filename) : budgetTrackerFile(filename){
        operations = budgetTrackerFile.readAllOperationsFromFile();
    }
    ~BudgetTracker(){}

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();

};


#endif
