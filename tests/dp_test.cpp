#include <iostream>
#include <tuple>
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

int matrix_chain_mul_test(void *data) {
	std::vector<std::tuple<int, int>> v;
	v.push_back(std::make_tuple(10, 20));
	v.push_back(std::make_tuple(20, 30));
	v.push_back(std::make_tuple(30, 40));
	v.push_back(std::make_tuple(40, 30));
	std::cout << matrix_chain_mul(v) << std::endl;
	return TEST_SUCCESS;
}

int subnet_sum_test(void *data) {
	std::vector<int> v = {2, 3, 7, 8, 10};
	subset_sum(v, 11);
	return TEST_SUCCESS;
}

int fib_sum_dp_test(void *data) {
	std::cout << fib_sum_dp_r(17) << std::endl;
	return TEST_SUCCESS;
}

const TestFamily* dp_init() {
    TestFamily *testFamily = new TestFamily("DP", static_cast<int>(10));

    TEST_DEF(THREE_SUM_TEST, three_sum_test);
    TEST_DEF(KNAPSACK_TEST, knapsack_test);
    TEST_DEF(MATRIX_CHAIN_MUL_TEST, matrix_chain_mul_test);
    TEST_DEF(FIB_SUM_DP_TEST, fib_sum_dp_test);
    TEST_DEF(SUBNET_SUM_TEST, subnet_sum_test);

    return testFamily;
}
