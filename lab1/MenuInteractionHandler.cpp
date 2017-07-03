//
// Created by Rich Surgenor on 6/30/17.
//

#include <iostream>
#include <string>
#include "MenuInteractionHandler.h"

using namespace std;

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

User* MenuInteractionHandler::getCurrentUser()
{
    return currentUser;
}

string MenuInteractionHandler::getCurrentUserName()
{
    return currentUser->getName();
}

void MenuInteractionHandler::postMessage(string message)
{
    messageBuffer.append("(*"+ currentUser->getName() + "*)" + message);
}

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

void MenuInteractionHandler::displayWallPage()
{
    //User &test = *currentUser;
    WallPage page(messageBuffer, *currentUser);
    //cout << page;
    page.parseBuffer();
    page.displayWallPage();
}

void MenuInteractionHandler::displayHomePage()
{
    HomePage page(messageBuffer, *currentUser);
    page.parseBuffer();
    page.generateHomePage();
}
