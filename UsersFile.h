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
    UsersFile(string filename) : TextFile(filename){};
    vector <User> readAllUsersFromFile();
    void addUserToFile(User user);
    void editUserPassword(int loggedUserId, string newPassword);
};



#endif
