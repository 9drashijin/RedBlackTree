#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
void addRedBlackTree(Node **rootPtr, Node *newNode);

Node *_delRedBlackTree(Node **rootPtr, Node *nodeToRemove);
Node *delRedBlackTree(Node **rootPtr, Node *nodeToRemove);

#endif // RedBlackTree_H
