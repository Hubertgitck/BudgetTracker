#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods{

public:
    static string readLine();
    static string convertIntToString(int number);
    static string convertCommaToDot(string stringWithComma);
    static string formatDateToReadable(int dateInteger);
    static string convertDoubleToString(double nubmerAsDouble);
    static char readChar();
    static int convertStringToInt(string number);
    static int formatDateWithoutDashes(string dateWithDashes);
    static double convertStringToDouble(string stringToConvert);

};


#endif
