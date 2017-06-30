//
// Created by Rich Surgenor on 6/30/17.
//

#ifndef LAB1_USER_H
#define LAB1_USER_H

#include<vector>
#include<string>

using namespace std;


class User {
private:
    string name;
    vector<string> followedHashTags;

public:
    bool followHashTag(string);
    User(string nameIn) : name(nameIn){};
};



#endif //LAB1_USER_H
