#include "arrays.h"
#include <iostream>

int palindrome_chunks(const std::string &s){
	bool found = false;
	int end = s.size();
	int cnt = 0;

	if (s.empty()) return 0;
	if (s.size() == 1) return 1;

	while(!found && end > s.size()/2) {
		if (s[0] == s[end] && !s.compare(end, cnt, s, 0, cnt)) {
			found = true;
			continue;
		}
		end--;
		cnt++;
	}

	if (found) return palindrome_chunks(s.substr(cnt, s.size()-2*cnt)) + 2;

	return 1;
}
