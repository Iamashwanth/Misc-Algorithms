#include <vector>
#include "arrays.h"

int rotate_min_util(std::vector<int> &v, int low, int high) {
	int mid;
	
	if (high <= low) return v[low];

	mid = low + (high - low)/2;

	if (mid > low && v[mid] < v[mid-1])
		return v[mid];

	if (mid < high && v[mid] > v[mid+1])
		return v[mid+1];
	
	if (v[mid] < v[high]) rotate_min_util(v, low, mid-1);
	else rotate_min_util(v, mid+1, high);
}

int rotate_min(std::vector<int> &v) {
	return rotate_min_util(v, 0, v.size()-1);
}
