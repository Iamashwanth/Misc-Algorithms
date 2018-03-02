#include <iostream>
#include <map>
#include <string>

std::string words[][3] =  {{"one",       "ten",    "eleven"},
			   {"two",    "twenty",    "twelve"},
			   {"three",  "thirty",  "thirteen"},
			   {"four",    "forty",  "fourteen"},
			   {"five",    "fifty",   "fifteen"},
			   {"six",     "sixty",   "sixteen"},
			   {"seven", "seventy", "seventeen"},
			   {"eight",  "eighty",  "eighteen"},
			   {"nine",    "ninty",  "nineteen"}};

std::string values[] = {"", "", "hundred", "thousand"};

void number_to_words(int num) {
	int place = 2;
	int zeroth, idx;
	std::string str = "";

	zeroth = num % 10;
	num = num/10;
	idx = num%10;

	if (idx == 0 && zeroth) str = words[zeroth-1][0];
	else if (idx == 1 && zeroth) str = words[zeroth-1][2];
	else str = (idx ? words[idx-1][1] : "") + " " + (zeroth ? words[zeroth-1][0] : "");

	num = num/10;
	idx = num%10;
	if (idx) str = words[idx-1][0] + " hundred " + str;

	num = num/10;
	idx = num%10;
	if (idx) str = words[idx-1][0] + " thousand " + str;

	std::cout << str << std::endl;
}
