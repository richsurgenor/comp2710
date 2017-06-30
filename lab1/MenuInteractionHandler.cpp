//
// Created by Rich Surgenor on 6/30/17.
//

#include <iostream>
#include <string>
#include "MenuInteractionHandler.h"

using namespace std;

bool MenuInteractionHandler::createUser() {
    string name;
    cout << "Please enter user name: ";
    cin >> name;

    if (users.)
    User user(name);
    users.push_back(user);
    return true;
}

