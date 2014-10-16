#include "unity.h"
#include "RedBlackTree.h"
#include "Rotation.h"
#include "Node.h"
#include "InitNode.h"
#include "CustomAssertion.h"
#include "ErrorCode.h"
#include <stdio.h>
#include <CException.h>

Node node1, node5, node10, node15, node20, node25, node30, node35, node40, node45;

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
void tearDown(void){
}

/**
 *      root           root
 *       |    add 10    |
 *       V   ------->   V
 *      NULL           10
 */ 
void test_addRedBlackTree_add_10_to_empty_tree(void){
  setNode(&node10,NULL,NULL,'r');
	Node *root = NULL;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node10);

  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', root);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
}
/**
 *      root           root
 *       |    add 5     |
 *       V   ------->   V
 *      10b            10b
 *                    /
 *                   5r
 */ 
void test_addRedBlackTree_add_5_to_tree_with_root_10(void){
  setNode(&node5,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;

  addRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node10);

  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', root);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}

/**
 *      root           root
 *       |    add 15    |
 *       V   ------->   V
 *      10b            10b
 *                        \
 *                        15r 
 */ 
void test_addRedBlackTree_add_15_to_tree_with_root_10(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;

  addRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root,&node10);
  
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', root);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}
/**
 *      root           root
 *       |    add 10     |
 *       V   ------->   V
 *      10b            10b
 *                        \
 *                        15r 
 */ 
void test_addRedBlackTree_add_10_to_tree_with_root_10_should_throw_error(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'b');
	Node *root = &node10;
  ErrorCode e;
  Try{
  addRedBlackTree(&root, &node10);
  TEST_FAIL_MESSAGE("Error");
  }
  Catch(e){
  TEST_ASSERT_EQUAL(ERROR_EQUAL_NODE,e);
  }
}
/**
 *      root           root
 *       |    add 1r    |
 *       V   ------->   V
 *      10b            5b right rotated
 *      /             /  \
 *    5r             1r  10r
 */ 
void test_addRedBlackTree_add_1_to_tree_should_right_rotate(void){
  setNode(&node1,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node10,&node5,NULL,'b');
	Node *root = &node10;

  addRedBlackTree(&root, &node1);
  TEST_ASSERT_EQUAL_PTR(root, &node5);
  
  TEST_ASSERT_EQUAL_NODE(&node1, &node10, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
}

/**
 *      root           root
 *       |    add 10r   |
 *       V   ------->   V
 *      15b            10b right Left rotated
 *      /             /  \
 *    5r            5r   15r
 */ 
void test_addRedBlackTree_add_10_to_tree_should_left_right_rotate(void){
  setNode(&node10,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node15,&node5,NULL,'b');
	Node *root = &node15;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node10);
  
  TEST_ASSERT_EQUAL_NODE(&node5, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}
/**
 *      root           root
 *       |    add 20r   |
 *       V   ------->   V
 *      15b            10b add only
 *      /             /  \
 *    5r            5r   20r
 */ 
void test_addRedBlackTree_add_10_to_tree_should_add_only(void){
  setNode(&node20,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node15,&node5,NULL,'b');
	Node *root = &node15;

  addRedBlackTree(&root, &node20);
  TEST_ASSERT_EQUAL_PTR(root, &node15);
  
  TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}
