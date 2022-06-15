#include "Operation.h"

void Operation::setOperationId(int newOperationId){
    if (newOperationId > 0)
        operationId = newOperationId;
}

void Operation::setUserId(int newUserId){
    if (newUserId > 0)
        userId = newUserId;
}

void Operation::setAmount(double newAmount){
    if (newAmount != 0)
        amount = newAmount;
}

void Operation::setOperationDescription(string newOperationDescription){
    if (newOperationDescription != "")
        operationDescription = newOperationDescription;
}

int Operation::getOperationId(){
    return operationId;
}

int Operation::getUserId(){
    return userId;
}

double Operation::getAmount(){
    return amount;
}

string Operation::getOperationDescription(){
    return operationDescription;
}

