#include <iostream>
#include <algorithm>

int access_memo(std::vector<std::vector<int>> &C, int r, int c, int m, int n) {
	if (r < 0 || r >= m) return 0;
	if (c < 0 || c >= n) return 0;

	return C[r][c];
}

void longest_common_subsequence(char* A, char *B, int m, int n) {
	std::vector<std::vector<int>> C;
	C.reserve(m);

	for(int i=0; i<m; i++) {

		C[i].reserve(n);

		for(int j=0; j<n; j++) {

			if (A[i] == B[j]) {
				std::cout << A[i] << " ";
				C[i][j] = access_memo(C, i-1, j-1, m, n) + 1;
			} else {
				C[i][j] = std::max(access_memo(C, i-1, j, m, n),
						   access_memo(C, i, j-1, m, n));
			}

		}
	}

	std::cout << std::endl;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cout << C[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	char A[] = {'A', 'B', 'C', 'D', 'G', 'H'};
	char B[] = {'A', 'E', 'D', 'F', 'H', 'R'};
	longest_common_subsequence(A, B, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]));
	return 0;
}
