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
		c->push_back(1);
		c->push_back(0);
		return c;
	}

	void process_solution(int k) override {
		std::cout << "{";
		for (int i = 0; i < k; i++)
			if (v[i]) std::cout << i+1;
		std::cout << "}" << std::endl;
	}
};

int main() {
	subsets s(3);
	s.backtrack(0);
	return 0;
}
