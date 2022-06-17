#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation {
    int operationId;
    int userId;
    int date;
    double amount;
    string operationDescription;

public:
    Operation (int operationId=0, int userId=0, int date=0, double amount=0, string operationDescription=""){
        this -> operationId = operationId;
        this -> userId = userId;
        this -> date = date;
        this -> amount = amount;
        this -> operationDescription = operationDescription;
    }
    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setAmount(double newAmount);
    void setOperationDescription(string newOperationDescription);

    int getOperationId();
    int getUserId();
    int getDate();
    double getAmount();
    string getOperationDescription();
};


#endif
