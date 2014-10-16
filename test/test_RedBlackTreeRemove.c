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

void test_module_generator_needs_to_be_implemented(void){


}
