#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods{

public:
    static string readLine();
    static string convertIntToString(int number);
    static char readChar();
    static int convertStringToInt(string number);
    static string convertCommaToDot(string stringWithComma);
    static double convertStringTodouble(string stringToConvert);
    static string formatDateToReadable(int dateInteger);
};


#endif
