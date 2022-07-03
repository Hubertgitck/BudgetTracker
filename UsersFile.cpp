#include "UsersFile.h"

vector <User> UsersFile::readAllUsersFromFile(){

    vector <User> users;
    User user;

    if (checkIfFileEmpty()){
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem()){

            xml.IntoElem();
            xml.FindElem();
            user.setId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem();
            user.setName(xml.GetData());
            xml.FindElem();
            user.setLastName(xml.GetData());
            xml.FindElem();
            user.setLogin(xml.GetData());
            xml.FindElem();
            user.setPassword(xml.GetData());\

            xml.OutOfElem();
            users.push_back(user);
        }
    return users;
    }
}


void UsersFile::addUserToFile(User user){

    if (!checkIfFileEmpty()){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("ID", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFilename());
}

void UsersFile::editUserPassword(int loggedUserId, string newPassword){

    xml.Load(getFilename());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem()){
        xml.FindChildElem("ID");
        if (AuxiliaryMethods::convertStringToInt(xml.GetChildData()) == loggedUserId){

            xml.IntoElem();
            xml.FindElem("Password");
            xml.SetData(newPassword);
            break;
        }
    }
    xml.Save(getFilename());
}
