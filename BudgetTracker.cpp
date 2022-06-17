#include "BudgetTracker.h"

void BudgetTracker::addIncome(){
    Operation operation;
    char choice;
    string amount="";

    cout << "1.Dodaj przychod z data dzisiejsza " << '\n' ;
    cout << "2.Dodaj przychod z okreslona data" << '\n';
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::readChar();

    switch (choice){
        case '1':
            operation.setDate(getCurrentDate());
            break;
        case '2':
            operation.setDate(insertDate());
            break;
    }
    cout << '\n' << "Czego dotyczy przychod? ";
    operation.setDescription(AuxiliaryMethods::readLine());

    cout << '\n' << "Podaj kwote przychodu: ";
    amount = AuxiliaryMethods::readLine();
    amount = AuxiliaryMethods::convertCommaToDot(amount);
    operation.setAmount(AuxiliaryMethods::convertStringTodouble(amount));

    operations.push_back(operation);
}

void BudgetTracker::addExpense(){
    Operation operation;
    char choice;
    string amount="";

    cout << "1.Dodaj wydatek z data dzisiejsza " << '\n' ;
    cout << "2.Dodaj wydatek z okreslona data" << '\n';
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::readChar();

    switch (choice){
        case '1':
            operation.setDate(getCurrentDate());
            break;
        case '2':
            operation.setDate(insertDate());
            break;
    }
    cout << '\n' << "Czego dotyczy wydatek? ";
    operation.setDescription(AuxiliaryMethods::readLine());

    cout << '\n' << "Podaj kwote wydatku: ";
    amount = AuxiliaryMethods::readLine();
    cout << '\n' << amount;
    amount = AuxiliaryMethods::convertCommaToDot(amount);
    cout << setprecision(15);
    cout << '\n' << amount;
    operation.setAmount(AuxiliaryMethods::convertStringTodouble(amount)*(-1));
    operations.push_back(operation);

    cout << '\n' << operations[0].getAmount() << '\n';
    cout << setprecision(15);
    cout << operations[0].getAmount() << '\n';

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
    int tokenCounter = 1;
    int insertedDateAsInteger = 0;

    cout << "Podaj date operacji (yyyy-mm-dd): ";
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

    if (!checkDateIntegrity(AuxiliaryMethods::convertStringToInt(year), AuxiliaryMethods::convertStringToInt(month),
        AuxiliaryMethods::convertStringToInt(day))){
            cout << "Wprowadzona bledna date operacji! Wpisz date w formacie yyyy-mm-dd";
    }

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

