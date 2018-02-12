#include <iostream>
#include "backtracking.h"

class subsets: public backtracking {
	public:

	subsets(int n): backtracking(n) {}

	bool is_a_solution(int k) const override {
		return k == this->n;
	}

	std::vector<int>* candidate_space(int k) const override {
		std::vector<int> *c = new std::vector<int>;
		c->push_back(0);
		c->push_back(1);
		return c;
	}

	void process_solution(int k) const override {
		for (int i = 0; i < k; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
};

int main() {
	subsets s(5);
	s.backtrack(0);
	return 0;
}
