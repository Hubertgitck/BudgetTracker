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
                operation.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetChildData()));
                xml.IntoElem();
                xml.FindElem("ID");
                operation.setOperationId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
                xml.FindElem("Date");
                operation.setDate(AuxiliaryMethods::formatDateWithoutDashes(xml.GetData()));
                xml.FindElem("Description");
                operation.setDescription(xml.GetData());
                xml.FindElem("Amount");
                operation.setAmount(AuxiliaryMethods::convertStringToDouble(xml.GetData()));
                xml.OutOfElem();

                operations.push_back(operation);
            }
        }
    //xml.FindElem returns false if there is no next sibling element and leaves main position where it was so we can
    //xml.GetChildData ID of last operation outside of loop
    xml.ResetChildPos();
    xml.FindChildElem("ID");
    lastOperationID = AuxiliaryMethods::convertStringToInt(xml.GetChildData());
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
    xml.IntoElem();
    xml.AddElem("ID", operation.getOperationId());
    xml.AddElem("UserID", operation.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::formatDateToReadable(operation.getDate()));
    xml.AddElem("Description", operation.getDescription());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(operation.getAmount()));

    xml.Save(getFilename());
    lastOperationID++ ;
}

int BudgetTrackerFile::getLastOperationId(){
    return lastOperationID;
}

