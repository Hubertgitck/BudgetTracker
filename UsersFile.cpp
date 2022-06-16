#include "UsersFile.h"

vector <User> UsersFile::readAllUsersFromFile(){

    vector <User> users;
    User user;

    if (!checkIfFileEmpty())
        return;
    else{
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")){
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
            user.setPassword(xml.GetData());

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
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml");

}
