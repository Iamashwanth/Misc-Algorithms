#include <iostream>

class node {
	public:
	int elem;
	node *next;

	node(): next {NULL} {}
	node(int e): elem {e}, next{NULL} {}
};

class linked_list {
	public:
	linked_list(): head {NULL}, tail {NULL} {}
	linked_list(std::initializer_list<int> l): head {NULL}, tail {NULL} {
		for (auto n:l) this->push_back(n);
	}

	void push_front(int e) {
		node *n = new node(e);

		if (head)
			n->next = head;
		else
			tail = n;
		head = n;
	}

	void push_back(int e) {
		if (!head) return push_front(e);

		tail->next = new node(e);
		tail = tail->next;
	}

	void pop_front() {
		node *tmp = head;
		if (!head) return;

		head = head->next;
		delete(tmp);

		if (!head) tail = NULL;
	}

	void pop_back() {
		node *tmp = head;
		if (!head) return;

		if (head == tail) return pop_front();

		while (tmp->next != tail) tmp = tmp->next;

		tmp->next = NULL;
		delete(tail);
		tail = tmp;
	}

	void reverse() {
		if (head == tail) return;

		tail = head;
		head = reverse(head, NULL);
	}

	node* reverse(node *n, node *p) {
		node *c;
		if (!n) return p;

		c = n->next;
		n->next = p;
		reverse(c, n);
	}

	void print_list() {
		node *n =  head;

		while (n) {
			std::cout << n->elem << " ";
			n = n->next;
		}

		std::cout << std::endl;
	}

	private:
	node *head, *tail;
};

int main() {
	linked_list l {11, 14, 67};
	l.push_front(1);
	l.push_front(2);
	l.push_front(4);
	l.push_front(1);
	l.push_back(5);
	l.push_back(9);
	l.print_list();
	l.pop_front();
	l.pop_back();
	l.pop_back();
	l.pop_back();
	l.print_list();
	l.reverse();
	l.print_list();
}
