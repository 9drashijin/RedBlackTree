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
// Red Black Tree Adding 
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
// Normal Red Black Tree Delete (ignored)
Node *delRedBlackTreeNormal(Node **rootPtr, Node *nodeToRemove){
  Node *node = _delRedBlackTreeNormal(rootPtr,nodeToRemove);
  if((*rootPtr) != NULL){
  (*rootPtr)->color = 'b';}
  return node;
}

Node *_delRedBlackTreeNormal(Node **rootPtr, Node *nodeToRemove){
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
        node = _delRedBlackTreeNormal(&root->left,nodeToRemove);
      }
      else if(nodeToRemove->data > root->data){
        node = _delRedBlackTreeNormal(&root->right,nodeToRemove);
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
// Node *removeNextLargerSuccessor(Node **parentPtr){
  // Node *removedNode, *parent = (*parentPtr), *tempNode;

  // if(parent->left != NULL){
    // removedNode = removeNextLargerSuccessor(&parent->left);
  // }
  // else if(parent->left == NULL && parent->right == NULL){
    // removedNode = *parentPtr;
    // *parentPtr = NULL;
    // return removedNode;
  // }
  // else if(parent->right != NULL){
    // printf("gotReplacer");
    // tempNode = (*parentPtr)->right;
    // removedNode = *parentPtr;
    // *parentPtr = tempNode;
    // (*parentPtr)->color = 'b';
    // return removedNode;
  // }
    // restructureTree(parentPtr,removedNode);
  // return removedNode;
// }
// New Red Black Tree Delete (current)
Node *delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove){
  Node *node = _delRedBlackTreeParentSibling(rootPtr,nodeToRemove);
  if((*rootPtr) != NULL){
  (*rootPtr)->color = 'b';}
  return node;
}
Node *_delRedBlackTreeParentSibling(Node **rootPtr, Node *nodeToRemove){
  Node *node, *tempNode;
  Node *root = (*rootPtr);

  if(*rootPtr == NULL || nodeToRemove == NULL) Throw(ERROR_NO_NODE);
  else{
    if(nodeToRemove->data == root->data){
      
      if(root->right){
        printf("IN HERE");
        tempNode = root->left;
        node = removeNextLargerSuccessor(&root->right);
        printf("Node: %d\n",(node)->data);
        *rootPtr = node;
        (* rootPtr)->left = tempNode;
        // restructureTree(rootPtr,nodeToRemove);
        return node;
      }
      else if(!root->right && !root->left){
        node = *rootPtr;
        *rootPtr = NULL;
        return node;
      }
    }
    else{
      if(nodeToRemove->data < root->data){
        node = _delRedBlackTreeParentSibling(&root->left,nodeToRemove);
      }
      else if(nodeToRemove->data > root->data){
        node = _delRedBlackTreeParentSibling(&root->right,nodeToRemove);
      }
    }
    restructureTree(rootPtr,nodeToRemove);
  return node;
  }
}

// 3 cases for the left side
void rmvCase1Left(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  if(isRedNode(root->right->right) && isBlackNode(root->right->left)){
    leftRotate(rootPtr);
    printf("Left Case1-");
  }
  else if(isRedNode(root->right->left) && isBlackNode(root->right->right)){
    rightLeftRotate(rootPtr);
    printf("Left Case1b-");
  }
  (* rootPtr)->right->color = 'b';
  (* rootPtr)->left->color = 'b';
  (* rootPtr)->color = 'r';
}
void rmvCase2Left(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  if(isBlackNode(root)){
    (* rootPtr)->color = 'd';
    printf("Left Case2-");
    }
  else if(isRedNode(root)){
    (* rootPtr)->color = 'b';
    printf("Left Case2b-");
    }
  if(root->right !=NULL){
    (* rootPtr)->right->color = 'r';
  }
  if(root->left !=NULL){
    (* rootPtr)->left->color = 'b';
  }
}
void rmvCase3Left(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  leftRotate(rootPtr);
  (* rootPtr)->color = 'b';
  (* rootPtr)->left->color = 'r';
  printf("Left Case3-");
  
  if(isDoubleBlackNode((*rootPtr)->left->left,removedNode) && isBlackNode(((*rootPtr)->left->right))){
		if(isRedNode((*rootPtr)->left->right->left) || isRedNode((*rootPtr)->left->right->right)){
			rmvCase1Left(&(*rootPtr)->left,removedNode);
      }
    else if(isBlackNode((*rootPtr)->left->right->left) && isBlackNode((*rootPtr)->left->right->right)){
			rmvCase2Left(&(*rootPtr)->left,removedNode);
      }
    else;;
	}
  else;;
}
// 3 cases for the right side
void rmvCase1Right(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  if(isRedNode(root->left->left) && isBlackNode(root->left->right)){
    rightRotate(rootPtr);
    printf("Right Case1-");
  }
  else if(isRedNode(root->left->right) && isBlackNode(root->left->left)){
    leftRightRotate(rootPtr);
    printf("Right Case1b-");
  }
  (* rootPtr)->right->color = 'b';
  (* rootPtr)->left->color = 'b';
  (* rootPtr)->color = 'r';
}
void rmvCase2Right(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  if(isBlackNode(root)){
    (* rootPtr)->color = 'd';
    printf("Right Case2-");
    }
  else if(isRedNode(root)){
    (* rootPtr)->color = 'b';
    printf("Right Case2b-");
    }
  if(root->left !=NULL){
    (* rootPtr)->left->color = 'r';
  }
  if(root->right !=NULL){
    (* rootPtr)->right->color = 'b';
  }
}
void rmvCase3Right(Node **rootPtr, Node *removedNode){
  Node *root = (*rootPtr);
  rightRotate(rootPtr);
  (* rootPtr)->color = 'b';
  (* rootPtr)->right->color = 'r';
  printf("Right Case3-");

  if(isDoubleBlackNode((*rootPtr)->right->right,removedNode) && isBlackNode((*rootPtr)->right->left)){
		if(isBlackNode((*rootPtr)->right->left->left) && isBlackNode((*rootPtr)->right->left->right)){
			rmvCase2Right(&(*rootPtr)->right,removedNode);
      }
    else if(isRedNode((*rootPtr)->right->left->left) || isRedNode((*rootPtr)->right->left->right)){
			rmvCase1Right(&(*rootPtr)->right,removedNode);
      }
    else;;
	}
  else;;
}
// Rename Delete Red Black Tree to Remove
Node *delRedBlackTree(Node **rootPtr, Node *nodeToRemove){
  Node *node = delRedBlackTreeParentSibling(rootPtr,nodeToRemove);
  return node;
}

