//
// Created by Rich Surgenor on 7/26/17.
//

#include "MazeGame.h"

MazeGame::MazeGame()
{
    for(int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            nodes[x][y] = new Node();
        }
    }
}

void MazeGame::UI()
{
    displayBanner("Welcome to the Ladder and Chute Maze!");
    //promptUser("Please enter the maze file name: ");
    bool fileExists = false;
    while (!fileExists) {
        fileExists = createMazeFromFile(promptUser("Please enter the maze file name: "));
    }
    //todo check if valid filename
    currentNode = nodes[0][0]; // Let's begin


    cout << "complete";

}

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
// Description:     Creates a pointer network of nodes that stores the starting node at currentNode
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




