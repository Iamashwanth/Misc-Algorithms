#include <iostream>
#include "test_framework.h"
#include "misc.h"

int num2word_test(void *data) {
	number_to_words(9110);
	return TEST_SUCCESS;
}

const TestFamily* misc_init() {
    TestFamily *testFamily = new TestFamily("MISC", static_cast<int>(10));

    TEST_DEF(num2word_TEST, num2word_test);

    return testFamily;
}
