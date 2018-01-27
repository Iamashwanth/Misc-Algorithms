/* * * * * * * * * * * * * * * * *
 * Knuth-Morris-Pratt algorithm  *
 * * * * * * * * * * * * * * * * */

/*

   This algorithm efficiently matches a given pattern in any input string with
   a time complexity of O(m+n), where m and n are the lenghts of pattern and the
   input string respectively.

   It achieves this by building a pattern table(like the one below) where each
   cell stores the lenght of longest suffix that is also the prefix in the
   substring upto that index.

   --------------------------
    a b c d a b c e a b c d e
    0 0 0 0 1 2 3 0 1 2 3 4 0
   --------------------------

   During the search whenever there is a mismatch we need not begin our search
   from the beginning of the pattern, but instead we can make use of the pattern
   table above and move to the next smaller suffix(match) until we hit index 0.

 */

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
		table = NULL;
	}

	~kmp() {
		delete table;
	}

	kmp(const std::string& pattern) {
		set_match_pattern(pattern);
	}

	void print_pattern_table() {
		for (int i=0; i<len; i++)
			cout << "--";
		cout << endl << " ";
		for (int i=0; i<len; i++)
			cout << pattern[i] << " ";
		cout << endl << " ";
		for (int i=0; i<len; i++)
			cout << table[i] << " ";
		cout << endl;
		for (int i=0; i<len; i++)
			cout << "--";
		cout << endl;
		cout << endl;
	}

	int search_str(const std::string &str) {
		int i=0, j=0;

		while (i<str.length()) {
			if (j == len) return i-len;

			if (str[i] == pattern[j]) {
				i++, j++;
			} else if (j == 0) {
				i++;
			} else {
				j = table[j-1];
			}
		}

		return -1;
	}

	private:

	std::string pattern;
	int *table;
	int len;

	void build_pattern_table() {
		int i=1, j=0;

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
