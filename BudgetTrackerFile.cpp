#include "BudgetTrackerFile.h"

vector <Operation> BudgetTrackerFile::readAllOperationsFromFile(int loggedUserId){

    vector <Operation> operations;
    Operation operation;

    if (checkIfFileEmpty()){
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem()){
            xml.FindChildElem("UserID");
            if ((AuxiliaryMethods::convertStringToInt(xml.GetChildData()) == loggedUserId)){
                operation.setOperationId(AuxiliaryMethods::convertStringToInt(xml.GetAttrib("ID")));
                operation.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetChildData()));
                xml.IntoElem();
                xml.FindElem("Date");
                operation.setDate(AuxiliaryMethods::formatDateWithoutDashes(xml.GetData()));
                xml.FindElem("Description");
                operation.setDescription(xml.GetData());
                xml.FindElem("Amount");
                operation.setAmount(AuxiliaryMethods::convertStringTodouble(xml.GetData()));
                operations.push_back(operation);
                xml.OutOfElem();
            }
        }
    //xml.FindElem returns false if there is no next sibling element and leaves main position where it was so we can
    //xml.GetAttrib of last operation outside of loop
    lastOperationID = AuxiliaryMethods::convertStringToInt(xml.GetAttrib("ID"));
    return operations;
    }
}


void BudgetTrackerFile::addNewOperationToFile(Operation operation){

    if (!checkIfFileEmpty()){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
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

int BudgetTrackerFile::getLastOperationId(){
    return lastOperationID;
}

