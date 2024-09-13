#include <iostream>
using namespace std;

// Function to print the optimal parenthesization
void printOptimalParens(int **s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    cout<< "By RISHABH CHAWDA (24MAI0102)\n";
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    // Dynamic allocation of array to store dimensions
    int *r = new int[n + 1];
    //cout << "Enter the number of matrices: " << n + 1 << ":\n";
    cout<< "Enter array of order of Matrix:";
    for (int i = 0; i <= n; i++) {
        //cout << "Enter dimension " << i + 1 << ": ";
        
        cin >> r[i];
    }

    // Dynamic allocation of dp and split point arrays
    int **dp = new int*[n];
    int **s = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n]();
        s[i] = new int[n]();
    }

    // Initialize the diagonal of the dp matrix to zero
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the dp matrix for the chain multiplication cost
    for (int diag = 2; diag <= n; diag++) {
        for (int i = 0; i <= n - diag; i++) {
            int j = i + diag - 1;
            dp[i][j] = 999999; // Use a large value as initial

            // Finding the minimum cost and split point
            for (int k = i; k < j; k++) {
                // Correct bounds check to avoid accessing r[j+1] if j = n-1
                int q = dp[i][k] + dp[k + 1][j] + r[i] * r[k + 1] * r[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    // Print the minimum multiplication cost
    cout << "The minimum cost is " << dp[0][n - 1] << endl;

    // Print the dp matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                cout << "  ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Print the optimal multiplication order
    cout << "The optimal way to multiply the matrices is: ";
    printOptimalParens(s, 0, n - 1);
    cout << endl;
    return 0;
}
