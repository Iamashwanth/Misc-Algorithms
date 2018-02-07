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
	virtual ~tree() {};
};

#endif
