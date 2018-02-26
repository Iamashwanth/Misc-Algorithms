#include <iostream>

class node {
	public:
	int elem;
	node *next;

	node(): next {NULL} {}
	node(int e): elem {e}, next{NULL} {}
	node(int e, node *n): elem {e}, next{n} {}
};

class linked_list {
	public:
	linked_list(): head {NULL}, tail {NULL} {}
	linked_list(std::initializer_list<int> l): head {NULL}, tail {NULL} {
		for (auto n:l) this->push_back(n);
	}

	void push_front(int e);
	void push_back(int e);
	void pop_front();
	void pop_back();
	void reverse();
	void reverse(int n, int alt = 0);
	node* reverse(node *n, node *p, node *end);
	void reverse_i();
	void reverse_i(int a, int b);
	void print_list();
	static void print_list_util(node *n);
	static node* sum_list(node *a, node *b);
	static node* sum_list_internal(node *a, node *b);

	private:
	node *head, *tail;
};

node* detect_loop(node *head);
void remove_loop(node *head);
