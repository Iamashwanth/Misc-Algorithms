#include <iostream>
#include <string>
#include "test_framework.h"
#include "misc.h"

int num2word_test(void *data) {
	number_to_words(9110);
	return TEST_SUCCESS;
}

int ato10_test(void *data) {
	std::string s {"1Hello"};
	std::cout << s << " " << ato10(s) << std::endl;
}

int b10toa_test(void *data) {
	uint n = 1799015220;
	std::string s;
	b10toa(n, s);
	std::cout << n << " " << s << std::endl;
}

const TestFamily* misc_init() {
    TestFamily *testFamily = new TestFamily("MISC", static_cast<int>(10));

    TEST_DEF(num2word_TEST, num2word_test);
    TEST_DEF(ato10_TEST, ato10_test);
    TEST_DEF(b10toa_TEST, b10toa_test);

    return testFamily;
}
