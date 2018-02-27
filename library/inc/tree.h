#ifndef TREE_H
#define TREE_H

class tree_node {
	public:
	int elem;
	tree_node *left;
	tree_node *right;

	tree_node() : elem{0}, left{NULL}, right{NULL} {}
	tree_node(int e) : elem{e}, left{NULL}, right{NULL} {}
};

class tree {
	public:
	virtual void insert_elem(int e) = 0;
	virtual void delete_elem(int e) = 0;
	virtual bool search_elem(int e) const = 0;
	virtual void traverse_tree_inorder() const = 0;

	static void traverse_tree_inorder(tree_node *node);
	static void traverse_tree_inorder_i(tree_node *node);

	virtual ~tree() {};
};

bool is_bst(tree_node *node, tree_node *min = NULL, tree_node *max = NULL);
bool is_bst_inorder(tree_node *node);
void bt_2_bst(tree_node *root);
bool is_isomorphic(tree_node *x, tree_node *y);
void bounary_traversal(tree_node *node);
tree_node* LCA(tree_node *node, int x, int y);
int height(tree_node *node, int e);
int shortest_path(tree_node *node, int x, int y);
int fix_bst_2_node(tree_node *root);
void fix_bst_2_node_util(tree_node *cur, tree_node **prev, tree_node **n1,
			 tree_node **n1p, tree_node **n2);

#endif
