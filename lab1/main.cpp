#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    cout << "Hello World!";
}


class Menu {
    public:
    
};

class MenuInteractionHandler {
    private:
    string currentUser;
    string messageBuffer;
//    vector<User> users;
    
    public:
};

class User {
    private:
    string name;
    vector<User> friends;
    vector<string> followedHashTags;

    public:
    bool followHashTag(string);
};



