/*
  Same as below problem solved using dynamic programming.
  [library/misc/fibonacci_sum.cpp]

  Reccurence relation:
  - Either include the top element in the vector or not.
  fib_sum(sum, n) = fib_sum(sum - fib[n], n) + fib_sum(sum, n-1);
 */

#include <algorithm>
#include <iostream>
#include "dp.h"
#include "misc.h"

using namespace std;

/* return values are not memoized in potential OOB cases */
int fib_sum_dp_r_int(vector<int> &fib, vector<vector<int>> &t, int end, int k) {
	int r1, r2;
	if (!k) return 0;
	if (k < 0 || end < 0) return -1;

	if(t[k][end] != -1) return t[k][end];

	r1 = fib_sum_dp_r_int(fib, t, end, k-fib[end]);
	r2 = fib_sum_dp_r_int(fib, t, end-1, k);

	/* increment the count only for r1 since last element is picked up
	   while taking this branch */
	if (r1 != -1 && r2 != -1) {
		return (t[k][end] = min(r1+1, r2));
	} else if (r1 == -1 || r2 == -1) {
		return (t[k][end] = (r1 != -1 ? r1 + 1 : r2));
	} else {
		return -1;
	}
}

/* Recursive solution */
int fib_sum_dp_r(int k) {
	vector<int> fib;
	vector<vector<int>> tbl(k+1); //for memoization

	generate_fib(fib, k);

	/* remove the first 1 since each element can be considered
	   more than once */
	fib.erase(fib.begin());

	for (int i=0; i<=k; i++) {
		tbl[i].reserve(fib.size());
		for (int j=0; j<fib.size(); j++)
			tbl[i][j] = -1;
	}

	return fib_sum_dp_r_int(fib, tbl, fib.size()-1, k);
}
