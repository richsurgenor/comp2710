//
// Created by Rich on 7/2/2017.
//

#include "HomePage.h"

HomePage::HomePage(string& buffer, User& user) : buffer(buffer), user(user) {}

// Function:        ParseBuffer
// Description:     Fills the messages variable with relevant messages for the user's home page.
void HomePage::parseBuffer() {
    size_t beginMessage;
    size_t endMessage;
    beginMessage = buffer.find("(*");
    endMessage = buffer.find("(*", beginMessage + 1);

    vector<string> followedHashTags = user.getFollowedHashTags();
    vector<string> acceptedValues = user.getFriendNamesAsMessageHeaders();
    acceptedValues.insert(acceptedValues.end(), followedHashTags.begin(), followedHashTags.end());
    acceptedValues.push_back("(*" + user.getName() + "*)");

    while (beginMessage != string::npos) {
        string whole = buffer.substr(beginMessage, endMessage - beginMessage); // get the entire message string

        bool found = false;
        for (string value : acceptedValues) {
            if (whole.find(value) != string::npos) {
                found = true;
                break;
            }
        }

        if (found) {
            messages.push_back(whole);
        }

        beginMessage = buffer.find("(*", endMessage);
        endMessage = buffer.find("(*", beginMessage + 1);
    }
}

// Function:        generateHomePage
// Description:     uses a reverse iterator to output each message in reverse-chronological order that was selected
//                  from the filter (only friends messages, hash tag messages, or user messages). it then prompts the
//                  user after 2 messages if they would like to print more messages
void HomePage::generateHomePage() {
    int count = 0;
    bool moreMessages = true;
    string answer;
    for (vector<string>::reverse_iterator i = messages.rbegin();
         i != messages.rend(); ++i) {
        if (moreMessages) {
            string whole = *i;
            size_t endHeaderIndex = whole.find("*)");
            string name = whole.substr(2, endHeaderIndex - 2);
            string message = whole.substr(endHeaderIndex + 2, string::npos);
            cout << name + " >\n";
            cout << message << "\n\n";
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