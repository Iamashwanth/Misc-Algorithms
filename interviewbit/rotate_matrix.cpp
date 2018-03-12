void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int temp;

    for (int i=0; i<n; i++) {
        for (int j=i; j < n; j++) {
            if (i == j) continue;

            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0, k=n-1; j < k; j++, k--) {
            temp = A[i][k];
            A[i][k] = A[i][j];
            A[i][j] = temp;
        }
    }
}

