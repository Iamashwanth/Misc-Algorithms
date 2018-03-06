/* By sssuming the character in the url are limited to alphanumberice, tinurl
 * problem turns into a base converrsion problem */

#include <iostream>
#include <string>
#include <climits>

std::string alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

uint ato10(std::string &s) {
	uint num = 0;
	uint base = alphanum.size();
	uint add;
	std::cout << base << std::endl;

	for(int i = 0; i < s.size(); i++) {

		if (s[i] >= 'a' && s[i] <= 'z')
			add = s[i] - 'a';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			add = s[i] - 'A' + 26;
		else if (s[i] >= '0' && s[i] <= '9')
			add = s[i] - '0' + 52;
		else
			return 0;

		num = base * num + add;
	}

	return num;
}

void b10toa(uint num, std::string &s) {
	while (num) {
		s.insert(0, 1, alphanum[num%62]);
		num /= 62;
	}
}
