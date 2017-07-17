//
// Created by Rich on 7/13/2017.
//

#include "ConcurrencyHandler.h"


bool ConcurrencyHandler::doesFileExist(string fileName)
{
    ifstream infile(fileName);
    return infile.good();
}

void ConcurrencyHandler::findAndReplace(string& source, string const& find, string const& replace)
{
    for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length();
    }
}

int ConcurrencyHandler::getCurrentTimeStamp()
{
    int timestamp = 0;
    if (!doesFileExist("timestamp.txt"))
    {
        ofstream outStream;
        outStream.open("timestamp.txt");
        outStream << "-1" << endl;
        outStream.close();
        outStream.clear();
    }

    ifstream inStream;
    inStream.open("timestamp.txt");
    inStream >> timestamp;
    return timestamp;
}

// Function:        incrementTimeStamp()
// Description:     Increments the timestamp file
// Outputs:         the incremented timestamp (int)
int ConcurrencyHandler::incrementTimeStamp()
{
    int timestamp = getCurrentTimeStamp();
    timestamp++;
    ofstream outStream;
    outStream.open("timestamp.txt");
    outStream << timestamp;
    return timestamp;
}

// Function:        writeToFile()
// Description:     Appends or overwrites the file
// Inputs:          filename, what you want to append, if you are appending or overwriting
// Outputs:         Whether or not the write was successful
bool ConcurrencyHandler::writeToFile(string filename, string toAppend, bool append) {
    if (!doesFileExist(filename)) {
        return false;
    }
    ofstream outStream;
    if (append) {
        outStream.open(filename, ios::app);
    }
    else {
        outStream.open(filename);
    }
    outStream << toAppend << endl;
    return true;
}

// Function:        syncUsers()
// Description:     Synchronizes the system from the files
// Inputs:          reference to the users vector, a reference pointer to the current user, the reference to buffer
void ConcurrencyHandler::syncUsers(vector<User> &users, User*& currentUserPtr, string& buffer)
{
    if (!doesFileExist("users.txt")) {
        return;
    }
    User currentUser = *currentUserPtr;
    cout << "CURRENT USER'S NAME: " + currentUser.getName() << endl;
    string currentUserName = currentUser.getName();
    vector<string> names;
    ifstream inStream;
    inStream.open("users.txt");
    if (!inStream.fail()) // simply means no users have been created yet
    {
        int currentUserLoc = 0;
        int i = 0;
        users.clear(); // resets user vector
        for (string line; getline(inStream, line);)
        {
            User user = User(line);
            users.push_back(user); // replenish the users
            if (users.back().getName() == currentUserName)
            {
                currentUserLoc = i;
            }
            i++;
        }
        currentUserPtr = &users[currentUserLoc];
        cout << "syncing friends.." << endl;
        syncFriends(users);
        cout << "syncing hashtags.." << endl;
        syncHashtags(users);
        cout << "syncing posts.." << endl;
        syncPosts(users);
        cout << "creating buffer" << endl;
        createBuffer(buffer);
    }
}

// Function:        syncFriends()
// Description:     Syncs all users' friend lists
// Inputs:          reference to vector of users
void ConcurrencyHandler::syncFriends(vector<User>& users)
{
    for (User& user : users) {
        ifstream inStream;
        inStream.open(user.getName() + ".Friends.txt"); // should always exist if we got this far
        for (string line; getline(inStream, line);) {
            user.addFriend(line);
        }
    }
    return;
}

// Function:        syncHashtags
// Description:     Syncs all users' hashtag lists
// Inputs:          reference to vector of strings containing hashtags user follows
void ConcurrencyHandler::syncHashtags(vector<User>& users)
{
    for (User& user : users) {
        ifstream inStream;
        inStream.open(user.getName() + ".Hashtags.txt"); // should always exist if we got this far
        for (string line; getline(inStream, line);) {
            user.followHashTag(line);
        }
    }
    return;
}

// Function:        syncPosts
// Description:     Syncs all users' posts to the local posts array (todo: make it only append to the array instead)
// Inputs:          Reference to vector containing users
void ConcurrencyHandler::syncPosts(vector<User>& users)
{
    for (User& user : users) {
        bool messageReady = false;
        char next;
        string timestamp;
        string message;
        ifstream inStream;
        inStream.open(user.getName() + ".txt"); // should always exist if we got this far
        while (inStream >> next)
        {

            if (next != '{' && next != '#' && next != '}') {
                timestamp += next;
            }

            if (messageReady)
            {
                findAndReplace(message, "&&", "\n");
                posts[stoi(timestamp)] = "(*" + user.getName() + "*)" + message;
                message = "";
                timestamp = "";
                messageReady = false;

            }

            if (next == '}')
            {
                getline(inStream, message, '{');
                messageReady = true;
            }
        }
        if (message != "")
        { // in case user had no posts
            findAndReplace(message, "&&", "\n");
            posts[stoi(timestamp)] = "(*" + user.getName() + "*)" + message; // record the last message
        }
    }
    return;
}

// Function:        createBuffer()
// Description:     Uses the local posts array to create the buffer from Lab1 compatible with home and wall pages
// Inputs:          reference to the menu buffer
void ConcurrencyHandler::createBuffer(string& buffer)
{
    buffer.clear();
    int i = 0;
    while (posts[i] != "")
    {
        buffer += posts[i];
        i++;
    }
}
