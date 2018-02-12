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
	std::cout << "Inorder traversal of BT\n";
	inorder_print(root);
	std::cout << std::endl;
	inorder_save(root, l);
	l.sort();
	inorder_restore(root, l);
	std::cout << "Inorder traversal of BST\n";
	inorder_print(root);
	std::cout << std::endl << std::endl;
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
	std::cout << "Boundary traversal\n";
	print_left_edge(node);
	print_leaf(node);
	if (node->right) print_right_edge(node->right);
	std::cout << std::endl << std::endl;
}

tree_node* LCA(tree_node *node, int x, int y) {
	tree_node *left, *right;

	if (!node) return NULL;

	if (node->elem == x || node->elem == y) {
		return node;
	}

	left = LCA(node->left, x, y);

	if (left && left->elem != x && left->elem != y) return left;

	right = LCA(node->right, x, y);

	if (left && right) return node;
	return left ? left : right;
}

int height(tree_node *node, int e) {
	int left, right;

	if (!node) return -1;
	if (node->elem == e) return 0;

	left = height(node->left, e);
	if (left != -1) return left+1;

	right = height(node->right, e);
	if (right != -1) return right+1;
}

int shortest_path(tree_node *node, int x, int y) {
	tree_node *lca = LCA(node, x, y);
	return height(lca, x) + height(lca, y);
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
	std::cout << std::endl << std::endl;

	std::cout << "Isomorphic " << is_isomorphic(x, y) << "\n\n";

	bt_2_bst(y);
	bounary_traversal(x);
	std::cout << "LCA of 1 and 5 is " << (LCA(x, 1, 5))->elem << "\n\n";
	std::cout << "Height of node 7 is " << height(x, 7) << "\n\n";
	std::cout << "Shortest path between 8 and 6 is " << shortest_path(x, 8, 6) << "\n\n";
	return 0;
}
