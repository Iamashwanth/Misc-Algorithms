#include <iostream>
#include <algorithm>

int longest_increasing_subsequence(int *a, int n) {
	int i, j;
	int *c = new int[n];

	for(i=0; i<n; i++) {
		c[i] = 1;
	}

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++) {
			if (a[j] < a[i])
				c[i] = std::max(c[i], c[j]+1);
		}
	}

	for(i=1, j=c[1]; i<n; i++) {
		j = std::max(j, c[i]);
	}

	for(i=0; i<n; i++) {
		std::cout << c[i] << " ";
	}

	std::cout << std::endl;

	delete[] c;
	return j;
}

int main() {
	int a[] = {3, 4, -1, 0, 6, 2, 3};
	int b[] = {2, 5, 1, 8, 3};
	int ret;
	ret = longest_increasing_subsequence(a, sizeof(a)/sizeof(a[0]));
	std::cout << "Longest increasing subsequence of a is " << ret << std::endl;
	ret = longest_increasing_subsequence(b, sizeof(b)/sizeof(b[0]));
	std::cout << "Longest increasing subsequence of b is " << ret << std::endl;
}
