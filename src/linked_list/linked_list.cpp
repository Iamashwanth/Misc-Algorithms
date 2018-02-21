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
		head = reverse(head, NULL, NULL);
	}

	void reverse(int n, int alt = 0) {
		int i, rev = 1;
		node *start_p = NULL, *start = head;
		node *end = start, *end_n, *ret;

		while (start) {
			for (i = 1; i < n && end->next; i++) {
				end = end->next;
			}
			end_n = end->next;

			if (rev) {
				ret = reverse(start, end_n, end_n);

				if (start_p) start_p->next = ret;
				else head = ret;

				start_p = start;
			} else {
				start_p = end;
			}

			if (alt) rev = rev ? 0 : 1;

			end = start = end_n;
		}

		tail = start_p;
	}

	node* reverse(node *n, node *p, node *end) {
		node *c;
		if (!n || n == end) return p;

		c = n->next;
		n->next = p;
		reverse(c, n, end);
	}

	void reverse_i() {
		node *n = head, *p = NULL, *c;

		if (head == tail) return;

		while (n) {
			c = n->next;
			n->next = p;
			p = n;
			n = c;
		}

		tail = head;
		head  = p;
	}

	void reverse_i(int a, int b) {
		node *start, *end;
		node *p = NULL, *c, *n = head;
		int i = 1;

		if (a == b) return;

		while (i < a) {
			p = n;
			n = n->next;
			i++;
		}

		start = n;

		while (i < b) {
			n = n->next;
			i++;
		}

		end = n;

		if (p) {
			p->next =  end;
		} else {
			head = end;
		}

		if (end == tail) tail = start;

		p = end->next;
		n = start;

		while (n != end) {
			c = n->next;
			n->next = p;
			p = n;
			n = c;
		}

		n->next = p;
	}

	void print_list() {
		print_list_util(head);
	}

	static void print_list_util(node *n) {

		while (n) {
			std::cout << n->elem << " ";
			n = n->next;
		}

		std::cout << std::endl;
	}

	static node* sum_list(node *a, node *b) {
		node *sum = sum_list_internal(a, b);

		if (sum && sum->elem >= 10) {
			sum = new node(sum->elem/10, sum);
			sum->next->elem = sum->next->elem%10;
		}

		return sum;
	}

	static node* sum_list_internal(node *a, node *b) {
		if (!a || !b) return NULL;

		node *ret;
		node *sum = new node(a->elem + b->elem);

		sum->next = sum_list_internal(a->next, b->next);

		if (sum->next && sum->next->elem >= 10) {
			sum->elem += sum->next->elem/10;
			sum->next->elem = sum->next->elem%10;
		}

		return sum;
	}

	private:
	node *head, *tail;
};

node* detect_loop(node *head) {
	node *s, *f;

	if (!head) return NULL;

	s = f = head;

	do {
		s = s->next;
		if (!s) return NULL;

		f = f->next;
		if (!f) return NULL;

		f = f->next;
		if (!f) return NULL;

	} while (s != f);

	return s;
}

void remove_loop(node *head) {
	int i = 0, n = 1;
	node *loop = detect_loop(head);
	node *tmp, *f, *s;

	if (!loop) return;

	tmp = loop->next;
	while (tmp != loop) {
		tmp = tmp->next;
		n++;
	}

	std::cout << n << std::endl;

	f = s = head;

	while(i++ < n) s = s->next;

	while(s->next != f->next) {
		s = s->next;
		f = f->next;
	}

	s->next = NULL;
}

int main() {
	//Test basic operations
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
	l.print_list();

	//Test reverse routines
	l.reverse();
	l.print_list();
	l.reverse_i();
	l.print_list();
	l.reverse_i(2, 6);
	l.print_list();

	//Test loops
	node *loop = new node(3);
	node *ll = new node(1, new node(2, loop));
	loop->next = new node(4, new node(5, new node(6, loop)));
	std::cout << "Loop ? " << (bool)detect_loop(ll) << std::endl;
	remove_loop(ll);
	linked_list::print_list_util(ll);

	//Test reverse K nodes and alternate K nodes
	l.reverse(2);
	l.print_list();
	l.reverse(2, 1);
	l.print_list();

	//Test sum of two linked lists
	node *a = new node(5, new node(4, new node(7, NULL)));
	node *b = new node(7, new node(2, new node(4, NULL)));
	node *sum = linked_list::sum_list(a, b);
	linked_list::print_list_util(sum);
}
