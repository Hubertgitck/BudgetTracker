#ifndef BUDGETTRACKERFILE_H
#define BUDGETTRACKERFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Operation.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetTrackerFile:public XmlFile{
    int lastOperationID;

public:
    BudgetTrackerFile(string filename) : XmlFile(filename){
        lastOperationID = 0;
    };
    ~BudgetTrackerFile(){};

    vector <Operation> readAllOperationsFromFile(int loggedUserId);
    void addNewOperationToFile(Operation operation);
    int getLastOperationId();
};

#endif
