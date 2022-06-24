#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

#include "BudgetTracker.h"
#include "UsersMenager.h"

using namespace std;

class Application{

    UsersMenager usersMenager;
    BudgetTracker *budgetTracker;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    Application(string usersFilename, string incomesFilename, string expensesFilename ) :
        usersMenager(usersFilename),INCOMES_FILENAME(incomesFilename),EXPENSES_FILENAME(expensesFilename) {

        budgetTracker = NULL;
    };
    ~Application(){
        delete budgetTracker;
        budgetTracker = NULL;
    };

    char choseOptionFromMainMenu();
    char choseOptionFromUserMenu();
    bool checkIfUserIsLoggedIn();

    void userRegistration();
    void logOut();
    void logIn();
    void changeLoggedUserPassword();
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void selectedPeriodBalance();
};


#endif
