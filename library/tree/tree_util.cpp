#include <iostream>
#include <list>
#include <vector>
#include "tree.h"

void tree::traverse_tree_inorder(tree_node *node) {
	if (!node) return;

	traverse_tree_inorder(node->left);
	std::cout << node->elem << " ";
	traverse_tree_inorder(node->right);
}

/* Here we are trying to simulate recusrive behavior by using a stack.
   Pushing the left nodes is equivalent to traversing down the left edge.
   Pop the current node once we hit with a leaf and try to traverse the
   left edge of the right node. */

void tree::traverse_tree_inorder_i(tree_node *node) {
	std::vector<tree_node*> s;

	while (node || s.size()) {
		while (node) {
			s.push_back(node);
			node = node->left;
		}

		node = s.back();
		s.pop_back();

		std::cout << node->elem << " ";

		node = node->right;
	}
}

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

/* In this approach we pass down the parent node either using
   the min or max agrument based on whether we are checking
   the left or the right sub-tree. */

bool is_bst(tree_node *node, tree_node *min, tree_node *max) {
	if (!node) return true;

	if (min and node->elem < min->elem) return false;
	if (max and node->elem > max->elem) return false;

	return is_bst(node->left, min, node) &&
		is_bst(node->right, node, max);
}

/* Keep track of the previous node and use it to check if inorder traversal
   results in non-decreasing sequence */

bool is_bst_inorder(tree_node *node) {
	static tree_node *prev = NULL;

	if (!node) return true;

	if (!is_bst_inorder(node->left) ||
	    (prev && node->elem < prev->elem))
		return false;

	prev = node;
	return is_bst_inorder(node->right);
}

void bt_2_bst(tree_node *root) {
	std::list<int> l;
	std::cout << "Inorder traversal of BT\n";
	tree::traverse_tree_inorder(root);
	std::cout << std::endl;
	inorder_save(root, l);
	l.sort();
	inorder_restore(root, l);
	std::cout << "Inorder traversal of BST\n";
	tree::traverse_tree_inorder(root);
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

void fix_bst_2_node_util(tree_node *cur, tree_node **prev, tree_node **n1,
			 tree_node **n1p, tree_node **n2) {
	if (!cur) return;

	fix_bst_2_node_util(cur->left, prev, n1, n1p, n2);

	if (*prev && cur->elem < (*prev)->elem) {
		if (!(*n1)) {
			*n1 = cur;
			*n1p = *prev;
		} else {
			*n2 = cur;
		}
	}

	*prev = cur;

	fix_bst_2_node_util(cur->right, prev, n1, n1p, n2);
}

int fix_bst_2_node(tree_node *root) {
	tree_node *n1, *n1p, *n2, *prev;
	n1 = n2 = n1p = prev = NULL;
	int tmp;

	fix_bst_2_node_util(root, &prev, &n1, &n1p, &n2);

	if (n2) {
		tmp = n1p->elem;
		n1p->elem = n2->elem;
		n2->elem = tmp;
	} else {
		n2 = n1;;
		tmp = n1p->elem;
		n1p->elem = n2->elem;
		n2->elem = tmp;
	}
}

int find_ndist(tree_node *n, tree_node *tn, int dist, int cur_dist) {
	if (!n) return 0;

	if (dist == cur_dist) {
		std::cout << n->elem << " ";
		return 0;
	}

	if (tn == n || cur_dist) {
		find_ndist(n->left, tn, dist, cur_dist+1);
		find_ndist(n->right, tn, dist, cur_dist+1);
		return tn == n;
	} else {
		int l,r;

		l = find_ndist(n->left, tn, dist, 0);
		r = find_ndist(n->right, tn, dist, 0);

		if (l) {
			if (l == dist) {
				std::cout << n->elem << " ";
				return 0;
			} else {
				find_ndist(n->right, tn, dist, l+1);
				return l+1;
			}
		} else if (r) {
			if (r == dist) {
				std::cout << n->elem << " ";
				return 0;
			} else {
				find_ndist(n->left, tn, dist, r+1);
				return r+1;
			}
		} else {
			return 0;
		}
	}
}
