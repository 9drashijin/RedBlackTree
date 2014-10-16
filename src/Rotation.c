#include "Rotation.h"
#include "Node.h"
#include <stdio.h>

void rightRotate(Node **nodePtr){
  Node *root = (* nodePtr)->left;
  Node *tempRoot = root->right;

  root->right = *nodePtr;
  (*nodePtr)->left = tempRoot;  
  *nodePtr = root;
}
void leftRotate(Node **nodePtr){
  Node *root = (* nodePtr)->right;
  Node *tempRoot = root->left;

  root->left = *nodePtr;
  (*nodePtr)->right = tempRoot;  
  *nodePtr = root;
}
void leftRightRotate(Node **nodePtr){
  Node *root = (* nodePtr);
  
  leftRotate(&root->left);
  rightRotate(*(&nodePtr));
}
void rightLeftRotate(Node **nodePtr){
  Node *root = (* nodePtr);
  
  rightRotate(&root->right);
  leftRotate(*(&nodePtr));
}
