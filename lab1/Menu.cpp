//
// Created by Rich Surgenor on 6/30/17.
//

#include <iostream>
#include "Menu.h"
#include "MenuInteractionHandler.h"

Menu::Menu(MenuInteractionHandler& menuHandlerIn) : menuHandler(menuHandlerIn), userExit(false), welcomeState(true) {}

void Menu::UI()
{
    do
    {
        if (welcomeState) {
            cout << "========================================================\n";
            if (menuHandler.getCurrentUserName() == "") {
                cout << "|          Welcome to War Eagle Chat System            |\n";
            } else {
                cout << "|          Welcome to War Eagle Chat System, " + menuHandler.getCurrentUserName() +
                        "      |\n";
            }
                cout << "========================================================\n\n";
        }
        else
        {
            cout << "=================================================================================================="
                    "======================\n";
        }
        welcomeState = false;
        cout << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change"
                     " user (c), Quit (q)\n";
        selectOption();
    } while (!userExit);
}

void Menu::selectOption()
{
    char option;
    cout << "Enter option: ";
    cin >> option;

    switch(option)
    {
        case 'n':
            createUserOption();
            break;
        case 'p':
            postMessageOption();
            break;
        case 'w':
            displayWallPageOption();
            break;
        case 'h':
            displayHomePageOption();
            break;
        case 'f':
            addFriendOption();
            break;
        case 't':
            followHashTagOption();
            break;
        case 'c':
            changeUserOption();
            break;
        case 'q':
            cout << "========================================================\n";
            cout << "     Thank you for using the War Eagle Chat System      \n";
            cout << "========================================================\n";
            userExit = true;
            break;
    }
}

string Menu::promptUser(string prompt)
{
    string name;
    cout << prompt;
    cin >> name;
    return name;
}

void Menu::createUserOption()
{
    if (menuHandler.createUser(promptUser("Please enter user name: "))) {
        welcomeState = true;
    }
    else {
        cout << "Sorry, this user already exists!\n";
    }
}

void Menu::changeUserOption()
{
    if (menuHandler.changeUser(promptUser("Please enter user name: ")))
    {
        welcomeState = true;
    }
    else {
        cout << "Sorry, this user does not exist!\n";
    }
}

void Menu::postMessageOption()
{
    cout << "Enter message: ";
    bool messageComplete = false;
    string message;
    string temp;
    cin.ignore(); // takes care of ‘\n’ left in buffer by cin
    while (!messageComplete)
    {
        getline(cin, temp);
        if (temp == "#$")
        {
            messageComplete = true;
        }
        else {
            message += temp + "\n";
        }
    }
    menuHandler.postMessage(message.substr(0, message.length()-1));
}

void Menu::addFriendOption()
{
    if (!menuHandler.addFriend(promptUser("Please enter friend's name: "))) {
        cout << "Either you are already friends with the user or they do not exist.\n";
    }
}

void Menu::followHashTagOption()
{
   if (!menuHandler.getCurrentUser()->followHashTag(promptUser("Enter hashtag topic: "))) {
       cout << "You are already following this topic.\n";
   }
}

void Menu::displayWallPageOption()
{
    menuHandler.displayWallPage();
}

void Menu::displayHomePageOption ()
{
    cout << "==========================================================\n";
    cout << "               " + menuHandler.getCurrentUser()->getName() +"'s Home Page          \n";
    cout << "==========================================================\n\n";
    menuHandler.displayHomePage();
}




