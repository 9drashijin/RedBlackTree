#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include "InitNode.h"
#include "RedBlackTree.h"
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
void tearDown(void){}

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
 *      15b            15b add only
 *      /             /  \
 *    5r            5r   20r
 */
void test_addRedBlackTree_add_20_to_tree_should_add_only(void){
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
/**
 *      root           root
 *       |    add 10r   |
 *       V   ------->   V
 *      15b            15b add only
 *         \          /   \
 *         20r      10r   20r
 */
void test_addRedBlackTree_add_10_to_tree_should_add_only(void){
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node15,NULL,&node20,'b');
	Node *root = &node15;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node15);

  TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}
/**
 *      root           root
 *       |    add 15r   |
 *       V   ------->   V
 *      10b            15b right Left Rotated
 *         \          /   \
 *         20r      10r   20r
 */
void test_addRedBlackTree_add_10_to_tree_should_right_left_rotate(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;

  addRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root, &node15);

  TEST_ASSERT_EQUAL_NODE(&node10, &node20, 'b', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node20);
}
/**
 *      root           root
 *       |    add 30r   |
 *       V   ------->   V
 *      10b            20b left Rotated
 *         \          /   \
 *         20r      10r   30r
 */
void test_addRedBlackTree_add_10_to_tree_should_left_rotate(void){
  setNode(&node30,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node10,NULL,&node20,'b');
	Node *root = &node10;

  addRedBlackTree(&root, &node30);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node30);
}

//////////////
//  4 Node  //
//////////////
/**
 *      root           root
 *       |    add 5r    |
 *       V   ------->   V
 *      20b            20b no rotate
 *     /   \          /   \
 *   10r   30r      10b   30b
 *   /              /
 *  5r            5r
 */
void test_addRedBlackTree_add_5_should_not_rotate_and_flip_colour(void){
  setNode(&node5,NULL,NULL,'r');
  setNode(&node30,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node20,&node10,&node30,'b');
	Node *root = &node20;

  _addRedBlackTree(&root, &node5);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'r', &node20);
  TEST_ASSERT_EQUAL_NODE(&node5, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node5);
}
/**
 *      root           root
 *       |    add 15r   |
 *       V   ------->   V
 *      20b            20b no rotate
 *     /   \          /   \
 *   10r   30r      10b   30b
 *     \               \
 *     15r             15r
 */
void test_addRedBlackTree_add_15_should_not_rotate_and_flip_colour(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node30,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node20,&node10,&node30,'b');
	Node *root = &node20;

  _addRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'r', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
}
/**
 *      root           root
 *       |    add 15r   |
 *       V   ------->   V
 *      20b            20b no rotate
 *     /   \          /   \
 *   10r   30r      10b   30b
 *        /               /
 *      25r             25r
 */
void test_addRedBlackTree_add_25_should_not_rotate_and_flip_colour(void){
  setNode(&node25,NULL,NULL,'r');
  setNode(&node30,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node20,&node10,&node30,'b');
	Node *root = &node20;

  _addRedBlackTree(&root, &node25);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'r', &node20);
  TEST_ASSERT_EQUAL_NODE(&node25, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node25);
}
/**
 *      root           root
 *       |    add 15r   |
 *       V   ------->   V
 *      20b            20b no rotate
 *     /   \          /   \
 *   10r   30r      10b   30b
 *           \              \
 *           35r            35r
 */
void test_addRedBlackTree_add_35_should_not_rotate_and_flip_colour(void){
  setNode(&node35,NULL,NULL,'r');
  setNode(&node30,NULL,NULL,'r');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node20,&node10,&node30,'b');
	Node *root = &node20;

  _addRedBlackTree(&root, &node35);
  TEST_ASSERT_EQUAL_PTR(root, &node20);

  TEST_ASSERT_EQUAL_NODE(&node10, &node30, 'r', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node35, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node10);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node35);
}

/**
 *        root           root
 *         |    add 10r   |
 *         V   ------->   V
 *        25b            25b    =>     25b
 *       /   \          /   \         /   \
 *     15b   30b      15b   30b     15r   30b
 *    /  \           /  \          /  \
 *   5r  20r       5r   20r      5b   20b
 *                   \             \
 *                   10r           10r
 */
void test_addRedBlackTree_add_10_should_not_rotate_and_promote_then_flip_colour(void){
  setNode(&node10,NULL,NULL,'r');
  setNode(&node5,NULL,NULL,'r');
  setNode(&node20,NULL,NULL,'r');
  setNode(&node15,&node5,&node20,'b');
  setNode(&node30,NULL,NULL,'b');
  setNode(&node25,&node15,&node30,'b');
	Node *root = &node25;

  addRedBlackTree(&root, &node10);
  TEST_ASSERT_EQUAL_PTR(root, &node25);

  TEST_ASSERT_EQUAL_NODE(&node15, &node30, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(&node5, &node20, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node10, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node10);
}
/**
 *        root                root
 *         |      add 15r      |
 *         V     ------->      V
 *         30b                30b       =>        30b
 *       /     \            /     \             /     \
 *      5r     40r         5r     40r          5b     40b
 *    /  \     /  \      /  \     /  \       /  \     /  \
 *  1b   20b 35b  45b  1b   20b 35b  45b   1b   20r 35b  45b
 *      /  \               /  \                /  \
 *   10r   25r          10r   25r            10b   25b
 *                         \                   \
 *                         15r                 15r
 */
void test_addRedBlackTree_add_10_should_not_rotate_and_promote_2_time_then_flip_colour(void){
  setNode(&node15,NULL,NULL,'r');
  setNode(&node1,NULL,NULL,'b');
  setNode(&node10,NULL,NULL,'r');
  setNode(&node25,NULL,NULL,'r');
  setNode(&node35,NULL,NULL,'b');
  setNode(&node45,NULL,NULL,'b');

  setNode(&node20,&node10,&node25,'b');
  setNode(&node5,&node1,&node20,'r');
  setNode(&node40,&node35,&node45,'r');
  setNode(&node30,&node5,&node40,'b');
	Node *root = &node30;

  addRedBlackTree(&root, &node15);
  TEST_ASSERT_EQUAL_PTR(root, &node30);

  TEST_ASSERT_EQUAL_NODE(&node5, &node40, 'b', &node30);
  TEST_ASSERT_EQUAL_NODE(&node1, &node20, 'b', &node5);
  TEST_ASSERT_EQUAL_NODE(&node35, &node45, 'b', &node40);
  TEST_ASSERT_EQUAL_NODE(&node10, &node25, 'r', &node20);
  TEST_ASSERT_EQUAL_NODE(NULL, &node15, 'b', &node10);

  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'r', &node15);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node1);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node25);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node35);
  TEST_ASSERT_EQUAL_NODE(NULL, NULL, 'b', &node45);
}