#include <iostream>
#include "tree.h"
#include "linked_list.h"

/*
  Arrays or Linked-lists do not allow both fast search and flexible update.
  With Binary search tree's these operations more or less take O(n) time
  if the tree is balanced.
*/

class bst : public tree {
	public:
	bst() : root{NULL} {}
	bst(std::initializer_list<int> l);
	bst(node *ll);

	/* creates a balaned bst from a sorted array */
	bst(int *a, int n);

	tree_node* find_min(tree_node* node);
	tree_node* find_max(tree_node *node);
	bool search_elem(int e) const override;
	void insert_elem(int e) override;
	void traverse_tree_inorder() const override;
	void delete_elem(int e);
	int LCA(int x, int y);
	void preorder_to_bst(int *a, int n);
	void postorder_to_bst(int *a, int n);
	void two_sum(int sum);

	private:
	tree_node *root;

	void insert_sorted_array(int *a, int i, int j);
	tree_node* ll_to_bst(node **headp, int n);
	tree_node* preorder_to_bst_util(tree_node *max, int *a, int *i, int n);
	tree_node* postorder_to_bst_util(tree_node *min, int *a, int *i);
	tree_node* delete_elem(tree_node *node, int e);
	tree_node* LCA(tree_node* node, int x, int y);
};
