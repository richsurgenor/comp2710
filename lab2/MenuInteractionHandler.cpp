//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        MenuInteractionHandler.cpp
// Description: Definitions for the MenuInteractionHandler class

#include "MenuInteractionHandler.h"

using namespace std;

MenuInteractionHandler::MenuInteractionHandler() : superUser(User("")), currentUser(&superUser)
{
    concurrencyHandler.syncUsers(users, currentUser, messageBuffer);
}

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
    writeUser(name);
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
        if (ConcurrencyHandler::equalsIgnoreCase(user.getName(), name))
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
        if (ConcurrencyHandler::equalsIgnoreCase(user.getName(), name))
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

// Function:        setCurrentUser
// Inputs:          Pointer to the user
// Description      Sets the current user at login
void MenuInteractionHandler::setCurrentUser(User* currentUserIn)
{
   currentUser = currentUserIn;
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
    string header;
    header = "{#" + to_string(concurrencyHandler.incrementTimeStamp()) + "#}";
    string post = header + message;
    concurrencyHandler.findAndReplace(post, "\n", "&&");

    concurrencyHandler.writeToFile(getCurrentUserName() + ".txt", post);
}

// Function:        addFriend
// Inputs:          name of friend
// Outputs:         true if successful/false if not
// Description:     adds friend to user vector of friends
bool MenuInteractionHandler::addFriend(string _friend)
{
    concurrencyHandler.syncUsers(users, currentUser, messageBuffer);
    User& friendUser = getUser(_friend);
    //cout << "FRIEND'S NAME: " + friendUser.getName() << endl;
    if (friendUser.getName() == "") {
        return false;
    }
    if (!currentUser->addFriend(friendUser.getName())) {
        return false;
    }
    concurrencyHandler.writeToFile(currentUser->getName() + ".Friends.txt", _friend);
    return true;
}

// Function:        displayWallPage
// Description:     displays user's wall page
void MenuInteractionHandler::displayWallPage()
{
    concurrencyHandler.syncUsers(users, currentUser, messageBuffer);
    WallPage page(messageBuffer, *currentUser);
    page.parseBuffer();
    page.displayWallPage();
}

// Function:        displayHomePage
// Description:     displays user's home page
void MenuInteractionHandler::displayHomePage()
{
    concurrencyHandler.syncUsers(users, currentUser, messageBuffer);
    HomePage page(messageBuffer, *currentUser);
    page.parseBuffer();
    page.generateHomePage();
}

// Function:        writeUser
// Description:     Initializes a new user and creates their post, friend, and hashtag files
void MenuInteractionHandler::writeUser(string name)
{
    // read each text file in data directory that doesn't contain a period.
    ofstream outStream;

    outStream.open(name + ".txt");
    outStream.close();
    outStream.clear();
    outStream.open(name + ".Friends.txt");
    outStream.close();
    outStream.clear();
    outStream.open(name + ".Hashtags.txt");
    outStream.close();
    outStream.clear();
    outStream.open("users.txt", ios::app);
    outStream << name << endl;
}

// Function:        followHashtag
// Description:     If the user is not already following the hashtag, follow it and write it to the user hashtag file
// Outputs:         Whether the user is already following the hashtag
bool MenuInteractionHandler::followHashtag(string hashtag)
{
    if (getCurrentUser()->followHashTag(hashtag))
    {
        concurrencyHandler.writeToFile(currentUser->getName() + ".Hashtags.txt", hashtag);
        return true;
    }
    return false;
}



