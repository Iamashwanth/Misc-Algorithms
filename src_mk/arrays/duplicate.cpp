/* Find duplicate elemts in an array */

#include <iostream>
#include <array>
#include <algorithm>

void duplicates(std::array<int, 10> &a) {
	int count = 0;
	std::sort(a.begin(), a.end());

	for(int i=1; i < a.size(); i++) {
		if (a[i] == a[i-1]) {
			count++;
		} else if (count) {
			std::cout << "Element " << a[i-1] << " repeated "
				<< count + 1 << " times.\n";
			count = 0;
		}
	}
}

void duplicates_inplace(std::array<int , 10> &a) {
	int n = a.size();
	for (int i=0; i < n; i++) {
		a[a[i]  % n] += n;
	}
	for (int i=0; i < n; i++) {
		if (a[i] / n > 1) {
			std::cout << "Element " << i << " repeated "
				<< a[i] / n << " times.\n";
		}
	}
}

int main() {
	std::array<int, 10> a = {6, 5, 2, 1, 5, 2, 3, 4, 1, 2};
	duplicates(a);
	duplicates_inplace(a);
	return 0;
}
