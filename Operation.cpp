#include "Operation.h"

void Operation::setOperationId(int newOperationId){
    if (newOperationId > 0)
        operationId = newOperationId;
}

void Operation::setUserId(int newUserId){
    if (newUserId > 0)
        userId = newUserId;
}

void Operation::setDate(int newDate){
    date = newDate;
}

void Operation::setAmount(double newAmount){
    if (newAmount != 0)
        amount = newAmount;
}

void Operation::setDescription(string newDescription){
    if (newDescription != "")
        description = newDescription;
}

int Operation::getOperationId(){
    return operationId;
}

int Operation::getUserId(){
    return userId;
}

int Operation::getDate(){
    return date;
}

double Operation::getAmount(){
    return amount;
}

string Operation::getDescription(){
    return description;
}

