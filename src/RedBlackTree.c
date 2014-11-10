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

  else ;;
}

Node *delRedBlackTree(Node **rootPtr, Node *nodeToRemove){
  Node *node = _delRedBlackTree(rootPtr,nodeToRemove);
  if((*rootPtr) != NULL){
  (*rootPtr)->color = 'b';}
  return node;
}

Node *_delRedBlackTree(Node **rootPtr, Node *nodeToRemove){
  Node *node;
  Node *root = (*rootPtr);

  if(*rootPtr == NULL || nodeToRemove == NULL) Throw(ERROR_NO_NODE);
  else{
    if(nodeToRemove->data == root->data){
      node = *rootPtr;
      *rootPtr = NULL;
      return node;
    }
    else{
      if(nodeToRemove->data < root->data){
        node = _delRedBlackTree(&root->left,nodeToRemove);
      }
      else if(nodeToRemove->data > root->data){
        node = _delRedBlackTree(&root->right,nodeToRemove);
      }
    }
  if(root->left != NULL && root->left->left != NULL && root->right == NULL){
    if((root->left->left != NULL) && (root->left->right != NULL)){
      printf("RightDel");
      rightRotate(rootPtr);
      (* rootPtr)->right->left->color = 'r';
    }
  }
  else if(root->right != NULL && root->right->right != NULL && root->left == NULL){
    if((root->right->left != NULL) && (root->right->right != NULL)){
      printf("leftDel");
      leftRotate(rootPtr);
      (* rootPtr)->left->right->color = 'r';
    }
  }
  if(root->right != NULL && root->left == NULL){
    if(root->right->color == 'b'){
      (* rootPtr)->color = 'b';
      (* rootPtr)->right->color = 'r';
    }
  }
  else if(root->right == NULL && root->left != NULL){
    if(root->left->color == 'b'){
      (* rootPtr)->color = 'b';
      (* rootPtr)->left->color = 'r';
    }
  }
  return node;
  }
}

