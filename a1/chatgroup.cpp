/*  Name: Kenneth Surgenor
    User ID: krs0048
    Filename: chatgroup.cpp  */

#include <iostream>

using namespace std;

void printHeader();
void messageRequest(string&);
bool requestMoreUsers();
void printMessages();

string buffer;

int main() {
    printHeader();

    do {
        messageRequest(buffer);
    } while (requestMoreUsers()); 

    printMessages();
    return 0;
}

void printHeader() {
    cout << "========================================================" << endl;
    cout << "|          Welcome to the Wareagle Chat Group!         |" << endl;
    cout << "========================================================" << endl;
    cout << endl;
}

void messageRequest(string &buffer) {
    string user;
    string message;
    cout << "Enter user name: ";
    getline(cin, user);    
    cout << "Enter message: ";
    
    bool messageComplete = false;
    string temp;
    while (!messageComplete) {
        getline(cin, temp);
        if (temp == "#$") {
            messageComplete = true;
        } else {
            message += temp + '\n';           
        }
    }
    
    buffer.insert(0, "(*" + user + "*)" + message);    
}

bool requestMoreUsers() {
    string answer;
    cout << endl << "Any more users? ";
    getline(cin, answer);
    if (answer == "yes")
    {
        cout << endl;
        return true;
    }
    return false;
}

void printMessages() {
    cout << endl << "Current Chat Messages >" << endl << endl;

    size_t beg = -1;
    size_t end = -1;
    size_t end_message = -1;
   
    do { // Because str::npos is -1
        beg = buffer.find("(*", beg+1);
        end = buffer.find("*)", end+1);
        end_message = buffer.find("(*", beg+1);
        cout << buffer.substr(beg+2,end-beg-2) << " >" << endl;
        cout << buffer.substr(end+2, end_message-end-2) << endl;
    } while (buffer.find("(*", beg+1) != string::npos); 
}
