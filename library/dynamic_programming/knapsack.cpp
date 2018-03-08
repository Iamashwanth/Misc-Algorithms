#include "dp.h"
#include <algorithm>
#include <iostream>

#define AT(tbl, x, y) ((x) < 0 ? 0 : tbl[x][y])

void knapsack(std::vector<int> &w, std::vector<int> &v, int weight) {
	std::vector<std::vector<int>> tbl(w.size());

	for (int i=0; i<w.size(); i++) {
		tbl[i].reserve(weight+1);

		for (int j=0; j<=weight; j++) {
			if (w[i] > j) {
				tbl[i][j] = AT(tbl, i-1, j);
			} else {
				tbl[i][j] = std::max(v[i] + AT(tbl, i-1, j-w[i]), AT(tbl, i-1, j));
			}
			std::cout << tbl[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int i = w.size() - 1;

	while (weight) {
		if (tbl[i][weight] == AT(tbl, i-1, weight)) {
			i = i-1;
		} else {
			std::cout << "w:" << w[i] << " v:" << v[i] << std::endl;
			weight = weight - w[i];
			i = i-1;
		}
	}
}
