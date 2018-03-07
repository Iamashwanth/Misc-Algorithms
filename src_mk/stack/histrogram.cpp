/* Maximum rectangle area in a histogram

   This program finds a rectangle that spans the maximum area inside a histogram.
   Time complexity - O(n)

   Basic idea behind this algorithm is as below:
   - For every element(i) in the histogram, we try to find the left most(i)
   and the right most index(k) where the height is lesser than current element.
   Now we can compute the maximum area spanned by rectangle with the height of
   current element by H[j] * (k-i+1).
   - To make the solution efficient we use a stack and start popping off
   indices when we encounter the right edge of the rectangle.

 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::cout;
using std::endl;

class histogram {
	public:
	histogram(std::vector<int> &input) {
		hist = input;
	}

	int maximum_rectangle_area() {
		std::stack<int> stack;
		int i, left, right, top;
		int maxarea = -1;

		for (i=0; i<hist.size(); i++) {
			while (!stack.empty() && hist[stack.top()] >= hist[i]) {
				int height = hist[stack.top()];
				stack.pop();
				right = i-1;
				left = stack.empty() ? 0 : stack.top()+1;
				maxarea = std::max(maxarea, height*(right-left+1));
			}
			stack.push(i);
		}
		while (!stack.empty()) {
			int height = hist[stack.top()];
			stack.pop();
			right = i-1;
			left = stack.empty() ? 0 : stack.top()+1;
			maxarea = std::max(maxarea, height*(right-left+1));
		}
		return maxarea;
	}

	private:
	std::vector<int> hist;
};

int main() {
	std::vector<int> input = {6, 2, 5, 4, 5, 1, 6};
	//std::vector<int> input = {1, 2, 2, 1, 1, 1, 1, 1};
	histogram hist(input);
	cout << "Max Area: " << hist.maximum_rectangle_area() << endl;
	return 0;
}
