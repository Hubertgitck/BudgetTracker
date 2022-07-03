#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile:public XmlFile{

public:
    UsersFile(string filename) : XmlFile(filename){};
    vector <User> readAllUsersFromFile();
    void addUserToFile(User user);
    void editUserPassword(int loggedUserId, string newPassword);
};

#endif
