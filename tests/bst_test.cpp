#include <iostream>
#include "test_framework.h"
#include "bst.h"

int bst_op_test(void *data) {
	int a[] = {1, 2, 3, 4, 5, 6};
	bst search_tree = {1, 2, 4, 0, 7, -4, -2, 3};
	bst st2(a, 0, 6);
	std::cout << "Search for 2 returned " << search_tree.search_elem(2) << std::endl;
	search_tree.traverse_tree_inorder();
	search_tree.delete_elem(3);
	search_tree.traverse_tree_inorder();
	st2.traverse_tree_inorder();
	return TEST_SUCCESS;
}

int bst_lca_test(void *data) {
	bst search_tree = {1, 2, 4, 0, 7, -4, -2, 3};
	std::cout << "LCA of 2 and 4 : " << search_tree.LCA(2, 4) << std::endl;
	return TEST_SUCCESS;
}

const TestFamily* bst_init() {
	TestFamily *testFamily = new TestFamily("bst", static_cast<int>(10));

	TEST_DEF(BST_OP_TEST, bst_op_test);
	TEST_DEF(LCA_TEST, bst_lca_test);

	return testFamily;
}
