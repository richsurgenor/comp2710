//
// Created by Rich Surgenor on 7/26/17.
//
// MazeGame.h -- A driver for the MazeGame

#ifndef LAB3_MAZEGAME_H
#define LAB3_MAZEGAME_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
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
    void displayBanner(string bannerText);
    string getDirection(int direction);
    NodeCoordinates decodeNodeName(string nodeName);
    int getIndexByDirection(string direction);
    void leave();
    void changeCurrentNode(Node* newnode);

private:
    bool winner;
    Node* nodes[8][6];
    Node* currentNode;
    string directions[4];
    vector<string> travelledNodes;
};

#endif //LAB3_MAZEGAME_H
