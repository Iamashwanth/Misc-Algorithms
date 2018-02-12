#include <vector>

class backtracking {
	public:

	backtracking(): n {0} {}
	backtracking(int n): n {n} {}

	virtual bool is_a_solution(int k) const = 0;
	virtual std::vector<int>* candidate_space(int k) const = 0;
	virtual void process_solution(int k) const = 0;

	void backtrack(int k) {
		std::vector<int> *c;
		if(is_a_solution(k))
			process_solution(k);
		else {
			k++;
			c = candidate_space(k);
			for (auto it=c->begin(); it!=c->end(); it++) {
				v.push_back(*it);
				backtrack(k);
				v.pop_back();
			}
		}
	}

	protected:
	std::vector<int> v;
	int n;
};
