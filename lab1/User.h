//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        User.h
// Description: Declarations for the User class

#ifndef LAB1_USER_H
#define LAB1_USER_H

#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class User {
private:
    string name;
    vector<User> friends;
    vector<string> followedHashTags;

public:
    User(string nameIn) : name(nameIn){};
    bool followHashTag(string);
    string getName() const;
    bool addFriend(User&);
    //User& getFriend(string name);
    vector<string> getFriendNamesAsMessageHeaders();
    vector<string> getFollowedHashTags();
    bool isFriend(string name);
};



#endif //LAB1_USER_H
