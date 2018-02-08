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

	/*
	  Replace the element that need to be deleted with the minimum
	  element in the sub tree for which this node is a root.
	*/
	void delete_elem(int e) override {
		tree_node *node = root, *sub_root, *parent = NULL, *parent2 = NULL;

		std::cout << "Deleting element " << e << std::endl;

		if (!node) {
			std::cout << "Calling delete on an empty tree object\n";
			return;
		}

		while (node) {
			if (node->elem > e) {
				parent = node;
				node = node->left;
			} else if (node->elem < e) {
				parent = node;
				node = node->right;
			} else
				break;
		}

		if (!node) {
			std::cout << "element " << e << " is not present in the tree\n";
			return;
		}

		if (!node->left && !node->right) {
			if (!parent) {
				root = NULL;
			} else if (parent->elem > e) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
			delete node;
		} else if (!node->right) {
			if (!parent) {
				root = node->left;
			} else if (parent->elem > e) {
				parent->left = node->left;
			} else {
				parent->right = node->left;
			}
			delete node;
		} else if (!node->left) {
			if (!parent) {
				root = node->right;
			} else if (parent->elem > e) {
				parent->left = node->right;
			} else {
				parent->right = node->right;
			}
			delete node;
		} else {
			sub_root = node;
			node =  node->right;

			while (node->left) {
				parent2 = node;
				node = node->left;
			}

			if (!parent2) {
				if (!parent) {
					root = sub_root->right;
				} else if (parent->elem > e) {
					parent->left = sub_root->right;
				} else {
					parent->right = sub_root->right;
				}
				node->left =  sub_root->left;
			} else {
				parent2->left = node->right;

				if (!parent) {
					root = node;
				} else if (parent->elem > e) {
					parent->left = node;
				} else {
					parent->right = node;
				}

				node->left = sub_root->left;
				node->right = sub_root->right;
			}

			delete sub_root;
		}
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

	return 0;
}
