#include <iostream>
#include "Markup.h"
#include <chrono>
#include <ctime>

using namespace std;
tm make_tm(int year, int month, int day){
    tm tm = {0};
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}


int main()
{

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";

// Structures representing the two dates
tm tm1 = make_tm(2012,4,2);    // April 2nd, 2012
tm tm2 = make_tm(2003,2,2);    // February 2nd, 2003

// Arithmetic time values.
// On a posix system, these are seconds since 1970-01-01 00:00:00 UTC
time_t time1 = mktime(&tm1);
time_t time2 = mktime(&tm2);

// Divide by the number of seconds in a day
const int seconds_per_day = 60*60*24;
time_t difference = (time1 - time2) / seconds_per_day;

cout << difference;



    CMarkup xml;
    string amount = "12.5";

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Kwota", amount );

    xml.Save( "users.xml" );

    return 0;
}
