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

#endif
