#ifndef BUDGETTRACKERFILE_H
#define BUDGETTRACKERFILE_H

#include <iostream>
#include <vector>

#include "TextFile.h"
#include "Operation.h"
#include "AuxiliaryMethods.h"

using namespace std;
class BudgetTrackerFile:public TextFile{

public:
    BudgetTrackerFile(string filename) : TextFile(filename){};
    vector <Operation> readAllOperationsFromFile();
    void addNewOperationToFile(Operation operation);
};

#endif
