#include <iostream>
#include "test_framework.h"
#include "dp.h"

int three_sum_test(void *data) {
	std::vector<int> v = {13, 7, 6};
	std::cout << three_sum_i(v, 13) << std::endl;
	std::cout << three_sum(v, 13) << std::endl;
}

int knapsack_test(void *data) {
	std::vector<int> w = {1, 3, 4, 5};
	std::vector<int> v = {1, 4, 5, 7};
	knapsack(w, v, 7);
	return TEST_SUCCESS;
}

const TestFamily* dp_init() {
    TestFamily *testFamily = new TestFamily("DP", static_cast<int>(10));

    TEST_DEF(THREE_SUM_TEST, three_sum_test);
    TEST_DEF(KNAPSACK_TEST, knapsack_test);

    return testFamily;
}
