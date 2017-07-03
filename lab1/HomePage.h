//
// Created by Rich on 7/2/2017.
//

#ifndef LAB1_HOMEPAGE_H
#define LAB1_HOMEPAGE_H

#include<string>
#include<iostream>
#include "User.h"

class HomePage {
private:
    string& buffer;
    User& user;
    vector<string> messages;
public:
    HomePage(string& buffer, User& user);
    void parseBuffer();
    void generateHomePage();
};


#endif //LAB1_HOMEPAGE_H
