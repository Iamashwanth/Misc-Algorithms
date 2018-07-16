#include <iostream>
#include "test_framework.h"
#include "arrays.h"

int largest_sum_test(void *data) {
	std::vector<int> v = {-2, -3, 4, -1, -2, 1, 5, -3};
	std::cout << largest_sum_subarray(v) << std::endl;
}

int next_greatest_test(void *data) {
	std::vector<int> v = {13, 7, 6, 12};
	greatest_element(v);
}

int histogram_area_test(void *data) {
	std::vector<int> input = {6, 2, 5, 4, 5, 1, 6};
	std::cout << "Max Area: " << maximum_rectangle_area(input) << std::endl;
	return TEST_SUCCESS;
}

int rotate_min_test(void *data) {
	std::vector<int> input = {5, 6, 1, 2, 3, 4};
	std::cout << "Min elem: " << rotate_min(input) << std::endl;
	return TEST_SUCCESS;
}

int rotate_elem_test(void *data) {
	std::vector<int> input = {5, 6, 1, 2, 3, 4};
	std::cout << "index of 6 is " << find_elem_rotated(input, 6) << std::endl;
	return TEST_SUCCESS;
}

int binary_search_test(void *data) {
	std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
	std::cout << "Index of 4 is " << binary_search(input, 4, 0,\
			input.size()-1) << std::endl;
	return TEST_SUCCESS;
}

int palindrome_chunks_test(void *data) {
	std::string str = "ghiabcdefhelloadamhelloabcdefghi";
	std::cout << "count is " << palindrome_chunks(str) << std::endl;
	return TEST_SUCCESS;
}

int sort3_test(void *data) {
	std::vector<int> v = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	sort3(v);
	for (auto e:v) {
		std::cout << e;
	}
	std::cout << std::endl;
	return TEST_SUCCESS;
}

const TestFamily* array_init() {
    TestFamily *testFamily = new TestFamily("ARRAYS", static_cast<int>(10));

    TEST_DEF(LARGEST_SUM_TEST, largest_sum_test);
    TEST_DEF(NEXT_GREATEST_TEST, next_greatest_test);
    TEST_DEF(HISTOGRAM_AREA_TEST, histogram_area_test);
    TEST_DEF(ROTATE_MIN_TEST, rotate_min_test);
    TEST_DEF(BINARY_SEARCH_TEST, binary_search_test);
    TEST_DEF(ROTATE_ELEM_TEST, rotate_elem_test);
    TEST_DEF(PALINDROME_CHUNKS_TEST, palindrome_chunks_test);
    TEST_DEF(SORT3_TEST, sort3_test);

    return testFamily;
}
