/* Problem: Find the next greatest element to the right for each element of an
 * array. Basic idea here is to use a stack to push the elements and pop from it
 * if the current element is greater. */

#include <stack>
#include <vector>
#include <iostream>
#include "arrays.h"

void greatest_element(std::vector<int> &v) {
	std::stack<int> s;

	for(int i=0; i<v.size(); i++) {
		while (s.size()) {
			if (v[i] > s.top()) {
				std::cout << "NGE of " << s.top() << " is " \
						<< v[i] << std::endl;
				s.pop();
			} else {
				break;
			}
		}

		s.push(v[i]);
	}

	while (s.size()) {
		std::cout << "no NGE for " << s.top() << std::endl;
		s.pop();
	}
}
