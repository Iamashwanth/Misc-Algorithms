#include <iostream>

#define MAX 5

/* Boundary conditions

   Top - increment col, change the direction to bottom left
   Left - increment row, change direction to top right
   Bottom - increment col, change direction to top right
   Right - increment row, change direction to bottom left

 */

bool oob(int idx, int inc) {
	if (idx == 0 && inc == -1) return true;
	else if (idx == MAX-1 && inc == 1) return true;
	else return false;
}

void print_spiral(int A[MAX][MAX]) {
	int row_dir = -1, col_dir = 1;
	int row = 0, col = 0;

	while(row != MAX && col != MAX) {
		std::cout << A[row][col] << " ";

		if (oob(col, col_dir) && oob(row, row_dir)) {
			if (row == 0) row++;
			else if (col == 0) col++;
		}
		else if (oob(col, col_dir)) {
			row++;
		} else if (oob(row, row_dir)) {
			col++;
		} else {
			row += row_dir;
			col += col_dir;
			continue;
		}

		std::cout << std::endl;
		row_dir *= -1;
		col_dir *= -1;
	}
}

int main() {
	int A[MAX][MAX] = {{ 1,  2,  3,  4,  5},
			   { 6,  7,  8,  9, 10},
			   {11, 12, 13, 14, 15},
			   {16, 17, 18, 19, 20},
			   {21, 22, 23, 24, 25}};

	print_spiral(A);
	return 0;
}

