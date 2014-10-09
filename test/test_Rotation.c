#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include <stdio.h>

Node node1, node5, node10, node15, node20;

void setNode(Node *target, Node *left, Node *right, char color){
	target->left = left;
	target->right = right;
	target->color = color;
}
void resetNode(Node *target,int data){
	target->left = NULL;
	target->right = NULL;
	target->color = 'b';
	target->data = data;
}

void setUp(void){
	resetNode(&node1, 1);
	resetNode(&node5, 5);
	resetNode(&node10, 10);
	resetNode(&node15, 15);
	resetNode(&node20, 20);
}
void tearDown(void){}

/**
 *      10
 *     /         5
 *    5     => /  \
 *	 /				1		 10
 *  1
 */
void test_rightRotation_3_eleements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node5);
	
	TEST_ASSERT_EQUAL_PTR(&node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(&node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(&node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(&node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(&node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(&node10.right,NULL);
}

void changeRootByVal(Node *node, Node *newNode){
	node = newNode;
	printf("chgByVal : node = %x \n",node);

}
void changeRootByRef(Node **nodePtr, Node *newNode){
	*nodePtr = newNode;
	printf("chgByRal : node = %x \n",*nodePtr);

}
void test_chgRootbyVal(){
	Node *root;
	root = &node10;
	
	printf("root node is %d with address %x\n",root->data,root);
	changeRootByVal(root , &node5);
	printf("root node is %d with address %x\n\n=====",root->data,root);
}
void test_chgRootbyRef(){
	Node *root;
	root = &node10;
	
	printf("root node is %d with address %x\n",root->data,root);
	changeRootByRef(&root , &node5);
	printf("root node is %d with address %x\n",root->data,root);
}






