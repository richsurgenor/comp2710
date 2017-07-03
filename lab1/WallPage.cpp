//
// Created by Rich on 7/2/2017.
//

#include "WallPage.h"

WallPage::WallPage(string& buffer, User& user) : buffer(buffer), user(user) {}

void WallPage::parseBuffer()
{
    cout << "==========================================================\n";
    cout << "               " + user.getName() +"'s Wall Page          \n";
    cout << "==========================================================\n\n";

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

