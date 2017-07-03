//
// Created by Rich Surgenor on 6/30/17.
//

#include "User.h"

string User::getName() const {
    return name;
}

bool User::addFriend(User &user) {
    if (isFriend(user.getName())) {
        return false;
    }
    friends.push_back(user);
    return true;
}

User& User::getFriend(string name) {
    for (User& _friend : friends) {
        if (_friend.getName() == name) {
            return _friend;
        }
    }
}

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

vector<string> User::getFriendNamesAsMessageHeaders()
{
    vector<string> names;
    for (User& _friend : friends) {
        names.push_back("(*" +_friend.getName() + "*)");
    }
    return names;
}

vector<string> User::getFollowedHashtags() {
    return followedHashTags;
}