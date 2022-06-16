#include "BudgetTracker.h"

long int BudgetTracker::getCurrentDate(){
    string currentDateString = "";
    long int currentDateInteger = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentDateString = AuxiliaryMethods::convertIntToString(now -> tm_year + 1900) +
    AuxiliaryMethods::convertIntToString(now -> tm_mon + 1) + AuxiliaryMethods::convertIntToString(now -> tm_mday);

    currentDateInteger = AuxiliaryMethods::convertStringToInt(currentDateString);

    return currentDateInteger;
}

long int BudgetTracker::insertDate(){
    string insertedDateString = "";
    long int insertedDateInteger = 0;

    cout << "Podaj date operacji: ";
    insertedDateString = AuxiliaryMethods::readLine();

    for (string::iterator itr = insertedDateString.begin(); itr != insertedDateString.end(); itr++){
        if (*itr == '-')
            insertedDateString.erase(itr);
    }
    cout << insertedDateString;
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
