#include <vector>
#include <iostream>

#define AT(tbl, i, j) ((i) < 0  || (j) < 0) ? 0 : (tbl[i][j])

void subset_sum(std::vector<int> &v, int target) {
	std::vector<std::vector<int>> tbl(v.size());

	for (int i=0; i < v.size(); i++) {
		tbl[i].reserve(target);

		for (int j=0; j < target; j++) {
			if (AT(tbl, i-1, j)) tbl[i][j] = tbl[i-1][j];
			else if (v[i] == j+1)
				tbl[i][j] = 1;
			else if (v[i] < j+1)
				tbl[i][j] = AT(tbl, i-1, j-v[i]);

			std::cout << tbl[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int i = v.size() - 1;
	int j = target-1;

	while (i > 0 && j > 0) {
		if (AT(tbl, i-1, j)) i = i-1;
		else {
			std::cout << v[i] << " ";
			j = j-v[i];
			i = i-1;
		}
	}
	std::cout << std::endl;
}
