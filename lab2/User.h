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
    vector<string> friends;
    vector<string> followedHashTags;
    vector<string> posts;

public:
    User(string nameIn) : name(nameIn){};
    bool followHashTag(string);
    string getName() const;
    void addPost(string post);
    bool addFriend(string);
    //User& getFriend(string name);
    vector<string> getFriendNamesAsMessageHeaders();
    vector<string> getFollowedHashTags();
    bool isFriend(string name);
};



#endif //LAB1_USER_H
