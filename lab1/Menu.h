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
    MenuInteractionHandler menuHandler;

public:
    Menu(MenuInteractionHandler menuHandlerIn) : menuHandler(menuHandlerIn) {};
    void UIDialog();
    void selectOption();
};

#endif //LAB1_MENU_H
