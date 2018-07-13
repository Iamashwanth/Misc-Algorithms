#include <iostream>
#include "test_framework.h"
#include "bst.h"

int bst_op_test(void *data) {
	int a[] = {1, 2, 3, 4, 5, 6};
	bst search_tree = {1, 2, 4, 0, 7, -4, -2, 3};
	bst st2(a, 6);
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

int ll_to_bst_test(void *data) {
	node *a = new node(3, new node(4, new node(7, new node(9, NULL))));

	bst st(a);
	st.traverse_tree_inorder();
	return TEST_SUCCESS;
}

int pre_to_bst_test(void *data) {
	int a[] = {3, 1, 0, 2, 4, 5};
	bst st;

	st.preorder_to_bst(a, 6);
	st.traverse_tree_inorder();

	return TEST_SUCCESS;
}

int post_to_bst_test(void *data) {
	int a[] = {1, 3, 2, 5, 7, 6, 4};
	bst st;

	st.postorder_to_bst(a, 7);
	st.traverse_tree_inorder();

	return TEST_SUCCESS;
}

int two_sum_bst_test(void *data) {
	bst st = {1, 2, 4, 0, 7, -4, -2, 3};
	st.two_sum(10);

	return TEST_SUCCESS;
}

int greater_sum_test(void *data) {
	bst st = {1, 2, 4, 0, 7, -4, -2, 3};
	st.greater_sum();

	st.traverse_tree_inorder();

	return TEST_SUCCESS;
}

const TestFamily* bst_init() {
	TestFamily *testFamily = new TestFamily("bst", static_cast<int>(10));

	TEST_DEF(BST_OP_TEST, bst_op_test);
	TEST_DEF(LCA_TEST, bst_lca_test);
	TEST_DEF(LL_2_BST_TEST, ll_to_bst_test);
	TEST_DEF(PRE_2_BST_TEST, pre_to_bst_test);
	TEST_DEF(POST_2_BST_TEST, post_to_bst_test);
	TEST_DEF(TWO_SUM_TEST, two_sum_bst_test);
	TEST_DEF(GREATER_SUM_TEST, greater_sum_test);

	return testFamily;
}
