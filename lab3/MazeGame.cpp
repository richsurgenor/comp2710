//
// Created by Rich Surgenor on 7/26/17.
//
// MazeGame.cpp -- A driver for the MazeGame

#include "MazeGame.h"

// Function:        MazeGame()
// Description:     Default constructor
MazeGame::MazeGame()
{
    for(int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            nodes[x][y] = new Node();
        }
    }

    directions[0] = "North";
    directions[1] = "East";
    directions[2] = "South";
    directions[3] = "West";

    winner = false;
}

// Function:        UI
// Description:     Drives the user interface for the Maze Game
void MazeGame::UI()
{
    displayBanner("Welcome to the Ladder and Chute Maze!");
    //promptUser("Please enter the maze file name: ");
    bool fileExists = false;
    while (!fileExists) {
        fileExists = createMazeFromFile(promptUser("Please enter the maze file name: "));
    }
    currentNode = nodes[0][0]; // Let's begin

    bool specialResponse = false;
    cout << endl << "Now starting the Chute and Ladder Maze Game! If at any time you would like to quit, enter 'q'.\n\n";
    do {
        if (currentNode->getNodeName() == "H6") // finishing node
        {
            winner = true;
            leave();
        }
        cout << "You are currently in Room " + currentNode->getNodeName() +
                                   " of the Ladder and Chute Maze, and ";

        string options;
        string choice;
        if (!specialResponse) {
            options = "you can go " + getPossibleDirections() + ". What is your choice? ";
            choice = promptUser(options);
        } else
        {
            changeCurrentNode(currentNode->getLadderChuteNode());
            options = "You can go " + getPossibleDirections() + ". What is your choice? ";
            choice = promptUser("you have taken a Ladder to Room " + currentNode->getNodeName() + ".\n" + options);
            specialResponse = false;
        }

        if (choice == "q")
        {
            leave();
        }
        int direction = getIndexByDirection(choice);

        if (direction != -1 && currentNode->getAttachedNode(direction) != nullptr) {
            specialResponse = move(direction);
        } else
        {
            displayBanner("You have made an invalid move. Make sure you entered a valid possible direction.");
            cout << endl;
        }
    } while (!winner);

}

// Function:        move
// Inputs:          An integer from 0-3 determining direction
// Outputs:         Whether or not the user encountered a chute or ladder
// Description:     Moves the user around the maze
//
bool MazeGame::move(int choice)
{
    bool specialResponse = false;
    changeCurrentNode(currentNode->getAttachedNode(choice));
    if (currentNode->getLadderChuteNode() != nullptr)
    {
        specialResponse = true;
    }
    return specialResponse;
}

// Function:        leave
// Description:     When the user gives up or wins the maze, this is called.
void MazeGame::leave()
{
    if (winner) {
        displayBanner("Congratulations, you have finished the maze! Give yourself a pat on the back.");
    }
    else {
        displayBanner("You have failed to finish the maze. Be gone.");
    }
    cout << endl << endl;
    cout << "Here is your history ";
    string end = winner ? ", don't share with your friends! " : "so you have better luck next time. ";
    cout << end;
    for (string node : travelledNodes)
    {
        cout << node + " ";
    }
    cout << endl;
    exit(0);
}

// Function:        changeCurrentMode
// Inputs:          The node you wish to change currentNode to
// Description:     Changes current node as well as adds it to your history
void MazeGame::changeCurrentNode(Node *newnode)
{
    travelledNodes.push_back(currentNode->getNodeName()); // add old node to history
    currentNode = newnode;
}

// Function:        displayBanner
// Inputs:          Text you wish to display in a banner
// Description:     Displays text in a banner
void MazeGame::displayBanner(string text)
{
    size_t bannerLength = 60;
    size_t length = text.length();
    if (length > bannerLength) bannerLength = length + 20;
    size_t spaces = (bannerLength - length) / 2;
    string middle = string(spaces-1, ' ');
    string middle2 = string(spaces + (bannerLength-(spaces*2)-length-1), ' ');
    cout << string(bannerLength, '=') << endl;
    cout << '|' << middle;
    cout << text;
    cout << middle2 << '|' << endl;
    cout << string(bannerLength, '=') << endl;
}

// Function:        promptUser
// Inputs:          string to prompt
// Ouputs:          string of user input
// Desription:      Prompts user with message
string MazeGame::promptUser(string prompt)
{
    string name;
    cout << prompt;
    cin >> name;
    return name;
}

// Function:        createMazeFromFile
// Inputs:          filename
// Outputs:         Whether opening the file was successful
// Description:     Creates a pointer network of nodes
bool MazeGame::createMazeFromFile(string filename)
{
    string piece;
    ifstream inStream;
    inStream.open(filename);
    if (inStream.good()) {
        while (inStream >> piece) {
            NodeCoordinates coords = decodeNodeName(piece);
            nodes[coords.x][coords.y]->setNodeName(piece);
            // There are five more pieces of info to extract from the current node.
            for (int i = 0; i < 4; i++) // Set the direction pointers here
            {
                inStream >> piece;
                NodeCoordinates pCoords = decodeNodeName(piece);
                if (!pCoords.empty) {
                    nodes[coords.x][coords.y]->attachNewNode(nodes[pCoords.x][pCoords.y], i); // attach node in relative direction
                }
            }
            // Set the chute and ladder node here
            inStream >> piece;
            NodeCoordinates pCoords = decodeNodeName(piece);
            if (!pCoords.empty) {
                nodes[coords.x][coords.y]->attachLadderChuteNode(nodes[pCoords.x][pCoords.y]);
            }
        }
        return true;
    }
    return false;
}

// Function:        decodeNodeName
// Inputs:          the name of the node, e.g. "A1"
// Outputs:         A NodeCoordinates struct
// Description:     Converts the node name into an easy to use format for the location of the node
//                  in the 2D array.
NodeCoordinates MazeGame::decodeNodeName(string nodeName)
{
    NodeCoordinates coords;
    if (nodeName == "*") {
        coords.empty = true;
        return coords;
    }
    coords.x = nodeName[0] - 'A'; // Get the integer value
    coords.y = nodeName[1] - '1';
    coords.empty = false;
    return coords;
}

// Function:        getPossibleDirections
// Description:     Uses currentNode to deduce possible directions you can go.
string MazeGame::getPossibleDirections()
{
    string directions;
    bool first = true;
    for (int i = 0; i < 4; i ++) // 4 possible directions
    {
        if (currentNode->getAttachedNode(i) != nullptr) {
            if (first) {
                directions += getDirection(i);
                first = false;
            } else {
                directions += " or " + getDirection(i);
            }
        }
    }
    return directions;
}

// Function:        getDirection
// Inputs:          direction index
// Outputs:         name of direction
// Description:     Uses the direction index to look up the corresponding name
string MazeGame::getDirection(int direction)
{
    return directions[direction];
}

// Function:        getIndexByDirection
// Inputs:          direction name
// Outputs:         Index of the direction (returns -1 if doesn't exist)
// Description:     Gets the index by direction name
int MazeGame::getIndexByDirection(string direction)
{
    int i = 0;
    char cDir = direction[0];
    while (cDir != directions[i][0] && cDir != directions[i][0] + 0x20) {
        i++;
        if (i > 3) {
            return -1;
        }
    }
    return i;
}

