/* Two Sum problem

   Problem Description: Find two elements of an array whose sums adds up to
   a specified target. Assume that there is only one unique pair.

   One way to solve this problem is by:
   - First sorting the array.
   - Start adding elements from the opposite ends of the array and update the
   left and right indices based on the value of the sum with respect to the
   target.
   - If ths sum is larger than the target, decrement the right index and
   increment the left index if it is smaller. Repeat this process until the
   sum matches target or when we exhaust the elements in the array.
   - Complexity O(NlogN).

   More efficient way is to use a hash table. This approach takes a single pass
   through the array.
   - For every element we add the following (target-element, index) key value pair to
   the hash if (target-element) is positive.
   - When a new element is encountered and if it is already part of the hash,
   our pair is found.

 * */

#include <iostream>
#include <map>
#include <tuple>

using std::cout;
using std::endl;

/* Returns the indices whose element sum adds upto target */

std::tuple<int, int> two_sum_hash(int *elems, int len, int target) {
	std::map <int, int> sub_index;
	int i, sub, elem;

	for (i=0; i<len; i++) {
		elem = elems[i];

		if (sub_index[elem]) return std::make_tuple(sub_index[elem], i);

		sub = target - elem;

		if (sub < 0)
			continue;
		else if (sub == 0)
			return std::make_tuple(-1, -1);

		sub_index[sub] = i;
	}

	return std::make_tuple(-1, -1);
}

int main (void) {
	int input_arr[] = {1, 2, 3, 5, 7};
	int target = 12;
	int x, y;
	std::tie(x, y) = two_sum_hash(input_arr,
				      sizeof(input_arr)/sizeof(input_arr[0]),
				      target);
	cout << "two elements " << input_arr[x] << " " << input_arr[y] << endl;
}
