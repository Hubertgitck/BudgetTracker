#include "Date.h"

int Date::getCurrentDate(){
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

int Date::insertDate(){
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

bool Date::checkDateIntegrity(int year, int month, int day){
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

int Date::getCurrentYear(){
    int currentYear = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentYear = (now -> tm_year + 1900);

    return currentYear;
}

int Date::getCurrentMonth(){
    int currentMonth = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentMonth = (now -> tm_mon + 1);

    return currentMonth;
}

int Date::getCurrentDay(){
    int currentDay = 0;
    time_t t = time(0);

    tm* now = localtime(&t);

    currentDay = (now -> tm_mday);

    return currentDay;
}

int Date::checkNumberOfDaysInMonth(int month, int year){
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
