#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include <stdio.h>

Node node1, node5, node10, node15, node20, node25, node30, node35, node40, node45;

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
	resetNode(&node25, 25);
	resetNode(&node30, 30);
	resetNode(&node35, 35);
	resetNode(&node40, 40);
	resetNode(&node45, 45);
}
void tearDown(void){}

////////////////////
//  Right Rotate  //
////////////////////
/**
 *      10
 *     /         5
 *    5     => /  \
 *	 /				1		 10
 *  1
 */
void test_rightRotate_with_3_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;
	
  // printf("1 %d\n",&node1);
  // printf("5 %d\n",&node5);                                                                   
  // printf("10 %d\n=============\n",&node10);         
  
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node5);
	
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
  
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
}
/**
 *      10           5
 *     /  \        /  \
 *    5    15 =>  1		10
 *	 /				         \
 *  1                   15
 */
void test_rightRotate_with_4_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node10,&node5,&node15,'b');
	Node *root = &node10;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node5);
	
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
  
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
}
/**
 *       20          10
 *      /  \        /  \
 *    10   25 =>   5	  20
 *	 /  \				       /  \
 *  5   15           15    25
 */
void test_rightRotate_with_5_elements(void){
	setNode(&node5,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node10,&node5,&node15,'b');
	setNode(&node20,&node10,&node25,'b');
	Node *root = &node20;
	
	rightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node10);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node20.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  
	TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}
///////////////////
//  Left Rotate  //
///////////////////
/**
  *   1             5
  *    \           / \
  *     5    =>  1    10
  *      \
  *      10
  */
void test_leftRotate_with_3_elements(void){
	setNode(&node10,NULL,NULL,'b');
	setNode(&node5,NULL,&node10,'b');
	setNode(&node1,NULL,&node5,'b');
	Node *root = &node1;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node5);
	
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
  
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
}
/**
 *     5             10
 *   /  \           /  \
 *  1		10    =>   5   15
 *	     \        / 
 *        15     1
 */
void test_leftRotate_with_4_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node5,&node1,&node10,'b');
	Node *root = &node5;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node10);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  
	TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
}
/**
 *      10               20
 *     /  \             /  \
 *    5	  20     =>   10   25 
 *	      / \        /  \	
 *      15   25     5   15 
 */
void test_leftRotate_with_5_elements(void){
	setNode(&node5,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node20,&node15,&node25,'b');
	setNode(&node10,&node5,&node20,'b');
	Node *root = &node10;
	
	leftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node20);
	
	TEST_ASSERT_EQUAL_PTR(node20.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
  
	TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}

/////////////////////////
//  Left Right Rotate  //
/////////////////////////
/**
 *      20         20
 *     /          /         15
 *   10     =>   15   =>   /  \
 *	   \			  /        10   20
 *      15     10
 */
void test_leftRightRotate_with_3_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node20,&node10,NULL,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
  
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
}
/**
 *      20          20
 *     /           /         15
 *    10     =>   15   =>   /  \
 *   /  \			   /        10   20
 *  5    15     10        /
 *             /         5
 *            5
 */
void test_leftRightRotate_with_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node5,NULL,NULL,'b');
	setNode(&node10,&node5,&node15,'b');
	setNode(&node20,&node10,NULL,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
  
  TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
}
/**
 *       20             20
 *      /  \           /  \            10
 *     5    25        10   25         /  \
 *   /  \			  =>   /  \      =>    5   20
 *  1    10         5   15         /    /  \
 *        \        /              1    15   25
 *         15     1
 */
void test_leftRightRotate_with_6_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node5,&node1,&node10,'b');
	setNode(&node20,&node5,&node25,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node10);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node20.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}
/**
 *       20             20
 *      /  \           /  \           15
 *     5    25        15  25         /  \
 *   /  \			  =>   /         =>   5    20
 *  1    15         5              / \    \
 *      /          /  \           1   10   25
 *     10         1    10
 */
void test_leftRightRotate_with_6_elements_case2(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node10,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node15,&node10,NULL,'b');
	setNode(&node5,&node1,&node15,'b');
	setNode(&node20,&node5,&node25,'b');
	Node *root = &node20;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,&node10);
  TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}

/////////////////////////
//  Right Left Rotate  //
/////////////////////////
/**
 *    10      10
 *      \       \           15
 *	    20  =>  15    =>   /  \
 *     /          \      10   20
 *   15           20
 */
void test_rightLeftRotate_with_3_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node20,&node15,NULL,'b');
	setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
  
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
}
/**
 *    10       10
 *      \        \           15
 *	    20  =>   15    =>   /  \
 *     /  \        \      10   20
 *   15   25       20            \
 *                   \           25
 *                   25
 */
void test_rightLeftRotate_with_4_elements(void){
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node20,&node15,&node25,'b');
	setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
  TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  
	TEST_ASSERT_EQUAL_PTR(node10.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node10.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}
/**
 *       10             10
 *      /  \           /  \               15
 *     1   20         1   15             /  \
 *        /  \	  =>     /  \     =>    10   20
 *       15   25        5   20         / \     \
 *      /                     \       1   5    25
 *     5                      25
 */
