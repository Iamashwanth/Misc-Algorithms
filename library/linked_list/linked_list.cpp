#include <iostream>
#include "linked_list.h"

void linked_list::push_front(int e) {
	node *n = new node(e);

	if (head)
		n->next = head;
	else
		tail = n;
	head = n;
}

void linked_list::push_back(int e) {
	if (!head) return push_front(e);

	tail->next = new node(e);
	tail = tail->next;
}

void linked_list::pop_front() {
	node *tmp = head;
	if (!head) return;

	head = head->next;
	delete(tmp);

	if (!head) tail = NULL;
}

void linked_list::pop_back() {
	node *tmp = head;
	if (!head) return;

	if (head == tail) return pop_front();

	while (tmp->next != tail) tmp = tmp->next;

	tmp->next = NULL;
	delete(tail);
	tail = tmp;
}

void linked_list::reverse() {
	if (head == tail) return;

	tail = head;
	head = reverse(head, NULL, NULL);
}

void linked_list::reverse(int n, int alt) {
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

node* linked_list::reverse(node *n, node *p, node *end) {
	node *c;
	if (!n || n == end) return p;

	c = n->next;
	n->next = p;
	reverse(c, n, end);
}

void linked_list::reverse_i() {
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

void linked_list::reverse_i(int a, int b) {
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

void linked_list::print_list() {
	print_list_util(head);
}

void linked_list::print_list_util(node *n) {

	while (n) {
		std::cout << n->elem << " ";
		n = n->next;
	}

	std::cout << std::endl;
}

node* linked_list::sum_list(node *a, node *b) {
	node *sum = sum_list_internal(a, b);

	if (sum && sum->elem >= 10) {
		sum = new node(sum->elem/10, sum);
		sum->next->elem = sum->next->elem%10;
	}

	return sum;
}

node* linked_list::sum_list_internal(node *a, node *b) {
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
