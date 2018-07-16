#include "arrays.h"
#include <algorithm>

using namespace std;

int rain_trapping(vector<int> &v) {
	vector<int> max_l, max_r;
	int sum = 0;

	max_l.resize(v.size());
	max_r.resize(v.size());

	max_l[0] = v[0];
	max_r[v.size()-1] = v[v.size()-1];

	for (int i=1; i<v.size(); i++)
		max_l[i] = max(v[i], max_l[i-1]);

	for (int i=v.size()-2; i>=0; i--)
		max_r[i] = max(v[i], max_r[i+1]);

	for (int i=0; i<v.size(); i++)
		sum += min(max_l[i], max_r[i]) - v[i];

	return sum;
}
