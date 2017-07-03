//
// Created by Rich Surgenor on 6/30/17.
//

#ifndef LAB1_MENUINTERACTIONHANDLER_H
#define LAB1_MENUINTERACTIONHANDLER_H


#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "WallPage.h"
#include "HomePage.h"

using namespace std;

class MenuInteractionHandler {
    private:
    string messageBuffer;
    vector<User> users;
    User superUser=User("");
    User *currentUser=&superUser; //todo: make smart pointer

    public:
    bool createUser(string name);
    bool changeUser(string name);
    bool isUser(string name);
    User& getUser(string name);
    User* getCurrentUser();
    string getCurrentUserName();
    void postMessage(string);
    bool addFriend(string);
    void displayWallPage();
    void displayHomePage();
};

#endif //LAB1_MENUINTERACTIONHANDLER_H
