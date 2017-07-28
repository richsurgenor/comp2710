//
// Created by Rich Surgenor on 7/26/17.
//

#include "Node.h"

void Node::attachNewNode(Node* newNode, int direction)
{
    attachedNodes[direction] = newNode;
}

void Node::attachLadderChuteNode(Node *newNode) {
    ladderOrChuteNode = newNode;
}

void Node::setNodeName(string newname) {
    name = newname;
}