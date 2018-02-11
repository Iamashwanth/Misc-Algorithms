#include <iostream>
#include <list>
#include "tree.h"

void inorder_save(tree_node *node, std::list<int> &l) {
	if (!node) return;

	inorder_save(node->left, l);
	l.push_back(node->elem);
	inorder_save(node->right, l);
}

void inorder_restore(tree_node *node, std::list<int> &l) {
	if (!node) return;

	inorder_restore(node->left, l);
	node->elem = l.front();
	l.pop_front();
	inorder_restore(node->right, l);
}

void bt_2_bst(tree_node *root) {
	std::list<int> l;
	inorder_print(root);
	std::cout << std::endl;
	inorder_save(root, l);
	l.sort();
	inorder_restore(root, l);
	inorder_print(root);
	std::cout << std::endl;
}

bool is_isomorphic(tree_node *x, tree_node *y) {
	if (!x && !y) return true;

	if ((!x && y) || (x && !y)) return false;

	if (x->elem != y->elem) return false;

	return ((is_isomorphic(x->left, y->left) && is_isomorphic(x->right, y->right)) ||
		(is_isomorphic(x->left, y->right) && is_isomorphic(x->right, y->left)));
}

void print_left_edge(tree_node *node) {
	if (node && (node->left || node->right)) {
		std::cout << node->elem << " ";
		print_left_edge(node->left);
	}
}

void print_right_edge(tree_node *node) {
	if (node && (node->left || node->right)) {
		print_right_edge(node->right);
		std::cout << node->elem << " ";
	}
}

void print_leaf(tree_node *node) {
	if (!node) return;

	if (!node->left && !node->right) {
		std::cout << node->elem << " ";
		return;
	}

	print_leaf(node->left);
	print_leaf(node->right);
}

void bounary_traversal(tree_node *node) {
	print_left_edge(node);
	print_leaf(node);
	if (node->right) print_right_edge(node->right);
	std::cout << std::endl;
}

int main() {
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
	inorder_print(x);
	std::cout << "\nInorder Access tree 2 ";
	inorder_print(y);
	std::cout << std::endl;

	std::cout << "Isomorphic " << is_isomorphic(x, y) << std::endl;

	bt_2_bst(y);
	bounary_traversal(x);
	return 0;
}
