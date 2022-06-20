#ifndef BUDGETTRACKERFILE_H
#define BUDGETTRACKERFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Operation.h"
#include "AuxiliaryMethods.h"

using namespace std;
class BudgetTrackerFile:public XmlFile{

public:
    BudgetTrackerFile(string filename) : XmlFile(filename){};

    vector <Operation> readAllOperationsFromFile();
    void addNewOperationToFile(Operation operation);
};

#endif
