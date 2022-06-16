#include "BudgetingApp.h"

void BudgetingApp::userRegistration(){
    usersMenager.userRegistration();
}

void BudgetingApp::logOut(){
    usersMenager.logOut();
}
void BudgetingApp::logIn(){
    usersMenager.logIn();
}
void BudgetingApp::changeLoggedUserPassword(){
    usersMenager.changePassword();
}
bool BudgetingApp::checkIfUserIsLoggedIn(){
    if (usersMenager.checkIfUserIsLoggedIn())
        return true;
    else
        return false;
}

char BudgetingApp::choseOptionFromMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << '\n';
    cout << "---------------------------" << '\n';
    cout << "1. Rejestracja" << '\n';
    cout << "2. Logowanie" << '\n';
    cout << "9. Koniec programu" << '\n';
    cout << "---------------------------" << '\n';
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::readChar();
    return choice;
}
