vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> M(A, std::vector<int>(A));
    int left, right, bottom, top;
    int dir = 0; // 0 for horizontal
    int j = 0;

    left = top = 0;
    right = bottom = A-1;

    for (long long i = 1; i <= A*A; i++) {
        switch(dir) {
            case 0:
                M[top][j] = i;
                if (++j > right) {
                    top++;
                    j = top;
                    dir++;
                }
                break;
            case 1:
                M[j][right] = i;
                if (++j > bottom) {
                    right--;
                    j = right;
                    dir++;
                }
                break;
            case 2:
                M[bottom][j] = i;
                if (--j < left) {
                    bottom--;
                    j = bottom;
                    dir++;
                }
                break;
            case 3:
                M[j][left] = i;
                if (--j < top) {
                    left++;
                    j = left;
                    dir = 0;
                }
                break;
        }
    }

    return M;
}

