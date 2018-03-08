#ifndef DP_H
#define DP_H

#include <vector>

int three_sum_i(std::vector<int> &v, int target);
int three_sum(std::vector<int> &v, int target);
void knapsack(std::vector<int> &w, std::vector<int> &v, int weight);
int matrix_chain_mul(std::vector<std::tuple<int, int>> &m);
void subset_sum(std::vector<int> &v, int target);

#endif
