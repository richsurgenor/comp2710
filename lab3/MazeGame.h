//
// Created by Rich Surgenor on 7/26/17.
//

#ifndef LAB3_MAZEGAME_H
#define LAB3_MAZEGAME_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

struct NodeCoordinates {
    bool empty;
    int x;
    int y;
};

class MazeGame {
public:
    MazeGame();
    void UI();
    string promptUser(string prompt);
    string getPossibleDirections();
    bool move(int direction);
    bool createMazeFromFile(string filename);
    vector<string> getTravelledNodes();
    void displayBanner(string bannerText);

private:
    bool winner;
    Node* nodes[8][6];
    Node* currentNode;
    Node endNode;
    vector<string> travelledNodes;
    NodeCoordinates decodeNodeName(string nodeName);
};

#endif //LAB3_MAZEGAME_H
