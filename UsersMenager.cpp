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

int UsersMenager::getNewUserId()
{
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
