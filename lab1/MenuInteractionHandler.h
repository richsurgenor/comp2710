//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        MenuInteractionHandler.h
// Description: Declarations for the MenuInteractionHandler class

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
    User superUser;
    User *currentUser; //todo: make smart pointer

    public:
    MenuInteractionHandler() : superUser(User("")), currentUser(&superUser) {}
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
    string getBuffer();
};

#endif //LAB1_MENUINTERACTIONHANDLER_H
