#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine(){
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::readChar(){
    string input = "";
    char character  = {0};

    while (true){
        getline(cin, input);

        if (input.length() == 1){
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << '\n';
    }
    return character;
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

string AuxiliaryMethods::convertCommaToDot(string stringWithComma){
    string stringWithDot="";

    for (int i = 0; i < stringWithComma.size(); i++){
        if (stringWithComma[i] == ',')
            stringWithDot += ".";
        else
            stringWithDot += stringWithComma[i];
    }
    return stringWithDot;
}

double AuxiliaryMethods::convertStringTodouble(string stringToConvert){
    return stod(stringToConvert);
}

string AuxiliaryMethods::formatDateToReadable(int dateInteger){
    string dateString = "";
    dateString = convertIntToString(dateInteger);
    //insert dashes - into a string
    dateString.insert(4,"-");
    dateString.insert(7,"-");

    return dateString;
}
