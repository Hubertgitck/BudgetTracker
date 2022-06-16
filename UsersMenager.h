#ifndef USERSMENAGER_H
#define USERSMENAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersMenager {
    int loggedUserId;
    vector <User> users;
    UsersFile usersFile;

    User giveNewUserData();
    int getNewUserId();
    bool checkIfLoginExists(string login);

public:
    UsersMenager(string filename) : usersFile(filename){
        users = usersFile.readAllUsersFromFile();
        loggedUserId = 0;
    }
    int logIn();
    int getLoggedUserId();
    bool checkIfUserIsLoggedIn();

    void userRegistration();
    void changePassword();
    void logOut();


};


#endif
