#include <stdio.h>
#include "Node.h"
#include "InitNode.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include "RedBlackTree.h"
#include "ErrorCode.h"
#include <CException.h>

void addRedBlackTree(Node **rootPtr, Node *newNode){
  _addRedBlackTree(rootPtr,newNode);
  (*rootPtr)->color = 'b';
}

void _addRedBlackTree(Node **rootPtr, Node *newNode){
  Node *root = (* rootPtr);

  if (root == NULL){
    *rootPtr = newNode;
   (*rootPtr)->color = 'r';
    return;
  }
  if(root->right != NULL && root->left != NULL){
    if((root->right->color == 'r') && (root->left->color == 'r')){
      (* rootPtr)->color = 'r';
      (* rootPtr)->left->color = 'b';
      (* rootPtr)->right->color = 'b';
    }
  }
  if(newNode->data < root->data){
    _addRedBlackTree(&root->left,newNode);
  }
  else if(newNode->data > root->data){
    _addRedBlackTree(&root->right,newNode);
  }
  else Throw(ERROR_EQUAL_NODE);
  
  if(root->left != NULL && root->left->left != NULL && root->right == NULL){
    if((root->left->color == 'r') && (root->right == NULL) && (root->left->left->color == 'r')){
      printf("Right");
      rightRotate(rootPtr);
      (* rootPtr)->right->color = 'r';
    }
  }
  else if(root->left != NULL && root->left->right != NULL && root->right == NULL){
  if((root->left->color == 'r') && (root->left->right->color == 'r')){
      printf("leftRight");
      leftRightRotate(rootPtr);
      (* rootPtr)->right->color = 'r';
    }
  }
  else if(root->right != NULL && root->right->right != NULL && root->left == NULL){
    if((root->right->color == 'r') && (root->right->right->color == 'r')){
      printf("left");
      leftRotate(rootPtr);
      (* rootPtr)->left->color = 'r';
    }
  }
  else if(root->right != NULL && root->right->left != NULL && root->left == NULL){
  if((root->right->color == 'r') && (root->right->left->color == 'r')){
      printf("rightLeft");
      rightLeftRotate(rootPtr);
      (* rootPtr)->left->color = 'r';
    }
  }
  
  // else ;;
}


