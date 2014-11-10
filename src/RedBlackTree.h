#ifndef RedBlackTree_H
#define RedBlackTree_H

#include "Node.h"

void _addRedBlackTree(Node **rootPtr, Node *newNode);
void addRedBlackTree(Node **rootPtr, Node *newNode);

Node *_delRedBlackTree(Node **rootPtr, Node *nodeToRemove);
Node *delRedBlackTree(Node **rootPtr, Node *nodeToRemove);

Node *_delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove);
Node *delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove);

void rmvCase1Left(Node **rootPtr);
void rmvCase2Left(Node **rootPtr);
void rmvCase3Left(Node **rootPtr);

void rmvCase1Right(Node **rootPtr);
void rmvCase2Right(Node **rootPtr);
void rmvCase3Right(Node **rootPtr);

int isBlackNode(Node *node);
int isRedNode(Node *node);
int isDoubleBlackNode(Node *node);

#endif // RedBlackTree_H
