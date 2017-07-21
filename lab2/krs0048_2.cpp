//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        krs0048_1.cpp
// Description: Program Driver

#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;

// todo: catch if user is not logged in yet
// todo: remove trash code

// Function:    main
// Description: Drives the program
int main () {
    MenuInteractionHandler handler; // Creates the handler instance for the menu
    Menu menu(handler); // Creates the menu instance
    menu.UI(); // Starts user UI
    return 0;
}






