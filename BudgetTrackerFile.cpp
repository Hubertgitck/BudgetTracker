#include "BudgetTrackerFile.h"

vector <Operation> BudgetTrackerFile::readAllOperationsFromFile(){

    vector <Operation> operations;
    Operation operation;

    if (checkIfFileEmpty()){
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem()){
            operation.setOperationId(AuxiliaryMethods::convertStringToInt(xml.GetAttrib("ID")));

            xml.IntoElem();
            xml.FindElem();
            operation.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem();
            operation.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem();
            operation.setDescription(xml.GetData());
            xml.FindElem();
            operation.setAmount(AuxiliaryMethods::convertStringTodouble(xml.GetData()));

            xml.OutOfElem();
            operations.push_back(operation);
        }
    return operations;
    }
}


void BudgetTrackerFile::addNewOperationToFile(Operation operation){

    if (!checkIfFileEmpty()){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("operations");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("operation");
    xml.SetAttrib("ID", operation.getOperationId());
    xml.IntoElem();
    xml.AddElem("UserID", operation.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::formatDateToReadable(operation.getDate()));
    xml.AddElem("Description", operation.getDescription());
    xml.AddElem("Amount", to_string(operation.getAmount()));

    xml.Save(getFilename());
}

