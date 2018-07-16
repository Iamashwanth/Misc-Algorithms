#include "arrays.h"

using namespace std;

void swap(vector<int> &A, int i, int j) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void sort3(vector<int> &v) {
	int l = 0, m = 0, h = v.size()-1;

	while (m <= h) {
		if (v[m] == 0) {
			swap(v, m, l);
			l++;
			m++;
			continue;
		} else if (v[m] == 1)
			m++;
		else if (v[m] == 2) {
			swap(v, m, h);
			h--;
		}
	}
}
