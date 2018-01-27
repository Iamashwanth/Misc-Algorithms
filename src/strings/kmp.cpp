#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::endl;

class kmp {
	public:

	kmp() {
		len = 0;
	}

	kmp(const std::string& pattern) {
		len = 0;
		set_match_pattern(pattern);
	}

	void print_pattern_table() {
		for (int i=0; i<len; i++)
			cout << "--";
		cout << endl;
		for (int i=0; i<len; i++)
			cout << pattern[i] << " ";
		cout << endl;
		for (int i=0; i<len; i++)
			cout << table[i] << " ";
		cout << endl;
	}

	bool search_str(const std::string &str) {
		int i=0, j=0;

		while (i<str.length()) {
			if (j == len) return true;

			if (str[i] == pattern[j]) {
				j++;
				i++;
			} else if (j == 0) {
				i++;
			} else {
				j = table[j-1];
			}
		}

		return false;
	}

	private:

	std::string pattern;
	int *table;
	int len;

	void build_pattern_table() {
		int i=0, j=0;

		while (i < len) {
			if (pattern[i] == pattern[j]) {
				table[i] = ++j;
				i++;
			} else if (j == 0) {
				i++;
			} else {
				j = table[j-1];
			}
		}
	}

	void set_match_pattern(const std::string& pattern) {
		this->pattern = pattern;
		len = pattern.length();
		table = (int *) std::malloc(sizeof(int) * len);
		std::memset(table, 0, sizeof(int) * len);
		build_pattern_table();
	}
};
