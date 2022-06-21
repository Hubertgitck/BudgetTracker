#include <iostream>

#include "Application.h"

using namespace std;

int main(){
    char choice;
    Application application("users.xml","incomes.xml","outcomes.xml");

    while (true){
        if (application.checkIfUserIsLoggedIn() == 0){
            choice = application.choseOptionFromMainMenu();
            switch (choice){
            case '1':
                application.userRegistration();
                break;
            case '2':
                application.logIn();
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
        else{
            choice = application.choseOptionFromUserMenu();

            switch (choice){
            case '1':
                application.addIncome();
                break;
            case '2':
                application.addExpense();
                break;
            case '3':
                application.currentMonthBalance();
                break;
            case '4':
                application.lastMonthBalance();
                break;
            case '5':
                application.selectedPeriodBalance();
                break;
            case '6':
                application.changeLoggedUserPassword();
                break;
            case '7':
                application.logOut();
                break;
            }
        }
    }
}

/*
#include "BudgetTracker.h"
int main(){

    BudgetTracker budgetTracker("incomes.xml","outcomes.xml");

    //budgetTracker.getCurrentDate();
    //budgetTracker.insertDate();

    //budgetTracker.addIncome();budgetTracker.addIncome();
    //budgetTracker.addExpense();budgetTracker.addExpense();
    //budgetTracker.addIncome(); budgetTracker.addExpense();
    budgetTracker.currentMonthBalance();
    budgetTracker.lastMonthBalance();
    budgetTracker.selectedPeriodBalance();

}
*/
