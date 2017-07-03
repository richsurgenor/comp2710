//
// Created by Rich on 7/2/2017.
//

#ifndef LAB1_WALLPAGE_H
#define LAB1_WALLPAGE_H

#include<string>
#include<iostream>
#include "User.h"

using namespace std;

class WallPage {
private:
    string& buffer;
    User& user;
    //friend std::ostream& operator<<(ostream&, const WallPage);
    vector<string> messages;


public:
    WallPage(string& buffer, User& user);
    void displayWallPage();
    void parseBuffer();
};


#endif //LAB1_WALLPAGE_H
