#include <iostream>
#include <list>
#include "tree.h"

void inorder_save(tree_node *node, std::list<int> &l) {
	if (!node) return;

	inorder_save(node->left, l);
	l.push_back(node->elem);
	inorder_save(node->right, l);
}

void inorder_restore(tree_node *node, std::list<int> &q) {
	if (!node) return;

	inorder_restore(node->left, q);
	node->elem = q.front();
	q.pop_front();
	inorder_restore(node->right, q);
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

int main() {
	tree_node *root = new tree_node(2);
	root->left = new tree_node(4);
	root->right = new tree_node(5);
	root->right->left = new tree_node(1);
	root->right->right = new tree_node(-1);
	root->left->left = new tree_node(0);
	root->left->right = new tree_node(6);
	bt_2_bst(root);
	return 0;
}
