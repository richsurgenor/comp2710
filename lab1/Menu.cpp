//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        Menu.cpp
// Description: Definitions for the Menu class

#include <iostream>
#include "Menu.h"
#include "MenuInteractionHandler.h"

Menu::Menu(MenuInteractionHandler& menuHandlerIn) : menuHandler(menuHandlerIn), userExit(false), welcomeState(true) {}

// Function:       UI
// Description:    Invokes Menu User Interface
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
            cout << "\n=================================================================================================="
                    "======================\n";
        }
        welcomeState = false;
        cout << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change"
                     " user (c), Quit (q)\n";
        selectOption();
    } while (!userExit);
}

// Function:        SelectOption
// Description:     Prompts user to enter menu option
void Menu::selectOption()
{
    char option;
    cout << "Enter option: ";
    cin >> option;

    if (menuHandler.getCurrentUserName() == "" && (option == 'p' || option == 'w' || option == 'h' || option == 'f' || option == 't')) {
        cout << "Please log in first." << endl;
        return;
    }

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
        default:
            cout << "You have entered an invalid option.\n";
    }
}

// Function:        promptUser
// Inputs:          string to prompt
// Ouputs:          string of user input
// Desription:      Prompts user with message
string Menu::promptUser(string prompt)
{
    string name;
    cout << prompt;
    cin >> name;
    return name;
}

// Function:        createUserOption
// Description:     create user option in UI
void Menu::createUserOption()
{
    if (menuHandler.createUser(promptUser("Please enter user name: "))) {
        welcomeState = true;
    }
    else {
        cout << "Sorry, this user already exists!\n";
    }
}

// Function:        changeUserOption
// Description:     changeUser option in UI
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

// Function:        postMessageOption
// Description:     post message option in UI
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

// Function:        addFriendOption
// Description:     add friend option in UI
void Menu::addFriendOption()
{
    if (!menuHandler.addFriend(promptUser("Please enter friend's name: "))) {
        cout << "Either you are already friends with the user or they do not exist.\n";
    }
}

// Function:        followHashTagOption
// Description:     follow hash tag option in UI
void Menu::followHashTagOption()
{
   if (!menuHandler.getCurrentUser()->followHashTag(promptUser("Enter hashtag topic: "))) {
       cout << "You are already following this topic.\n";
   }
}

// Function:        displayWallPageOption
// Description:     display wall page option in UI
void Menu::displayWallPageOption()
{
    menuHandler.displayWallPage();
}

// Function:        displayHomePageOption
// Description:     display home page option in UI
void Menu::displayHomePageOption ()
{
    cout << "==========================================================\n";
    cout << "               " + menuHandler.getCurrentUser()->getName() +"'s Home Page          \n";
    cout << "==========================================================\n\n";
    menuHandler.displayHomePage();
}




