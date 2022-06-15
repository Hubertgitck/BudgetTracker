#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation {
    int operationId;
    int userId;
    double amount;
    string operationDescription;

public:
    Operation (int operationId=0, int userId=0, double amount=0, string operationDescription=""){
        this -> operationId = operationId;
        this -> userId = userId;
        this -> amount = amount;
        this -> operationDescription = operationDescription;
    }
    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setAmount(double newAmount);
    void setOperationDescription(string newOperationDescription);

    int getOperationId();
    int getUserId();
    double getAmount();
    string getOperationDescription();
};


#endif