void test_rightLeftRotate_with_6_elements(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node5,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node15,&node5,NULL,'b');
	setNode(&node20,&node15,&node25,'b');
	setNode(&node10,&node1,&node20,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node15);
	
	TEST_ASSERT_EQUAL_PTR(node15.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  TEST_ASSERT_EQUAL_PTR(node10.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node5);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}
/**
 *       5               5
 *     /   \           /  \                 10
 *    1    20         1   10               /  \
 *     	  /	 \	  =>        \       =>    5    20
 *      10    25            20           /    /  \
 *        \                /  \         1   15    25
 *         15            15    25
 */
void test_rightLeftRotate_with_6_elements_case2(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node10,NULL,&node15,'b');
	setNode(&node20,&node10,&node25,'b');
	setNode(&node5,&node1,&node20,'b');
	Node *root = &node5;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node10);
	
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node20);
	TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node20.left,&node15);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node25);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
}
//////////////////
//  Final Test  //
//////////////////
/**
 *         35                    25
 *        /  \                 /    \
 *      10   40              10      35
 *     /  \    \     =>     /  \    /  \
 *    5   25   45          5   15  30   40
 *   /    / \             /      \        \
 *  1   15   30          1       20        45
 *       \  
 *        20
 */
void test_leftRightRotate_for_FINAL_case(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node20,NULL,NULL,'b');
	setNode(&node30,NULL,NULL,'b');
	setNode(&node45,NULL,NULL,'b');
	setNode(&node15,NULL,&node20,'b');
	setNode(&node40,NULL,&node45,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node25,&node15,&node30,'b');
	setNode(&node10,&node5,&node25,'b');
	setNode(&node35,&node10,&node40,'b');
	Node *root = &node35;
	
	leftRightRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node25);
	
	TEST_ASSERT_EQUAL_PTR(node25.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node25.right,&node35);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
  TEST_ASSERT_EQUAL_PTR(node35.left,&node30);
	TEST_ASSERT_EQUAL_PTR(node35.right,&node40);
  TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,&node20);
  TEST_ASSERT_EQUAL_PTR(node40.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node40.right,&node45);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node30.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node30.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node45.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node45.right,NULL);
}

 /**
 *         10                     20
 *        /  \                  /    \
 *      5    35               10      35
 *     /    /  \     =>      /  \    /  \
 *    1   20   40           5   15  30  40
 *       /  \   \          /       /      \
 *      15  30   45       1      25       45
 *         /  
 *       25
 */
void test_rightLeftRotate_for_FINAL_case(void){
	setNode(&node1,NULL,NULL,'b');
	setNode(&node15,NULL,NULL,'b');
	setNode(&node25,NULL,NULL,'b');
	setNode(&node45,NULL,NULL,'b');
	setNode(&node30,&node25,NULL,'b');
	setNode(&node40,NULL,&node45,'b');
	setNode(&node5,&node1,NULL,'b');
	setNode(&node20,&node15,&node30,'b');
	setNode(&node35,&node20,&node40,'b');
	setNode(&node10,&node5,&node35,'b');
	Node *root = &node10;
	
	rightLeftRotate(&root);
	TEST_ASSERT_EQUAL_PTR(root,&node20);
	
	TEST_ASSERT_EQUAL_PTR(node20.left,&node10);
	TEST_ASSERT_EQUAL_PTR(node20.right,&node35);
	TEST_ASSERT_EQUAL_PTR(node10.left,&node5);
	TEST_ASSERT_EQUAL_PTR(node10.right,&node15);
  TEST_ASSERT_EQUAL_PTR(node35.left,&node30);
	TEST_ASSERT_EQUAL_PTR(node35.right,&node40);
  TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
	TEST_ASSERT_EQUAL_PTR(node5.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node30.left,&node25);
	TEST_ASSERT_EQUAL_PTR(node30.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node40.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node40.right,&node45);
  
  TEST_ASSERT_EQUAL_PTR(node1.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node1.right,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node15.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node25.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node25.right,NULL);
  TEST_ASSERT_EQUAL_PTR(node45.left,NULL);
	TEST_ASSERT_EQUAL_PTR(node45.right,NULL);
}

void changeRootByVal(Node *node, Node *newNode){
	node = newNode;
	printf("chgByVal : node = %x \n",node);

}
void changeRootByRef(Node **nodePtr, Node *newNode){
	*nodePtr = newNode;
	printf("chgByRal : node = %x \n",*nodePtr);

}
void xtest_chgRootbyVal(){
	Node *root;
	root = &node10;
	
	printf("root node is %d with address %x\n",root->data,root);
	changeRootByVal(root , &node5);
	printf("root node is %d with address %x\n\n=====",root->data,root);
}
void xtest_chgRootbyRef(){
	Node *root;
	root = &node10;
	
	printf("root node is %d with address %x\n",root->data,root);
	changeRootByRef(&root , &node5);
	printf("root node is %d with address %x\n",root->data,root);
}






