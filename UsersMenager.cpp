#include "UsersMenager.h"

void UsersMenager::userRegistration(){
    User user = giveNewUserData();
    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << '\n' << "Konto zalozono pomyslnie" << '\n' << '\n';
    system("pause");
}

User UsersMenager::giveNewUserData(){

    User user;

    user.setId(getNewUserId());

    do{
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::readLine());
    } while (checkIfLoginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::readLine());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::readLine());

    cout << "Podaj nazwisko: ";
    user.setLastName(AuxiliaryMethods::readLine());

    return user;
}

int UsersMenager::getNewUserId(){
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UsersMenager::checkIfLoginExists(string login){
    for (int i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login){
            cout << '\n' << "Istnieje uzytkownik o takim loginie." << '\n';
            return true;
        }
    }
    return false;
}

void UsersMenager::changePassword(){

    User user;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        if (itr -> getId() == loggedUserId){
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << '\n' << '\n';
            system("pause");
        }
    }
    usersFile.editUserPassword(loggedUserId,newPassword);
}

int UsersMenager::logIn(){

    User user;
    string login = "", password = "";

    cout << '\n' << "Podaj login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()){
        if (itr -> getLogin() == login){
            for (int trials = 3; trials > 0; trials--){
                cout << "Podaj haslo. Pozostalo prob: " << trials << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password){
                    cout << '\n' << "Zalogowales sie." << '\n' << '\n';
                    system("pause");
                    loggedUserId = itr -> getId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << '\n';
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << '\n' << '\n';
    system("pause");
    return 0;
}

void UsersMenager::logOut(){
    loggedUserId = 0;
}


bool UsersMenager::checkIfUserIsLoggedIn(){
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UsersMenager::getLoggedUserId(){
    return loggedUserId;
}

