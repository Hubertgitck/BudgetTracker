#include "BudgetTracker.h"

void BudgetTracker::addIncome(){
    Operation operation;
    string amount="";

    operation.setOperationId(incomesFile.getLastOperationId() + 1);
    operation.setUserId(LOGGED_USER_ID);
    operation.setDate(choseDateAssignment());

    cout << '\n' << "Czego dotyczy przychod? ";
    operation.setDescription(AuxiliaryMethods::readLine());

    cout << '\n' << "Podaj kwote przychodu: ";
    amount = AuxiliaryMethods::readLine();
    amount = AuxiliaryMethods::convertCommaToDot(amount);
    operation.setAmount(AuxiliaryMethods::convertStringTodouble(amount));

    incomes.push_back(operation);
    incomesFile.addNewOperationToFile(operation);

    cout << '\n' << "Operacja dodana pomyslnie " << '\n' ;
    system("pause");
}

void BudgetTracker::addExpense(){
    Operation operation;
    string amount="";

    operation.setOperationId(expensesFile.getLastOperationId() + 1);
    operation.setUserId(LOGGED_USER_ID);
    operation.setDate(choseDateAssignment());

    cout << '\n' << "Czego dotyczy wydatek? ";
    operation.setDescription(AuxiliaryMethods::readLine());

    cout << '\n' << "Podaj kwote wydatku: ";
    amount = AuxiliaryMethods::readLine();
    amount = AuxiliaryMethods::convertCommaToDot(amount);

    operation.setAmount(AuxiliaryMethods::convertStringTodouble(amount)*(-1)); //*-1 because its an expense
    expenses.push_back(operation);
    expensesFile.addNewOperationToFile(operation);

    cout << '\n' << "Operacja dodana pomyslnie " << '\n' ;
    system("pause");
}

void BudgetTracker::currentMonthBalance(){
    int currentMonthLowerRange = 0, currentMonthUpperRange = 0;
    double expenses = 0, incomes = 0, balance = 0;

    currentMonthLowerRange = date.getCurrentDate() - date.getCurrentDay();
    currentMonthUpperRange = date.getCurrentDate();

    cout << setprecision(15);
    cout << "<<<< BILANS OBECNEGO MIESIACA >>>>" << '\n';

    //executing sorting function
    incomesSort();
    expensesSort();

    incomes = showIncomes(currentMonthLowerRange, currentMonthUpperRange);
    expenses = showExpenses(currentMonthLowerRange, currentMonthUpperRange);
    balance = incomes + expenses;

    cout << '\n' << "Suma przychodow wynosi: " << incomes;
    cout << '\n' << "Suma wydatkow wynosi: " << expenses;
    cout << '\n' << "BILANS: " << balance << '\n';
    system("pause");
}

void BudgetTracker::lastMonthBalance(){
    int lastMonthLowerRange = 0, lastMonthUpperRange = 0;
    double expenses = 0, incomes = 0, balance = 0;
    lastMonthUpperRange = date.getCurrentDate() - date.getCurrentDay();

    if (date.getCurrentMonth() != 1){
        lastMonthLowerRange = date.getCurrentDate() - date.getCurrentDay() - 100;
    }
    else{
        lastMonthLowerRange = date.getCurrentDate() - date.getCurrentDay() - 8900;
    }

    cout << setprecision(15);
    cout << "<<<< BILANS OSTATNIEGO MIESIACA >>>>" << '\n';

    //executing sorting function
    incomesSort();
    expensesSort();

    incomes = showIncomes(lastMonthLowerRange, lastMonthUpperRange);
    expenses = showExpenses(lastMonthLowerRange, lastMonthUpperRange);
    balance = incomes + expenses;

    cout << '\n' << "Suma przychodow wynosi: " << incomes;
    cout << '\n' << "Suma wydatkow wynosi: " << expenses;
    cout << '\n' << "BILANS: " << balance << '\n';
    system("pause");
}

