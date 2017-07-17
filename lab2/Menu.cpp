//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        Menu.cpp
// Description: Definitions for the Menu class

#include "Menu.h"

Menu::Menu(MenuInteractionHandler& menuHandlerIn) : menuHandler(menuHandlerIn), userExit(false), entry(true) {}

// Function:       UI
// Description:    Invokes Menu User Interface
void Menu::UI()
{
    displayBanner("Distributed War Eagle Chat System!");
    loginOption();
    do
    {
        if (entry) {
                displayBanner("Distributed War Eagle Chat System, " + menuHandler.getCurrentUserName());
        }
        else
        {
            cout << "\n=================================================================================================="
                    "======================\n";
        }
        entry=false;
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

    switch(option)
    {
        case 'n':
            loginOption();
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
            displayBanner("Thank you for using the War Eagle Chat System");
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

// Function:        loginOption
// Description:     create user/login option in UI
void Menu::loginOption()
{
    string name = promptUser("Please enter user name: ");
    if (!menuHandler.createUser(name)) {
        // user already exists
        menuHandler.setCurrentUser(&menuHandler.getUser(name));
    }
}

// Function:        changeUserOption
// Description:     changeUser option in UI
void Menu::changeUserOption()
{
    if (!menuHandler.changeUser(promptUser("Please enter user name: ")))
    {
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
    displayBanner("New message added");
}

// Function:        addFriendOption
// Description:     add friend option in UI
void Menu::addFriendOption()
{
    string friendName = promptUser("Please enter friend's name: ");
    if (!menuHandler.addFriend(friendName)) {
        displayBanner("Either you are already friends with the user or they do not exist.");
    }
    else {
        displayBanner("Added " + friendName);
    }
}

// Function:        followHashTagOption
// Description:     follow hash tag option in UI
void Menu::followHashTagOption()
{
    string hashtag = promptUser("Enter hashtag topic: ");
   if (!menuHandler.followHashtag(hashtag)) {
       displayBanner("You are already following this topic.");
   }
   else {
       displayBanner("Following " + hashtag);
   }
}

// Function:        displayWallPageOption
// Description:     display wall page option in UI
void Menu::displayWallPageOption()
{
    displayBanner(menuHandler.getCurrentUser()->getName() +"'s Wall Page");
    menuHandler.displayWallPage();
    displayBanner("End of " + menuHandler.getCurrentUserName() + "'s Wall Page");
}

// Function:        displayHomePageOption
// Description:     display home page option in UI
void Menu::displayHomePageOption()
{
    displayBanner(menuHandler.getCurrentUserName() +"'s Home Page");
    menuHandler.displayHomePage();
    displayBanner("End of " + menuHandler.getCurrentUserName() + "'s Home Page");
}

// Function:        displayBanner
// Inputs:          Text to display
// Description:     Displays a banner of requested text
void Menu::displayBanner(string text)
{
    size_t bannerLength = 60;
    size_t length = text.length();
    if (length > bannerLength) bannerLength = length + 20;
    size_t spaces = (bannerLength - length) / 2;
    string middle = string(spaces-1, ' ');
    string middle2 = string(spaces + (bannerLength-(spaces*2)-length-1), ' ');
    cout << string(bannerLength, '=') << endl;
    cout << '|' << middle;
    cout << text;
    cout << middle2 << '|' << endl;
    cout << string(bannerLength, '=') << endl;
}




