#ifndef STACK_UTIL
#define STACK_UTIL

#include <stack>

void reverse_stack(std::stack<int> &s) {
	if (!s.size()) return;

	int elem = s.top();
	s.pop();
	reverse_stack(s);
	s.push(elem);
}

void insert_elem_sorted(std::stack<int> &s, int e) {
	if (!s.size() || e > s.top()) {
		s.push(e);
		return;
	}

	int elem = s.top();
	s.pop();
	insert_elem_sorted(s, e);
	s.push(elem);
}

/* We recurse down to the bottom of the stack and then keep inserting elements
   in sorted order - insertion again uses recursion to find the position for
   the new element in the stack. */

void sort_stack(std::stack<int> &s) {
	if (!s.size()) return;

	int elem = s.top();
	s.pop();

	sort_stack(s);

	insert_elem_sorted(s, elem);
}

#endif
