#include <iostream>
#include "test_framework.h"
#include "tree.h"

int tree_test(void *data) {
	tree_node *x = new tree_node(1);
	x->left = new tree_node(2);
	x->right = new tree_node(3);
	x->left->left = new tree_node(4);
	x->left->right = new tree_node(5);
	x->right->left = new tree_node(6);
	x->left->right->left = new tree_node(7);
	x->left->right->right = new tree_node(8);

	tree_node *y = new tree_node(1);
	y->left = new tree_node(3);
	y->right = new tree_node(2);
	y->left->right = new tree_node(6);
	y->right->left = new tree_node(4);
	y->right->right = new tree_node(5);
	y->right->right->right = new tree_node(7);
	y->right->right->left = new tree_node(8);

	std::cout << "Inorder Access tree 1 ";
	tree::traverse_tree_inorder(x);
	std::cout << "\nInorder Access tree 2 ";
	tree::traverse_tree_inorder(y);
	std::cout << std::endl << std::endl;

	std::cout << "Isomorphic " << is_isomorphic(x, y) << "\n\n";

	std::cout << "is y bst? " << is_bst(y) << "\n\n";
	bt_2_bst(y);
	std::cout << "is y bst? " << is_bst_inorder(y) << "\n\n";

	bounary_traversal(x);
	std::cout << "LCA of 1 and 5 is " << (LCA(x, 1, 5))->elem << "\n\n";
	std::cout << "Height of node 7 is " << height(x, 7) << "\n\n";
	std::cout << "Shortest path between 8 and 6 is " << shortest_path(x, 8, 6) << "\n\n";
	return TEST_SUCCESS;
}

int fix_bst_node_test(void *data) {
	tree_node *x = new tree_node(4);
	x->left = new tree_node(6);
	x->right = new tree_node(2);
	x->left->left = new tree_node(1);
	x->left->right = new tree_node(3);
	x->right->left = new tree_node(5);
	x->right->right = new tree_node(7);

	std::cout << "Inorder Access before fixing " << std::endl;
	tree::traverse_tree_inorder(x);
	std::cout << std::endl;
	fix_bst_2_node(x);
	std::cout << "Inorder Access after fixing " << std::endl;
	tree::traverse_tree_inorder(x);
	std::cout << std::endl;

	return TEST_SUCCESS;
}

const TestFamily* tree_init() {
    TestFamily *testFamily = new TestFamily("trees", static_cast<int>(10));

    TEST_DEF(TREE_TEST, tree_test);
    TEST_DEF(FIX_BST_TEST, fix_bst_node_test);

    return testFamily;
}
