//
// Created by Rich on 7/2/2017.
//
// LAB1:        War Eagle Chat System
// File:        Tests.cpp
// Description: Basic Unit Tests for the War Eagle Chat System

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Menu.h"

using namespace std;

int msleep(unsigned long milisec);

int main () {
    MenuInteractionHandler handler;
    Menu menu(handler);


    //msleep(1000);
    //system("rm data/*");
    // Setup: Create Users
    handler.createUser("Rich");
    handler.createUser("Jake");
    assert(handler.changeUser("Rich")); // Test and change current User

    User& user1 = handler.getUser("Rich");
    User& user2 = handler.getUser("Jake");

    // Unit Test 1: Test if user is created
    assert(user1.getName() == "Rich");

    // Unit Test 2: Test addFriend()
    user1.addFriend(user2.getName());
    assert(user1.isFriend(user2.getName()));

    // Unit Test 3: Test postMessage()
    //handler.postMessage("My name is Rich and I went swimming today!");
    //string buffer = handler.getBuffer();
    //cout << "Buffer:" + buffer;
    //msleep(1000);
    //assert(buffer == "(*Rich*)My name is Rich and I went swimming today!"); // test message

    // Unit Test 4: Test changeUser()
    handler.changeUser(user2.getName());
    assert(handler.getCurrentUser()==&user2);

    // Unit Test 5: Test followHashTag()
    user2.followHashTag("#running");
    assert (user2.getFollowedHashTags().size() > 0);

    // Unit Test 6: Test getFriendNamesAsMessageHeaders()
    assert(user1.getFriendNamesAsMessageHeaders()[0] == "(*Jake*)");

    cout << "All tests completed successfully" << endl;

    // Home Page and Wall Page as well as Overall System Testing can be seen in sampleOutput
}


int msleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
    return 1;
}