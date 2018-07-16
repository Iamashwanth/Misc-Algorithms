#ifndef MISC_H
#define MISC_H

#include <string>
#include <vector>

void number_to_words(int num);
unsigned int ato10(std::string &s);
void b10toa(uint num, std::string &s);
int fib_sum_greedy(int k);
void generate_fib(std::vector<int> &v, int k);
int postfix_eval(std::string expr);
std::string infix_to_postfix(std::string expr);

#endif
