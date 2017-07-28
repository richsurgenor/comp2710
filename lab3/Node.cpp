//
// Created by Rich Surgenor on 7/26/17.
//
// Node.cpp -- A custom data type for use with the Maze Game.
//

#include "Node.h"

// Function: attachNewNode
// Inputs: The new node and direction of it
// Description: Attaches a new node
void Node::attachNewNode(Node* newNode, int direction)
{
    attachedNodes[direction] = newNode;
}

// Function: attachLadderChuteNode
// Inputs: The new node
// Description: Sets ladderOrChuteNode to address of new node
void Node::attachLadderChuteNode(Node *newNode)
{
    ladderOrChuteNode = newNode;
}

// Function: setNodeName
// Inputs: new name for node
// Description: Sets the node name to the new name
void Node::setNodeName(string newname)
{
    name = newname;
}

// Function: getNodeName
// Outputs: name of node
// Description: Gets name of node
string Node::getNodeName()
{
    return name;
}

// Function: getAttachedNode
// Inputs: The inputted direction
// Outputs: Pointer to the attached node in the inputted direction
// Description: Gets pointer to an attached node
Node* Node::getAttachedNode(int direction)
{
    return attachedNodes[direction];
}

// Function: getLadderChuteNode
// Outputs: Gets pointer to the attached ladder/chute node
// Description: See output
Node* Node::getLadderChuteNode()
{
    return ladderOrChuteNode;
}