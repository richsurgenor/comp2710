//
// Created by Rich Surgenor on 6/30/17.
//
// LAB1:        War Eagle Chat System
// File:        User.cpp
// Description: Definitions for the User class

#include "User.h"

string User::getName() const {
    return name;
}

// Function:        addFriend
// Inputs:          pass by reference user
// Outputs:         true if add was successful, false if not
bool User::addFriend(User &user) {
    if (isFriend(user.getName())) {
        return false;
    }
    friends.push_back(user);
    return true;
}

// Function:        getFriend
// Inputs:          name of friend
// Outputs:         The correct reference to your friend, unless the friend did not exist,
//                  in which case you get a user with an empty string for name
// Description:     gets reference to friend
/*User& User::getFriend(string name) {
    for (User& _friend : friends) {
        if (_friend.getName() == name) {
            return _friend;
        }
    }
}*/

// Function:        isFriend
// Inputs:          name of friend
// Output:          true if friend false if not
// Description:     checks if user's friend
bool User::isFriend(string name)
{
    for(User _friend : friends)
    {
        if (_friend.getName() == name) {
            return true;
        }
    }
    return false;
}

// Function:        followHashTag
// Inputs:          name of hashTag
// Outputs:         whether hash tag could be added (true/false based on if user is already following)
// Description:     adds hash tag to followed hash tags
bool User::followHashTag(string hashTag) {
    if (find(followedHashTags.begin(), followedHashTags.end(), hashTag) == followedHashTags.end()) // does not contain
    {
        followedHashTags.push_back(hashTag);
        return true;
    }
    else {
        return false;
    }
}

// Function:        getFriendNamesAsMessageHeaders
// Outputs:         vector of all friends in message header format (*name*)
// Description      gets vector of friends names as message headers
vector<string> User::getFriendNamesAsMessageHeaders()
{
    vector<string> names;
    for (User& _friend : friends) {
        names.push_back("(*" +_friend.getName() + "*)");
    }
    return names;
}

// Function:        getFollowedHashTags
// Outputs:         vector of strings for all hash tags
// Description:     gets all user followed hash tags
vector<string> User::getFollowedHashTags() {
    return followedHashTags;
}