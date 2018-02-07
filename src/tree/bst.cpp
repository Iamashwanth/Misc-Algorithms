#include <iostream>
#include "tree.h"

/*
  Arrays or Linked-lists do not allow both fast search and flexible update.
  With Binary search tree's these operations more or less take O(n) time
  if the tree is balanced.
*/

class bst : public tree {
	public:
	bst() : root{NULL} {}

	int find_min() {
		tree_node *node {root};

		if (!node) throw;

		while(node->left)
			node = node->left;

		return node->elem;
	}

	int find_max() {
		tree_node *node {root};

		if (!node) throw;

		while(node->right)
			node = node->right;

		return node->elem;
	}

	bool search_elem(int e) const override {
		tree_node *node = root;

		while (node) {
			if (node->elem > e)
				node = node->left;
			else if (node->elem < e)
				node = node->right;
			else
				return true;
		}

		return false;
	}

	void insert_elem(int e) override {
		tree_node *node = root, *parent = NULL;

		while (node) {
			parent = node;

			if (node->elem > e)
				node =  node->left;
			else if (node->elem < e)
				node = node->right;
			else
				throw;
		}

		node = new tree_node(e);

		if (!parent)
			root = node;
		else if (parent->elem > e)
			parent->left = node;
		else
			parent->right = node;

	}

	void traverse_tree_inorder() const override {
		traverse_tree_inorder_int(root);
	}

	void delete_elem(int elem) override {}

	private:
	tree_node *root;

	void traverse_tree_inorder_int(const tree_node *node) const {
		if (node) {
			traverse_tree_inorder_int(node->left);
			std::cout << node->elem << std::endl;
			traverse_tree_inorder_int(node->right);
		}
	}
};

int main() {
	bst search_tree;
	search_tree.insert_elem(1);
	search_tree.insert_elem(2);
	search_tree.insert_elem(4);
	search_tree.insert_elem(0);
	search_tree.insert_elem(7);
	search_tree.insert_elem(-4);
	search_tree.insert_elem(-2);
	std::cout << search_tree.search_elem(2) << std::endl;
	search_tree.traverse_tree_inorder();

	return 0;
}
