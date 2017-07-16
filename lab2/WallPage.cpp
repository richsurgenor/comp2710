//
// Created by Rich on 7/2/2017.
//
// LAB1:        War Eagle Chat System
// File:        WallPage.cpp
// Description: Definitions for the WallPage class

#include "WallPage.h"

WallPage::WallPage(string& buffer, User& user) : buffer(buffer), user(user) {}

// Function:        parseBuffer
// Description:     parses entire message buffer of all messages and places them excluding the header in
//                  the messages vector
void WallPage::parseBuffer()
{
    size_t beginMessage;
    size_t endMessage;
    beginMessage = buffer.find("(*" + user.getName());
    endMessage = buffer.find("(*", beginMessage + 1);

    size_t headerConstant = user.getName().length() + 4;
    string answer;

    while (beginMessage != string::npos) {
        string sub = buffer.substr(beginMessage + headerConstant, endMessage - beginMessage - headerConstant);
        messages.push_back(sub);

        beginMessage = buffer.find("(*" + user.getName(), endMessage);
        endMessage = buffer.find("(*", beginMessage + 1);
        }
    }

// Function:        displayWallPage
// Description:     uses a reverse iterator to parse the messages vector backwards. Outputs each message to stdout
//                  and after 2 messages requests user input if the user wants to output more messages
void WallPage::displayWallPage()
{
    int count = 0;
    bool moreMessages = true;
    string answer;

    for (vector<string>::reverse_iterator i = messages.rbegin(); i != messages.rend(); ++i)
    {
        if (moreMessages) {
            cout << *i + "\n\n";
            count++;
        } else {
            break;
        }

        if (count == 2 && messages.rend() != i+1) {
            cout << "                       More messages? (yes/no) : ";
            cin >> answer;
            moreMessages = (answer == "yes");
            count = 0;
        }
    }
}

