//
// Created by Rich Surgenor on 7/26/17.
//

#ifndef LAB3_NODE_H
#define LAB3_NODE_H

#include <string>

using namespace std;

class Node {

public:
    //Node();
    //Node(string newname);
    void setNodeName(string newname);
    string getNodeName();
    void attachNewNode(Node* newNode, int direction);
    Node *getAttachedNode(int direction);
    void attachLadderChuteNode(Node *newNode);
    Node *getLadderChuteNode();

private:
    string name;
    Node *attachedNodes[4];
    Node *ladderOrChuteNode;

};




#endif //LAB3_NODE_H
