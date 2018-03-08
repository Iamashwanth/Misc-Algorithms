#include "dp.h"
#include <iostream>

int three_sum_i(std::vector<int> &v, int target) {
	std::vector<int> table;
	int i = 1;

	table.reserve(target+1);
	table[0] = 1;

	do {
		table[i] = i-v[0] >= 0 ? table[i-v[0]] : 0;
		table[i] += i-v[1] >= 0 ? table[i-v[1]] : 0;
		table[i] += i-v[2] >= 0 ? table[i-v[2]] : 0;
	} while (i++ != target);

	return table[target];
}

int three_sum_r(std::vector<int> &v, int target, std::vector<int> &m) {
	if (target < 0) return 0;
	if (target == 0) return 1;

	if (!m[target]) {
		 m[target] = three_sum_r(v, target - v[0], m) +
			     three_sum_r(v, target - v[1], m) +
			     three_sum_r(v, target - v[2], m);
	}

	return m[target];
}

int three_sum(std::vector<int> &v, int target) {
	std::vector<int> table(target+1, 0);

	return three_sum_r(v, target, table);
}
