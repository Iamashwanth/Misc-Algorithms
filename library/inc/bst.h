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
	bst(std::initializer_list<int> l) {
		root = NULL;
		for (auto it=l.begin(); it!=l.end(); it++) {
			this->insert_elem(*it);
		}
	}

	/* creates a balaned bst from a sorted array */
	bst(int *a, int s, int n) {
		root = NULL;
		insert_sorted_array(a, s, n-1);
	}

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
		inorder_print(root);
		std::cout << "\n";
	}

	void delete_elem(int e) {
		std::cout << "Deleting node " << e << std::endl;
		delete_elem(root, e);
	}

	int LCA(int x, int y) {
		tree_node *temp;
		temp = LCA(root, x , y);
		if (temp) return temp->elem;
		else throw;
	}

	private:
	tree_node *root;

	void insert_sorted_array(int *a, int i, int j) {
		int mid = i + (j - i) / 2;

		if (i > j) return;

		insert_elem(a[mid]);

		insert_sorted_array(a, i, mid-1);
		insert_sorted_array(a, mid+1, j);
	}

	tree_node* delete_elem(tree_node *node, int e) {

		if (!node) return NULL;

		if (node->elem > e) {
			node->left = delete_elem(node->left, e);
		} else if (node->elem < e ) {
			node->right = delete_elem(node->right, e);
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

				node->right = delete_elem(node->right, node->elem);
			}
		}

		return node;
	}

	tree_node* LCA(tree_node* node, int x, int y) {
		if (!node) return NULL;

		if (node->elem > x && node->elem > y) {
			LCA(node->left, x, y);
		} else if (node->elem < x && node->elem < y) {
			return LCA(node->right, x, y);
		} else if (node->elem >= x && node->elem <=y) {
			return node;
		}

		return NULL;
	}

};
