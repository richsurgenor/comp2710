//
// Created by Rich Surgenor on 6/30/17.
//

#include <iostream>
#include "Menu.h"
#include "MenuInteractionHandler.h"


void Menu::UIDialog() {
    cout << "========================================================\n"
         << "|          Welcome to War Eagle Chat System            |\n"
         << "========================================================\n\n"
         << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change"
                 "user (c), Quit (q)\n";
}

void Menu::selectOption() {
    char option;
    cout << "Enter option: ";
    cin >> option;

    switch(option) {
        case 'n':
            menuHandler.createUser();
            break;
        case 'p':
            break;
        case 'w':
            break;
        case 'h':
            break;
        case 'f':
            break;
        case 't':
            break;
        case 'c':
            break;
        case 'q':
            break;
    }
}