void BudgetTracker::selectedPeriodBalance(){
    int selectedPeriodLowerRange = 0, selectedPeriodUpperRange = 0;
    double incomes = 0, expenses = 0, balance = 0;

    do{
    cout << '\n' << "Podaj date poczatkowa: ";
    selectedPeriodLowerRange = date.insertDate();
    cout << '\n' << "Podaj date koncowa: ";
    selectedPeriodUpperRange = date.insertDate();

    }while (!checkSelectedPeriodCorrectnes(selectedPeriodLowerRange, selectedPeriodUpperRange));

    cout << setprecision(15);
    cout << "<<<< BILANS Z OKRESU OD " << AuxiliaryMethods::formatDateToReadable(selectedPeriodLowerRange) <<
    " DO " << AuxiliaryMethods::formatDateToReadable(selectedPeriodUpperRange) << " >>>>" << '\n';

    //executing sorting function
    incomesSort();
    expensesSort();

    incomes = showIncomes(selectedPeriodLowerRange, selectedPeriodUpperRange);
    expenses = showExpenses(selectedPeriodLowerRange, selectedPeriodUpperRange);
    balance = incomes + expenses;

    cout << '\n' << "Suma przychodow wynosi: " << incomes;
    cout << '\n' << "Suma wydatkow wynosi: " << expenses;
    cout << '\n' << "BILANS: " << balance << '\n';
    system("pause");
}

int BudgetTracker::choseDateAssignment(){
    Operation operation;
    char choice;
    cout << "1.Dodaj operacje z data dzisiejsza " << '\n' ;
    cout << "2.Dodaj operacje z okreslona data" << '\n';
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::readChar();

    switch (choice){
        case '1':
            operation.setDate(date.getCurrentDate());
            break;
        case '2':
            cout << "Podaj date operacji (yyyy-mm-dd): " << '\n';
            operation.setDate(date.insertDate());
            break;
    }
    return operation.getDate();
}



void BudgetTracker::incomesSort(){
    sort( incomes.begin(), incomes.end(), []( Operation &operationA, Operation &operationB ){
        return operationA.getDate() < operationB.getDate();
    });
}
void BudgetTracker::expensesSort(){
    sort( expenses.begin(), expenses.end(), []( Operation &operationA, Operation &operationB ){
        return operationA.getDate() < operationB.getDate();
    });
}

double BudgetTracker::showIncomes(int lowerRange, int upperRange){
    double totalIncomes = 0;

    cout << "PRZYCHODY: " << '\n';

    for (vector<Operation>::iterator itr = incomes.begin(); itr != incomes.end(); itr++){
        if (itr -> getDate() >= lowerRange && itr -> getDate() <= upperRange){
                cout << "   " << AuxiliaryMethods::formatDateToReadable(itr -> getDate()) << " " << itr -> getDescription() << " " << itr -> getAmount() << '\n';
                totalIncomes += itr -> getAmount();
        }
    }
return totalIncomes;
}

double BudgetTracker::showExpenses(int lowerRange, int upperRange){
    double totalExpenses = 0;

    cout << '\n' << "WYDATKI: " << '\n';

    for (vector<Operation>::iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        if (itr -> getDate() >= lowerRange && itr -> getDate() <= upperRange){
                cout << "   " << AuxiliaryMethods::formatDateToReadable(itr -> getDate()) << " " << itr -> getDescription() << " " << itr -> getAmount() << '\n';
                totalExpenses += itr -> getAmount();
        }
    }
return totalExpenses;
}

bool BudgetTracker::checkSelectedPeriodCorrectnes(int selectedPeriodLowerRange, int selectedPeriodUpperRange){
    if (selectedPeriodLowerRange >= selectedPeriodUpperRange){
        cout << '\n' << "Podales bledny zakres, data poczatkowa musi byc wczesniejsza niz koncowa!" << '\n';
        return false;
    }
    else
        return true;
}


