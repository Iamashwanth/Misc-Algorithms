#include "arrays.h"

int binary_search(std::vector<int> &v, int elem, int low, int high) {
	int mid = low + (high - low)/2;

	if (high < low) return -1;

	if (elem > v[mid])
		binary_search(v, elem, mid+1, high);
	else if (elem < v[mid])
		binary_search(v, elem, low, mid-1);
	else
		return mid;
}
