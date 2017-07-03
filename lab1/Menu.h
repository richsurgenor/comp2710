//
// Created by Rich Surgenor on 6/30/17.
//

#ifndef LAB1_MENU_H
#define LAB1_MENU_H

#include <string>
#include "MenuInteractionHandler.h"

using namespace std;

class Menu {
private:
    MenuInteractionHandler& menuHandler;
    bool userExit;
    bool welcomeState;
    string promptUser(string);

public:
    Menu(MenuInteractionHandler& menuHandlerIn);
    void UI();
    void selectOption();
    void createUserOption();
    void changeUserOption();
    void postMessageOption();
    void addFriendOption();
    void followHashTagOption();
    void displayWallPageOption();
    void displayHomePageOption();
};

#endif //LAB1_MENU_H
