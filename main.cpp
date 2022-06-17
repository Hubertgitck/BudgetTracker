#include <iostream>

#include "BudgetingApp.h"

using namespace std;
/*
int main(){
    char choice;
    BudgetingApp budgetingApp("users.xml");

    while (true){
        if (budgetingApp.checkIfUserIsLoggedIn() == 0){
            choice = budgetingApp.choseOptionFromMainMenu();

            switch (choice){
            case '1':
                budgetingApp.userRegistration();
                break;
            case '2':
                budgetingApp.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << '\n' << "Nie ma takiej opcji w menu." << '\n' << '\n';
                system("pause");
                break;
            }
        }
    }
}
*/

#include "BudgetTracker.h"
int main(){

    BudgetTracker budgetTracker;

    //budgetTracker.getCurrentDate();
    //budgetTracker.insertDate();

    budgetTracker.addIncome();
    //budgetTracker.addExpense();
    budgetTracker.currentMonthBalance();
}