Node *delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove){
  Node *node = _delRedBlackTreeParentSibling(rootPtr,nodeToRemove);
  if((*rootPtr) != NULL){
  (*rootPtr)->color = 'b';}
  return node;
}
Node *_delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove){
  Node *node;
  Node *root = (*rootPtr);

  if(*rootPtr == NULL || nodeToRemove == NULL) Throw(ERROR_NO_NODE);
  else{
    if(nodeToRemove->data == root->data){
      node = *rootPtr;
      *rootPtr = NULL;
      return node;
    }
    else{
      if(nodeToRemove->data < root->data){
        node = _delRedBlackTreeParentSibling(&root->left,nodeToRemove);
      }
      else if(nodeToRemove->data > root->data){
        node = _delRedBlackTreeParentSibling(&root->right,nodeToRemove);
      }
    }
    /////////// LEFT side /////////////
    if(root->left == NULL || isDoubleBlackNode(root->left)){
      if(isBlackNode(root->right)){
        // The sibling is black and it has a red nephew
        if(isRedNode((root->right->left)) || isRedNode((root->right->right))){
          rmvCase1Left(rootPtr);
        }
        // The sibling is black and both nephew are black
        else if(isBlackNode(root->right->right) && isBlackNode(root->right->left)){
          rmvCase2Left(rootPtr);
        }
      }
      // The sibling is red
      else if (isRedNode(root->right)){
      // rmvCase3Left(rootPtr);
      printf("Left Case3");
      leftRotate(rootPtr);
      (* rootPtr)->color = 'b';
      (* rootPtr)->left->color = 'b';
      (* rootPtr)->left->right->color = 'r';
      }
    }
    /////////// RIGHT side /////////////
    else if(root->right == NULL || isDoubleBlackNode(root->right)){
      if(isBlackNode(root->left)){
        // The sibling is black and it has a red nephew
        if(isRedNode((root->left->left)) || isRedNode((root->left->right))){
          rmvCase1Right(rootPtr);
        }
        // The sibling is black and both nephew are black
        else if(isBlackNode(root->left->right) && isBlackNode(root->left->left)){
          rmvCase2Right(rootPtr);
        }
      }
      // The sibling is red
      else if(isRedNode(root->left)){
      // rmvCase3Right(rootPtr);
      printf("Right Case3");
      rightRotate(rootPtr);
      (* rootPtr)->color = 'b';
      (* rootPtr)->right->color = 'b';
      (* rootPtr)->right->left->color = 'r';
      }
    }
  return node;
  }
}
void rmvCase1Left(Node **rootPtr){
  Node *root = (*rootPtr);
  if(isRedNode(root->right->right) && isBlackNode(root->right->left)){
    leftRotate(rootPtr);
    printf("Left Case1");
  }
  else if(isRedNode(root->right->left) && isBlackNode(root->right->right)){
    rightLeftRotate(rootPtr);
    printf("Left Case1b");
  }
  (* rootPtr)->right->color = 'b';
  (* rootPtr)->left->color = 'b';
}
void rmvCase2Left(Node **rootPtr){
  Node *root = (*rootPtr);
  if(isBlackNode(root)){
    (* rootPtr)->color = 'd';
    printf("Left Case2");
    }
  else if(isRedNode(root)){
    (* rootPtr)->color = 'b';
    printf("Left Case2b");
    }
  if(root->right !=NULL){
    (* rootPtr)->right->color = 'r';
  }
}
void rmvCase3Left(Node **rootPtr){
  Node *root = (*rootPtr);
  leftRotate(rootPtr);
  (* rootPtr)->color = 'b';
  (* rootPtr)->left->color = 'r';
  printf("Left Case3");
  
  if(isDoubleBlackNode(root->left->left) && isBlackNode(root->left->right)){
		if(isRedNode(root->left->right->left) || isRedNode(root->left->right->right)){
			rmvCase1Left(&root->left);
      }
    else if(isBlackNode(root->left->right->left) && isBlackNode(root->left->right->right)){
			rmvCase2Left(&root->left);
      }
    else ;;
	}
  else ;;
}
void rmvCase1Right(Node **rootPtr){
  Node *root = (*rootPtr);
  if(isRedNode(root->left->left) && isBlackNode(root->left->right)){
    rightRotate(rootPtr);
    printf("Right Case1");
  }
  else if(isRedNode(root->left->right) && isBlackNode(root->left->left)){
    leftRightRotate(rootPtr);
    printf("Right Case1b");
  }
  (* rootPtr)->right->color = 'b';
  (* rootPtr)->left->color = 'b';
}
void rmvCase2Right(Node **rootPtr){
  Node *root = (*rootPtr);
  if(isBlackNode(root)){
    (* rootPtr)->color = 'd';
    printf("Right Case2");
    }
  else if(isRedNode(root)){
    (* rootPtr)->color = 'b';
    printf("Right Case2b");
    }
  if(root->left !=NULL){
    (* rootPtr)->left->color = 'r';
  }
}
void rmvCase3Right(Node **rootPtr){
  Node *root = (*rootPtr);
  rightRotate(rootPtr);
  (* rootPtr)->color = 'b';
  (* rootPtr)->right->color = 'r';
  printf("Right Case3");

  if(isDoubleBlackNode(root->right->right) && isBlackNode(root->right->left)){
		if(isBlackNode(root->right->left->left) && isBlackNode(root->right->left->right)){
			rmvCase2Right(&root->right);
      }
    else if(isRedNode(root->right->left->left) || isRedNode(root->right->left->right)){
			rmvCase1Right(&root->right);
      }
	}
}

int isBlackNode(Node *node){
  if(node == NULL){return 1;}
  else if(node != NULL && node->color == 'b'){return 1;}
  else {return 0;}
}
int isRedNode(Node *node){
  if(node != NULL && node->color == 'r'){return 1;}
  else {return 0;}
}
int isDoubleBlackNode(Node *node){
  if (node == NULL){return 1;}
  else if(node != NULL && node->color == 'd'){return 1;}
  else {return 0;}
}