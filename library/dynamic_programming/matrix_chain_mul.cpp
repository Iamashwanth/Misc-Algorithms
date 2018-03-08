#include "dp.h"
#include <vector>
#include <tuple>
#include <climits>
#include <iostream>

int matrix_chain_mul(std::vector<std::tuple<int, int>> &m) {
	std::vector<std::vector<int>> cost(m.size());
	int min_cost, curr_cost;
	int r1, c1, r2, c2, r3, c3;

	for (int i=0; i<m.size(); i++) {
		cost[i].reserve(m.size());
		cost[i][i] = 0;
	}

	for (int l=1; l<m.size(); l++) {
		std::cout << "lenght" << l << std::endl;
		for (int i=0; i<m.size()-l; i++) {
			std::cout << i << "->" <<  i+l << std::endl;
			min_cost = INT_MAX;
			for (int d = i; d < i+l; d++) {
				std::cout << i << "->" << d << " " << d+1 << "->" << i+l << std::endl;
				std::tie(r1, c1) = m[i];
				std::tie(r2, c2) = m[d];
				std::tie(r3, c3) = m[i+l];

				curr_cost = cost[i][d] + cost[d+1][i+l] + r1 * c2 * c3;
				min_cost = std::min(curr_cost, min_cost);
			}
			cost[i][i+l] = min_cost;
		}
	}

	return cost[0][m.size()-1];
}
