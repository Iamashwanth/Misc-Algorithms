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

const TestFamily* array_init() {
    TestFamily *testFamily = new TestFamily("ARRAYS", static_cast<int>(10));

    TEST_DEF(LARGEST_SUM_TEST, largest_sum_test);
    TEST_DEF(NEXT_GREATEST_TEST, next_greatest_test);
    TEST_DEF(HISTOGRAM_AREA_TEST, histogram_area_test);
    TEST_DEF(ROTATE_MIN_TEST, rotate_min_test);

    return testFamily;
}
