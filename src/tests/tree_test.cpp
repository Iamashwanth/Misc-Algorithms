#include <iostream>
#include "test_framework.h"
#include "tree.h"

void create_treex(tree_node *x) {
	x = new tree_node(1);
	x->left = new tree_node(2);
	x->right = new tree_node(3);
	x->left->left = new tree_node(4);
	x->left->right = new tree_node(5);
	x->right->left = new tree_node(6);
	x->left->right->left = new tree_node(7);
	x->left->right->right = new tree_node(8);
}

void create_treey(tree_node *y) {
	y = new tree_node(1);
	y->left = new tree_node(3);
	y->right = new tree_node(2);
	y->left->right = new tree_node(6);
	y->right->left = new tree_node(4);
	y->right->right = new tree_node(5);
	y->right->right->right = new tree_node(7);
	y->right->right->left = new tree_node(8);
}

int isomorphic_test(void *data) {
	tree_node *x, *y;
	create_treex(x);
	create_treey(y);

	if (is_isomorphic(x, y)) return TEST_SUCCESS;
	else return TEST_FAILURE;
}

const TestFamily* tree_init() {
    TestFamily *testFamily = new TestFamily("trees", static_cast<int>(10));

    TEST_DEF(ISOMORPHIC_TEST, isomorphic_test);

    return testFamily;
}