// cases for Remove Next Larger Successor
Node *removeNextLargerSuccessor(Node **parentPtr){
  Node *removedNode, *parent = (*parentPtr), *tempNode;

  if(parent->left != NULL){
    removedNode = removeNextLargerSuccessor(&parent->left);
    printf("......");
  }
  else if(parent->left == NULL && parent->right == NULL){
    removedNode = *parentPtr;
    *parentPtr = NULL;
    printf("zxc");
    return removedNode;
  }
  else if(parent->right != NULL){
    printf("gotReplacer");
    tempNode = (*parentPtr)->right;
    removedNode = *parentPtr;
    *parentPtr = tempNode;
    (*parentPtr)->color = 'b';
    return removedNode;
  }
    restructureTree(parentPtr,removedNode);
  return removedNode;
}

// Red Black Tree for restructuring and balancing
Node *restructureTree(Node **parentPtr, Node *removedNode){
  Node *parent = (*parentPtr);
  /////////// LEFT side /////////////
  if(isDoubleBlackNode(parent->left,removedNode)){
      if(isBlackNode(parent->right)){
        // The sibling is black and it has a red nephew
        if(isRedNode((parent->right->left)) || isRedNode((parent->right->right))){
          rmvCase1Left(parentPtr,removedNode);
        }
        // The sibling is black and both nephew are black
        else if(isBlackNode(parent->right->right) && isBlackNode(parent->right->left)){
          rmvCase2Left(parentPtr,removedNode);
        }
      }
      // The sibling is red
      else if (isRedNode(parent->right)){
        rmvCase3Left(parentPtr,removedNode);
      }
    }
    /////////// RIGHT side /////////////
    else if(isDoubleBlackNode(parent->right,removedNode)){
      if(isBlackNode(parent->left)){
        // The sibling is black and it has a red nephew
        if(isRedNode((parent->left->left)) || isRedNode((parent->left->right))){
          rmvCase1Right(parentPtr,removedNode);
        }
        // The sibling is black and both nephew are black
        else if(isBlackNode(parent->left->right) && isBlackNode(parent->left->left)){
          rmvCase2Right(parentPtr,removedNode);
        }
      }
      // The sibling is red
      else if(isRedNode(parent->left)){
        rmvCase3Right(parentPtr,removedNode);
      }
    }
    return removedNode;
}

//Check for black node in RBT
int isBlackNode(Node *node){
  if(node == NULL){return 1;}
  else if(node != NULL && node->color == 'b'){return 1;}
  else {return 0;}
}
//Check for red node in RBT
int isRedNode(Node *node){
  if(node != NULL && node->color == 'r'){return 1;}
  else {return 0;}
}
//Check for double black node in RBT
int isDoubleBlackNode(Node *node , Node *removedNode){
  if (node == NULL){
    if(removedNode->color == 'b'){return 1;}
    else if(removedNode->color == 'r'){return 0;}
  }
  if(node->color == 'r'){
    if(removedNode->color == 'r'){return 0;}
    else if(removedNode->color == 'b'){return 0;}
  }
  if(node->color == 'b'){
    if(removedNode->color == 'r'){return 0;}
    else if(removedNode->color == 'b'){return 0;}
  }
  if(node->color == 'd'){
    if(removedNode->color == 'r'){return 1;}
    else if(removedNode->color == 'b'){return 1;}
  }
  else {return 0;}
}