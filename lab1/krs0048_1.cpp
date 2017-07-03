#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;

// todo: catch if user is not logged in yet
// todo: remove trash code

int main () {
    MenuInteractionHandler handler;
    Menu menu(handler);
    menu.UI();
    return 0;
}






