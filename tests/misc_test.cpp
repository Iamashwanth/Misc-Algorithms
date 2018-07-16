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
	return TEST_SUCCESS;
}

int b10toa_test(void *data) {
	uint n = 1799015220;
	std::string s;
	b10toa(n, s);
	std::cout << n << " " << s << std::endl;
	return TEST_SUCCESS;
}

int fib_sum_test(void *data) {
	std::cout << fib_sum_greedy(4) << std::endl;
	return TEST_SUCCESS;
}

int postfix_eval_test(void *data) {
	std::string s = "231*+9-";
	std::cout << "eval: \"" << s << "\" = " << postfix_eval(s) << std::endl;
	return TEST_SUCCESS;
}

int infix_to_postfix_test(void *data) {
	std::string s = "a+b*(c^d-e)^(f+g*h)-i";
	std::cout << s << " -> " << infix_to_postfix(s) << std::endl;
	return TEST_SUCCESS;
}

const TestFamily* misc_init() {
    TestFamily *testFamily = new TestFamily("MISC", static_cast<int>(10));

    TEST_DEF(num2word_TEST, num2word_test);
    TEST_DEF(ato10_TEST, ato10_test);
    TEST_DEF(b10toa_TEST, b10toa_test);
    TEST_DEF(FIB_SUM_TEST, fib_sum_test);
    TEST_DEF(POSTFIX_EVAL_TEST, postfix_eval_test);
    TEST_DEF(INFIX_TO_POSTFIX_TEST, infix_to_postfix_test);

    return testFamily;
}
