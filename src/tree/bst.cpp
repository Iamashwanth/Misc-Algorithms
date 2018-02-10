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

	tree_node* find_min(tree_node* node) {

		if (!node) node = root;
		if (!node) throw;

		while(node->left)
			node = node->left;

		return node;
	}

	tree_node* find_max(tree_node *node) {

		if (!node) node = root;
		if (!node) throw;

		while(node->right)
			node = node->right;

		return node;
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

		std::cout << "Insert element " << e << std::endl;
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
		std::cout << "Inorder Traversal\n";
		traverse_tree_inorder_int(root);
		std::cout << "\b\b\b   \n";
	}

	void delete_elem(int e) {
		std::cout << "Deleting node " << e << std::endl;
		delete_elem_int(root, e);
	}

	int LCA(int x, int y) {
		tree_node *temp;
		temp = LCA_int(root, x , y);
		if (temp) return temp->elem;
		else throw;
	}

	private:
	tree_node *root;

	void traverse_tree_inorder_int(const tree_node *node) const {
		if (node) {
			traverse_tree_inorder_int(node->left);
			std::cout << node->elem << " -> ";
			traverse_tree_inorder_int(node->right);
		}
	}

	tree_node* delete_elem_int(tree_node *node, int e) {

		if (!node) return NULL;

		if (node->elem > e) {
			node->left = delete_elem_int(node->left, e);
		} else if (node->elem < e ) {
			node->right = delete_elem_int(node->right, e);
		} else {
			if (!node->left) {
				tree_node *ret = node->right;
				delete node;
				return ret;
			} else if (!node->right) {
				tree_node *ret = node->left;
				delete node;
				return ret;
			} else {
				tree_node *temp = find_min(node->right);
				node->elem = temp->elem;

				node->right = delete_elem_int(node->right, node->elem);
			}
		}

		return node;
	}

	tree_node* LCA_int(tree_node* node, int x, int y) {
		if (!node) return NULL;

		if (node->elem > x && node->elem > y) {
			LCA_int(node->left, x, y);
		} else if (node->elem < x && node->elem < y) {
			return LCA_int(node->right, x, y);
		} else if (node->elem >= x && node->elem <=y) {
			return node;
		}

		return NULL;
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
	search_tree.insert_elem(3);
	std::cout << "Search for 2 returned " << search_tree.search_elem(2) << std::endl;
	search_tree.traverse_tree_inorder();
	search_tree.delete_elem(3);
	search_tree.traverse_tree_inorder();
	std::cout << "LCA of 0 and 4 : " << search_tree.LCA(4, 0) << std::endl;
	return 0;
}
