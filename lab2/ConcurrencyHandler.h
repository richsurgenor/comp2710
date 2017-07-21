//
// Created by Rich on 7/13/2017.
//

#ifndef LAB2_CONCURRENCYHANDLER_H
#define LAB2_CONCURRENCYHANDLER_H

#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class ConcurrencyHandler {
private:
    //MenuInteractionHandler& menuHandler;
    std::array<string, 1000> posts;
public:
    //ConcurrencyHandler(MenuInteractionHandler& menuHandlerIn) : menuHandler(menuHandlerIn) {};

    bool doesFileExist(string);

    void findAndReplace(string& source, string const& find, string const& replace);

    int getCurrentTimeStamp();

    int incrementTimeStamp();

    bool writeToFile(string, string, bool append =true);

    void syncUsers(vector<User>&, User*& currentUserPtr, string& buffer);

    void syncFriends(vector<User>&);

    void syncHashtags(vector<User>&);

    void syncPosts(vector<User>&);

    void createBuffer(string& buffer);

    static char toLower(char in);

    static bool equalsIgnoreCase(string, string);
};


#endif //LAB2_CONCURRENCYHANDLER_H
