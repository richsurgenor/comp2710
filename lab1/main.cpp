#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;

int main () {
    MenuInteractionHandler handler;
    Menu menu(handler);
    menu.UIDialog();
    menu.selectOption();
    return 0;
}






