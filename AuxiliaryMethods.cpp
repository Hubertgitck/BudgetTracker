#include "AuxiliaryMethods.h"


string AuxiliaryMethods::convertCommaToDot(){
    return "";
}

string AuxiliaryMethods::readLine(){
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::convertStringToInt(string number){
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}
string AuxiliaryMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
