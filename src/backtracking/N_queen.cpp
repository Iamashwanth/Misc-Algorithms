#include <iostream>
#include "backtracking.h"

class N_Queen: public backtracking {
	public:

	N_Queen(int n): backtracking(n) {}

	bool is_a_solution(int k) const override {
		return k == this->n;
	}

	std::vector<int>* candidate_space(int k) const override {
		std::vector<int> *c = new std::vector<int>;

		for (int j = 0; j < n; j++) {
			bool add = true;
			for (int i = 0; i < k-1; i++) {
				if ((j == v[i]) ||
				    (i - v[i] == k - j - 1) ||
				    (i + v[i] == k + j - 1)) {
					add = false;
					break;
				}
			}
			if (add) c->push_back(j);
		}

		return c;
	}

	void process_solution(int k) override {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == v[i]) std::cout << "1 ";
				else std::cout << "0 ";
			}
			std::cout << std::endl;
		}
		finished = true;
	}
};

int main() {
	N_Queen s(5);
	s.backtrack(0);
	return 0;
}
