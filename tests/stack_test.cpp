#include <stack>
#include <iostream>
#include "test_framework.h"
#include "stack_util.h"

int reverse_test(void *data) {
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	reverse_stack(s);

	while (s.size()) {
		std::cout << s.top() << " ";
		s.pop();
	}

	std::cout << std::endl;

	return TEST_SUCCESS;
}

int sort_test(void *data) {
	std::stack<int> s;
	s.push(-3);
	s.push(3);
	s.push(1);
	s.push(9);
	s.push(4);
	s.push(2);

	sort_stack(s);

	while (s.size()) {
		std::cout << s.top() << " ";
		s.pop();
	}

	std::cout << std::endl;

	return TEST_SUCCESS;
}

const TestFamily* stack_init() {
    TestFamily *testFamily = new TestFamily("STACK", static_cast<int>(10));

    TEST_DEF(REVERSE_TEST, reverse_test);
    TEST_DEF(SORT_TEST, sort_test);

    return testFamily;
}
