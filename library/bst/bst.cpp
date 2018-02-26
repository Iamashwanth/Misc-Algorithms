#include <iostream>
#include "tree.h"
#include "bst.h"

/*
  Arrays or Linked-lists do not allow both fast search and flexible update.
  With Binary search tree's these operations more or less take O(n) time
  if the tree is balanced.
*/

bst::bst(std::initializer_list<int> l) {
	root = NULL;
	for (auto it=l.begin(); it!=l.end(); it++) {
		this->insert_elem(*it);
	}
}

/* creates a balaned bst from a sorted array */
bst::bst(int *a, int n) {
	root = NULL;
	insert_sorted_array(a, 0, n-1);
}

/* creates a balaned bst from a linked list */
bst::bst(node *ll) {
	int n = 0;
	node *temp = ll;

	while (temp) {
		temp = temp->next;
		n++;
	}

	root = ll_to_bst(&ll, n);
}

tree_node* bst::find_min(tree_node* node) {

	if (!node) node = root;
	if (!node) throw;

	while(node->left)
		node = node->left;

	return node;
}

tree_node* bst::find_max(tree_node *node) {

	if (!node) node = root;
	if (!node) throw;

	while(node->right)
		node = node->right;

	return node;
}

bool bst::search_elem(int e) const {
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

void bst::insert_elem(int e) {
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

void bst::traverse_tree_inorder() const {
	std::cout << "Inorder Traversal\n";
	inorder_print(root);
	std::cout << "\n";
}

void bst::delete_elem(int e) {
	std::cout << "Deleting node " << e << std::endl;
	delete_elem(root, e);
}

int bst::LCA(int x, int y) {
	tree_node *temp;
	temp = LCA(root, x , y);
	if (temp) return temp->elem;
	else throw;
}

void bst::insert_sorted_array(int *a, int i, int j) {
	int mid = i + (j - i) / 2;

	if (i > j) return;

	insert_elem(a[mid]);

	insert_sorted_array(a, i, mid-1);
	insert_sorted_array(a, mid+1, j);
}

tree_node* bst::ll_to_bst(node **headp, int n) {
	tree_node *left, *root;

	if (n <= 0) return NULL;

	left = ll_to_bst(headp, n/2);

	root = new tree_node((*headp)->elem);

	root->left = left;

	*headp = (*headp)->next;

	root->right = ll_to_bst(headp, n - n/2 - 1);

	return root;
}

/* If the preorder traversal is saved along with the markers for NULL nodes,
   reconstructing the tree would be straightforward */
void bst::preorder_to_bst(int *a, int n) {
	int i = 0;
	root = preorder_to_bst_util(NULL, a, &i, n);
}

/* We pass down the parent node as the max arguemnt to make a switch to the
   right sub-tree whenever an element is greater than the max that is passed */

tree_node* bst::preorder_to_bst_util(tree_node *max, int *a, int *i, int n) {
	if (*i == n) return NULL;

	if (max && a[*i] > max->elem) return NULL;

	tree_node *tn = new tree_node(a[*i]);

	(*i)++;

	tn->left = preorder_to_bst_util(tn, a, i, n);
	tn->right = preorder_to_bst_util(max, a, i, n);

	return tn;
}

tree_node* bst::delete_elem(tree_node *node, int e) {

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

tree_node* bst::LCA(tree_node* node, int x, int y) {
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
