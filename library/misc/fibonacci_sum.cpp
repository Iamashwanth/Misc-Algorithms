/*
  Find the minimum number of fibonacci numbers that add up to k.
  Each number can be picked any number of times.
  [https://www.geeksforgeeks.org/minimum-fibonacci-terms-sum-equal-k]
*/

#include "misc.h"
#include <vector>

using namespace std;


/* generates fibonacci numbers upto k */
void generate_fib(vector<int> &v, int k) {
	int i = 2;

	if (k < i) return;

	v.push_back(1);
	v.push_back(1);

	do {
		v.push_back(v[i-1] + v[i-2]);
		i++;
	} while (v.back() < k);

	v.pop_back();
	return;
}

int fib_sum_greedy(int k) {
	vector<int> v;
	int count = 0;

	generate_fib(v, k);

	while (k) {
		count += k / v.back();
		k = k % v.back();

		v.pop_back();
	}

	return count;
}
