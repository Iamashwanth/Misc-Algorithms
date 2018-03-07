#include <iostream>
#include "test_framework.h"
#include "linked_list.h"

int list_test(void *data) {
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

	return TEST_SUCCESS;
}

const TestFamily* list_init() {
    TestFamily *testFamily = new TestFamily("linked list", static_cast<int>(10));

    TEST_DEF(LIST_TEST, list_test);

    return testFamily;
}
