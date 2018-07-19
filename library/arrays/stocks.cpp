#include "arrays.h"
#include <climits>
#include <iostream>

using namespace std;

int maximize_profit_single(vector<int> &v) {
	int min_price = INT_MAX;
	int max_profit = INT_MIN;

	for (auto p:v) {
		min_price = min(p, min_price);
		max_profit = max(p - min_price, max_profit);
	}

	return max_profit;
}

int maximize_profit_multiple(vector<int> &v) {
	vector<int> minv, maxv;
	int count = 0, i = 0;
	int profit = 0;
	std::cout << "entry" << std::endl;

	while (i<v.size()-1) {
		while (i < v.size()-1 && v[i+1] <= v[i]) i++;

		if (i == v.size()-1) break;

		minv.push_back(i++);

		while (i < v.size() && v[i] >= v[i-1]) i++;

		maxv.push_back(i-1);

		count++;
	}

	for (int i=0; i<count; i++) {
		std::cout << i << " : " << minv[i] << " " << maxv[i] << std::endl;
		profit += v[maxv[i]] - v[minv[i]];
	}

	return profit;
}
