#include <iostream>

int bin_coeff(int n, int k) {
	if (n == 0) return 1;
	if (k == 0 || k == n) return 1;

	return bin_coeff(n-1, k-1) + bin_coeff(n-1, k);
}

int main() {
	std::cout << bin_coeff(5, 2) << std::endl;
}
