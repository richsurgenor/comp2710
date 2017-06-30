//
// Created by Rich Surgenor on 6/30/17.
//

#ifndef LAB1_MENUINTERACTIONHANDLER_H
#define LAB1_MENUINTERACTIONHANDLER_H


#include <string>
#include <vector>
#include "User.h"

using namespace std;

class MenuInteractionHandler {
    private:
    string currentUser;
    string messageBuffer;
    vector<User> users;

    public:
    bool createUser();
};

#endif //LAB1_MENUINTERACTIONHANDLER_H
