#include <iostream>
#include <vector>

int fib(int n) {
	int f1 = 0, f2 = 1, s;

	if (n == 0) return f1;

	for (int i = 2; i < n; i++) {
		s = f1 + f2;
		f1 = f2;
		f2 = s;
	}

	return f1 + f2;
}

int main() {
	std::cout << "Fibonocci of 45 is " << fib(45) << std::endl;
	return 0;
}
