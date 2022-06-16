#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "TextFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile:public TextFile{

public:
    vector <User> readAllUsersFromFile();
    void addUserToFile(User user);
    void editUser(int loggedUserId, string newPassword);
};



#endif
