#include "Application.h"

void Application::userRegistration(){
    usersMenager.userRegistration();
}

void Application::logOut(){
    usersMenager.logOut();

    delete budgetTracker;
    budgetTracker = NULL;
}

void Application::logIn(){
    usersMenager.logIn();
    if (usersMenager.checkIfUserIsLoggedIn()){
    budgetTracker = new BudgetTracker(INCOMES_FILENAME,EXPENSES_FILENAME, usersMenager.getLoggedUserId());
    }
}

void Application::changeLoggedUserPassword(){
    usersMenager.changePassword();
}

void Application::addIncome(){
    budgetTracker -> addIncome();
}

void Application::addExpense(){
    budgetTracker -> addExpense();
}

void Application::currentMonthBalance(){
    budgetTracker -> currentMonthBalance();
}

void Application::lastMonthBalance(){
    budgetTracker -> lastMonthBalance();
}

void Application::selectedPeriodBalance(){
    budgetTracker -> selectedPeriodBalance();
}

bool Application::checkIfUserIsLoggedIn(){
    if (usersMenager.checkIfUserIsLoggedIn())
        return true;
    else
        return false;
}


char Application::choseOptionFromMainMenu(){
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

char Application::choseOptionFromUserMenu(){
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << '\n';
    cout << "---------------------------" << '\n';
    cout << "1. Dodaj przychod" << '\n';
    cout << "2. Dodaj wydatek" << '\n';
    cout << "3. Bilans z biezacego miesiaca" << '\n';
    cout << "4. Bilans z poprzedniego miesiaca" << '\n';
    cout << "5. Bilans z wybranego okresu" << '\n';
    cout << "---------------------------" << '\n';
    cout << "6. Zmien haslo" << '\n';
    cout << "7. Wyloguj sie" << '\n';
    cout << "---------------------------" << '\n';
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::readChar();
    return choice;
}
