#include <iostream>
using namespace std;

#define MAX 10

// Function to initialize a matrix of size n x n
int** initialize(int n) {
    int** mat = new int*[n];  // Create an array of pointers
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];  // Allocate memory for each row
    }
    return mat;  // Return the initialized matrix
}

// Function to add two matrices of size n x n
int** add(int** m1, int** m2, int n) {
    int** res = initialize(n);  // Initialize result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = m1[i][j] + m2[i][j];  // Add corresponding elements
        }
    }
    return res;  // Return the sum matrix
}

// Function to subtract two matrices of size n x n
int** sub(int** m1, int** m2, int n) {
    int** res = initialize(n);  // Initialize result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = m1[i][j] - m2[i][j];  // Subtract corresponding elements
        }
    }
    return res;  // Return the difference matrix
}

// Strassen's matrix multiplication function
int** strassen(int** A, int** B, int n) {
    // Base case for 1x1 matrix
    if (n == 1) {
        int** C = initialize(1);
        C[0][0] = A[0][0] * B[0][0];  // Simple multiplication for 1x1 matrix
        return C;
    }

    int k = n / 2;  // Divide matrix size by 2
    int** a = initialize(k);  // Submatrices of A
    int** b = initialize(k);
    int** c = initialize(k);
    int** d = initialize(k);
    int** e = initialize(k);  // Submatrices of B
    int** f = initialize(k);
    int** g = initialize(k);
    int** h = initialize(k);

    // Split the matrices into submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = A[i][j];            // Top-left
            b[i][j] = A[i][k + j];        // Top-right
            c[i][j] = A[k + i][j];        // Bottom-left
            d[i][j] = A[k + i][k + j];    // Bottom-right
            e[i][j] = B[i][j];            // Top-left
            f[i][j] = B[i][k + j];        // Top-right
            g[i][j] = B[k + i][j];        // Bottom-left
            h[i][j] = B[k + i][k + j];    // Bottom-right
        }
    }

    // Strassen's 7 recursive multiplications
    int** P1 = strassen(a, sub(f, h, k), k);              // P1 = a * (f - h)
    int** P2 = strassen(add(a, b, k), h, k);              // P2 = (a + b) * h
    int** P3 = strassen(add(c, d, k), e, k);              // P3 = (c + d) * e
    int** P4 = strassen(d, sub(g, e, k), k);              // P4 = d * (g - e)
    int** P5 = strassen(add(a, d, k), add(e, h, k), k);   // P5 = (a + d) * (e + h)
    int** P6 = strassen(sub(b, d, k), add(g, h, k), k);   // P6 = (b - d) * (g + h)
    int** P7 = strassen(sub(a, c, k), add(e, f, k), k);   // P7 = (a - c) * (e + f)

    // Combine submatrices into result matrix C
    int** C = initialize(n);
    int** C11 = add(sub(add(P5, P4, k), P2, k), P6, k);   // C11 = P5 + P4 - P2 + P6
    int** C12 = add(P1, P2, k);                           // C12 = P1 + P2
    int** C21 = add(P3, P4, k);                           // C21 = P3 + P4
    int** C22 = sub(sub(add(P1, P5, k), P3, k), P7, k);   // C22 = P1 + P5 - P3 - P7

    // Combine C11, C12, C21, C22 into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];               // Top-left
            C[i][k + j] = C12[i][j];           // Top-right
            C[k + i][j] = C21[i][j];           // Bottom-left
            C[k + i][k + j] = C22[i][j];       // Bottom-right
        }
    }
    return C;  // Return the resulting matrix
}

int main() {
    cout << "By RISHABH CHAWDA (24MAI0102)\n";
    int n;
    cout << "Enter the size of the matrix (must be a power of 2): ";
    cin >> n;

    // Initialize matrices A and B
    int** A = initialize(n);
    int** B = initialize(n);

    // Take user input for matrix A
    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];  // Input each element of A
        }
    }

    // Take user input for matrix B
    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];  // Input each element of B
        }
    }

    // Perform Strassen multiplication
    int** C = strassen(A, B, n);

    // Print the result matrix
    cout << "Result matrix C:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";  // Output each element of result C
        }
        cout << endl;
    }

    return 0;
}
