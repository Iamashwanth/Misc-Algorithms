#ifndef ARRAYS_H
#define ARRAYS_H

#include <vector>
#include <string>

int largest_sum_subarray(std::vector<int> const &v);
void greatest_element(std::vector<int> &v);
int maximum_rectangle_area(std::vector<int> &hist);
int rotate_min(std::vector<int> &v);
int binary_search(std::vector<int> &v, int elem, int low, int high);
int find_elem_rotated(std::vector<int> &v, int elem);
int palindrome_chunks(const std::string &str);

#endif
