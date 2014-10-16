#include "unity.h"
#include "CustomAssertion.h"

void assertNode(Node *left, Node *right, char color, Node *actualNode, int lineNumber){
              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  ^^^^^^^^^^^^^^^^^
              //          expected content                actual 
	UNITY_TEST_ASSERT_EQUAL_INT8(color, actualNode->color, lineNumber, "Wrong colour");
	UNITY_TEST_ASSERT_EQUAL_PTR(left, actualNode->left, lineNumber, "Wrong left node");
	UNITY_TEST_ASSERT_EQUAL_PTR(right, actualNode->right, lineNumber, "Wrong right node");
}