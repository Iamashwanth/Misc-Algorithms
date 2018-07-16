#include "misc.h"
#include <stack>
#include <cctype>
#include <iostream>

using namespace std;

int postfix_eval(string expr) {
	int res;
	int fn,sn;
	char c;
	stack<int> s;
	auto it = expr.begin();

	if (expr.empty()) throw;

	while(it != expr.end()) {
		c = *(it++);

		if (isdigit(c))
			s.push(c - '0');
		else {
			sn = s.top();
			s.pop();
			fn = s.top();
			s.pop();

			switch (c) {
				case '+':
					s.push(fn+sn);
					break;
				case '-':
					s.push(fn-sn);
					break;
				case '*':
					s.push(fn*sn);
					break;
				case '/':
					s.push(fn/sn);
					break;
				default:
					throw;
			}
		}
	}

	return s.top();
}

int precedence(char c) {
	if (c == '(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
}

string infix_to_postfix(string expr) {
	stack<char> s;
	string ret;
	char c;
	auto it = expr.begin();

	while (it != expr.end()) {
		c = *(it++);

		if (isalpha(c)) {
			ret.push_back(c);
		} else {
			switch (c) {
				case '(':
					s.push(c);
					break;
				case ')':
					while (s.top() != '(') {
						ret.push_back(s.top());
						s.pop();
					}
					s.pop();
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while (!s.empty() && precedence(s.top()) >= precedence(c)) {
						ret.push_back(s.top());
						s.pop();
					}
					s.push(c);
					break;
			}
		}
	}

	while (!s.empty()) {
		ret.push_back(s.top());
		s.pop();
	}

	return ret;
}
