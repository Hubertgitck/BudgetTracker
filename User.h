#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    int id;
    string name;
    string lastName;
    string login;
    string password;

public:
    User (int id=0, string name="", string lastName="", string login="",string password="123456"){
        this -> id = id;
        this -> name = name;
        this -> lastName = lastName;
        this -> login = login;
        this -> password = password;
    }
    void setId(int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getLastName();
    string getLogin();
    string getPassword();
};


#endif
