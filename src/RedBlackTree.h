#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
void addRedBlackTree(Node **rootPtr, Node *newNode);

Node *delRedBlackTreeNormal(Node **rootPtr, Node *nodeToRemove);
Node *_delRedBlackTreeNormal(Node **rootPtr, Node *nodeToRemove);

Node *_delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove);
Node *delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove);

Node *delRedBlackTree(Node **rootPtr, Node *nodeToRemove);
Node *removeNextLargerSuccessor(Node **parentPtr);

Node *restructureTree(Node **rootPtr, Node *removedNode);

void rmvCase1Left(Node **rootPtr, Node *removedNode);
void rmvCase2Left(Node **rootPtr, Node *removedNode);
void rmvCase3Left(Node **rootPtr, Node *removedNode);

void rmvCase1Right(Node **rootPtr, Node *removedNode);
void rmvCase2Right(Node **rootPtr, Node *removedNode);
void rmvCase3Right(Node **rootPtr, Node *removedNode);

int isBlackNode(Node *node);
int isRedNode(Node *node);
int isDoubleBlackNode(Node *node, Node *removedNode); 
// check if removed is 'd'? if Red return 0, if black return 1;
//NULL > possible 'd', if removed node == 'b'> then return 1
//                     else if removed node == 'r'> then return 0;

#endif // RedBlackTree_H
