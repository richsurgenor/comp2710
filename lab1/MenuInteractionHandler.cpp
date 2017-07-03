//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        MenuInteractionHandler.cpp
// Description: Definitions for the MenuInteractionHandler class

#include <iostream>
#include <string>
#include "MenuInteractionHandler.h"

using namespace std;

// Function:        createUser
// Inputs:          name for user to be created
// Outputs:         true/false whether user was created
// Description:     creates user
bool MenuInteractionHandler::createUser(string name)
{
    if (isUser(name))
    {
        return false;
    }
    User user(name);
    users.push_back(user);
    currentUser = &users.back();
    return true;
}

// Function:        isUser
// Inputs:          name for user to check
// Outputs:         whether name was a user
// Description:     checks if a user already exists with a name
bool MenuInteractionHandler::isUser(string name)
{
    for (User &user : users)
    {
        if (user.getName() == name)
        {
            return true;
        }
    }
    return false;
}

// Function:        changeUser
// Inputs:          name for user to change to
// Outputs:         whether this was successful
// Description:     switches to the user with the specified name
bool MenuInteractionHandler::changeUser(string name)
{
    User& user = getUser(name);
    if (user.getName() == "")
    { // could not be found
        return false;
    }

    currentUser = &user;
    return true;
}

// Function:        getUser
// Inputs:          name of user to get
// Outputs:         reference variable to user
// Description:     Gets a user with the selected name
User& MenuInteractionHandler::getUser(string name)
{
    for (User &user : users)
    {
        if (user.getName() == name)
        {
            return user;
        }
    }
    return superUser;
}

// Function:        getCurrentUser
// Outputs:         Pointer to current user
// Description:     Gets a pointer to the current user
User* MenuInteractionHandler::getCurrentUser()
{
    return currentUser;
}

// Function:        getCurrentUserName
// Outputs:         current user name
// Description:     gets current user name
string MenuInteractionHandler::getCurrentUserName()
{
    return currentUser->getName();
}

// Function:        postMessage
// Inputs:          message to post
// Description:     appends user message to messageBuffer
void MenuInteractionHandler::postMessage(string message)
{
    messageBuffer.append("(*"+ currentUser->getName() + "*)" + message);
}

// Function:        addFriend
// Inputs:          name of friend
// Outputs:         true if successful/false if not
// Description:     adds friend to user vector of friends
bool MenuInteractionHandler::addFriend(string _friend)
{
    User& friendUser = getUser(_friend);
    if (friendUser.getName() == "") {
        return false;
    }
    if (!currentUser->addFriend(friendUser)) {
        return false;
    }
    return true;
}

// Function:        displayWallPage
// Description:     displays user's wall page
void MenuInteractionHandler::displayWallPage()
{
    WallPage page(messageBuffer, *currentUser);
    page.parseBuffer();
    page.displayWallPage();
}

// Function:        displayHomePage
// Description:     displays user's home page
void MenuInteractionHandler::displayHomePage()
{
    HomePage page(messageBuffer, *currentUser);
    page.parseBuffer();
    page.generateHomePage();
}

// Function:        getBuffer
// Description:     gets the message buffer
string MenuInteractionHandler::getBuffer()
{
    return messageBuffer;
}
