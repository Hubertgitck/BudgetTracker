#include <iostream>
#include "Markup.h"
#include <chrono>
#include <ctime>

using namespace std;

/*
int main()
{

    return 0;
}
*/

#include "UsersMenager.h"

int main(){

    UsersMenager usersMenager("users.xml");

    //usersMenager.userRegistration();
    usersMenager.logIn();
    usersMenager.changePassword();
}

