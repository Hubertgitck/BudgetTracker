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
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int insertDate();
    int choseDateAssignment();
    int checkNumberOfDaysInMonth(int month,int year);
    string formatDateToReadable(int dateInteger);
    bool checkDateIntegrity(int year, int month, int day);
    void incomesSort();
    void expensesSort();
    double showIncomes(int lowerRange, int upperRange);
    double showExpenses(int lowerRange, int upperRange);

public:
    BudgetTracker(string incomesFilename, string expensesFilename, int loggedUserId) :
        incomesFile(incomesFilename),expensesFile(expensesFilename), LOGGED_USER_ID(loggedUserId){

        incomes = incomesFile.readAllOperationsFromFile(LOGGED_USER_ID);
        expenses = expensesFile.readAllOperationsFromFile(LOGGED_USER_ID);
    }
    ~BudgetTracker(){}

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();

};


#endif
