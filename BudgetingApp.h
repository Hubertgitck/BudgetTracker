#ifndef BUDGETINGAPP_H
#define BUDGETINGAPP_H

#include <iostream>

#include "BudgetTracker.h"
#include "UsersMenager.h"

using namespace std;

class BudgetingApp{

    UsersMenager usersMenager;
    string USERS_FILENAME;

public:
    BudgetingApp(string filename) : usersMenager(filename){}
    ~BudgetingApp(){}

    char choseOptionFromMainMenu();
    bool checkIfUserIsLoggedIn();

    void userRegistration();
    void logOut();
    void logIn();
    void changeLoggedUserPassword();
};


#endif
