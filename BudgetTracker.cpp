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
}

void BudgetTracker::currentMonthBalance(){
    int currentMonthLowerRange = 0, currentMonthUpperRange = 0;
    double expenses = 0, incomes = 0, balance = 0;

    currentMonthLowerRange = getCurrentDate() - getCurrentDay();
    currentMonthUpperRange = getCurrentDate();

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
    lastMonthUpperRange = getCurrentDate() - getCurrentDay();

    if (getCurrentMonth() != 1){
        lastMonthLowerRange = getCurrentDate() - getCurrentDay() - 100;
    }
    else{
        lastMonthLowerRange = getCurrentDate() - getCurrentDay() - 8900;
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

    cout << '\n' << "Podaj date poczatkowa: ";
    selectedPeriodLowerRange = insertDate();

    cout << '\n' << "Podaj date koncowa: ";
    selectedPeriodUpperRange = insertDate();

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
            operation.setDate(getCurrentDate());
            break;
        case '2':
            cout << "Podaj date operacji (yyyy-mm-dd): " << '\n';
            operation.setDate(insertDate());
            break;
    }
    return operation.getDate();
}

int BudgetTracker::getCurrentDate(){
    string currentDateString = "";
    int currentDateInteger = 0;

    currentDateString = AuxiliaryMethods::convertIntToString(getCurrentYear());

    // adding 0 when month is less than 10
    if (getCurrentMonth() < 10){
        currentDateString = currentDateString + "0" + AuxiliaryMethods::convertIntToString(getCurrentMonth());
    }
    else{
        currentDateString = currentDateString + AuxiliaryMethods::convertIntToString(getCurrentMonth());
    }

    // adding 0 when day is less than 10
    if (getCurrentDay() < 10){
        currentDateString = currentDateString + "0" + AuxiliaryMethods::convertIntToString(getCurrentDay());
    }
    else{
        currentDateString = currentDateString + AuxiliaryMethods::convertIntToString(getCurrentDay());
    }
    currentDateInteger = AuxiliaryMethods::convertStringToInt(currentDateString);
    return currentDateInteger;
}

int BudgetTracker::insertDate(){
    string insertedDate = "";
    string insertedDateWithoutDashes = "";
    string token="",year="",month="",day="";
    int insertedDateAsInteger = 0;
    bool dateIntegrityFlag;

    do{
        int tokenCounter = 1;
        insertedDate = AuxiliaryMethods::readLine();

        //Spliting string into tokens
        istringstream ss(insertedDate);

        while(!ss.eof()){
            getline(ss, token, '-');
            switch (tokenCounter){
            case 1:
                year = token;
                break;
            case 2:
                month = token;
                break;
            case 3:
                day = token;
                break;
            }
        tokenCounter++;
        }

        insertedDateWithoutDashes = year+month+day;
        dateIntegrityFlag = checkDateIntegrity(AuxiliaryMethods::convertStringToInt(year), AuxiliaryMethods::convertStringToInt(month),
            AuxiliaryMethods::convertStringToInt(day));
            if (!dateIntegrityFlag){
                cout << "Wprowadzona bledna date operacji! Wpisz date w formacie yyyy-mm-dd" << '\n';
            }
    }while (!dateIntegrityFlag);

    insertedDateAsInteger = AuxiliaryMethods::convertStringToInt(insertedDateWithoutDashes);
    return insertedDateAsInteger;
}

bool BudgetTracker::checkDateIntegrity(int year, int month, int day){
    // Date lower range is 2000-01-01 ; upper range is last day of current month
    int yearLowerRange = 2000;
    int yearUpperRange = getCurrentYear();

    if (year < yearLowerRange || year > yearUpperRange)
        return false;

    if (month < 1 || month > 12 || (year == getCurrentYear() && month > getCurrentMonth()) )
        return false;

    if (day < 1 || day > checkNumberOfDaysInMonth(month, year))
        return false;

    return true;
}

int BudgetTracker::getCurrentYear(){
    int currentYear = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentYear = (now -> tm_year + 1900);

    return currentYear;
}

int BudgetTracker::getCurrentMonth(){
    int currentMonth = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentMonth = (now -> tm_mon + 1);

    return currentMonth;
}

int BudgetTracker::getCurrentDay(){
    int currentDay = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentDay = (now -> tm_mday);

    return currentDay;
}

int BudgetTracker::checkNumberOfDaysInMonth(int month, int year){
	if( month == 2){
		if((year % 400==0) || (year%4==0 && year%100!=0))
			return 29;
		else
			return 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)
		return 31;
	else
		return 30;
}

void BudgetTracker::incomesSort(){
    sort( incomes.begin( ), incomes.end( ), []( Operation &operationA, Operation &operationB ){
        return operationA.getDate() < operationB.getDate();
    });
}
void BudgetTracker::expensesSort(){
    sort( expenses.begin( ), expenses.end( ), []( Operation &operationA, Operation &operationB ){
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


