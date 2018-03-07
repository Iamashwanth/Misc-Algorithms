#include "arrays.h"
#include <algorithm>

int largest_sum_subarray(std::vector<int> const &v) {
	int largest_sum = v[0];
	int cur_sum = v[0];

	for (int i=1; i<v.size(); i++) {
		cur_sum = std::max(cur_sum + v[i], v[i]);
		largest_sum =  std::max(largest_sum, cur_sum);
	}

	return largest_sum;
}
