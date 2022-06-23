#ifndef BUDGETTRACKER_H
#define BUDGETTRACKER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "AuxiliaryMethods.h"
#include "Operation.h"
#include "BudgetTrackerFile.h"
#include "Date.h"

using namespace std;

class BudgetTracker{

    vector <Operation> incomes;
    vector <Operation> expenses;

    BudgetTrackerFile incomesFile;
    BudgetTrackerFile expensesFile;
    Date date;

    const int LOGGED_USER_ID;
    int choseDateAssignment();
    string formatDateToReadable(int dateInteger);
    void incomesSort();
    void expensesSort();
    double showIncomes(int lowerRange, int upperRange);
    double showExpenses(int lowerRange, int upperRange);
    bool checkSelectedPeriodCorrectnes(int selectedPeriodLowerRange, int selectedPeriodUpperRange);

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
