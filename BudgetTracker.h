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

    vector <Operation> incomes;
    vector <Operation> expenses;

    BudgetTrackerFile incomesFile;
    BudgetTrackerFile expensesFile;

    const int LOGGED_USER_ID;
    bool checkDateIntegrity(int year, int month, int day);
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int insertDate();
    int checkNumberOfDaysInMonth(int month,int year);
    string formatDateToReadable(int dateInteger);
    void operationsSort();
    int choseDateAssignment();
    double showIncomes(int lowerRange, int upperRange);
    double showExpenses(int lowerRange, int upperRange);

public:
    BudgetTracker(string filename, string outcomesFilename) : incomesFile(filename),expensesFile(outcomesFilename){
        incomes = incomesFile.readAllOperationsFromFile();
        expenses = expensesFile.readAllOperationsFromFile();
    }
    ~BudgetTracker(){}

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();

};


#endif
