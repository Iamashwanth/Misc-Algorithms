#include "arrays.h"

using namespace std;

void swap(vector<int> &A, int i, int j) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void quick_sort(vector<int> &v, int low, int high) {
	int median = v[low];
	int j = low;

	if (low >= high) return;

	for (int i=low+1; i<=high; i++) {
		if (v[i] <= median) {
			j++;
			swap(v, i, j);
		}
	}

	swap(v, j, low);

	quick_sort(v, low, j-1);
	quick_sort(v, j+1, high);
}
