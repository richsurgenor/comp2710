//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        Menu.h
// Description: Declarations for the Menu class

#ifndef LAB1_MENU_H
#define LAB1_MENU_H

#include <string>
#include <iostream>
#include "MenuInteractionHandler.h"

using namespace std;

class Menu {
private:
    MenuInteractionHandler& menuHandler;
    bool userExit;
    bool loggedIn;
    string promptUser(string);

public:
    Menu(MenuInteractionHandler& menuHandlerIn);
    void UI();
    void selectOption();
    void loginOption();
    void changeUserOption();
    void postMessageOption();
    void addFriendOption();
    void followHashTagOption();
    void displayWallPageOption();
    void displayHomePageOption();
    void displayBanner(string);
};

#endif //LAB1_MENU_H
