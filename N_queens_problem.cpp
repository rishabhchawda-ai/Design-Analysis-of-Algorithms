#include <iostream>
using namespace std;

// Global variables
int n, chess[20][20]; // `n` is the size of the chessboard, `chess` is a 2D array to represent the board
bool found = false;   // Flag to indicate if a solution has been found

// Function to check if it's safe to place a queen at (row, col)
bool isSafe(int row, int col) {
    // Check the current row on the left side
    for (int j = col; j >= 0; j--) {
        if (chess[row][j] == 1) {
            return false; // Another queen is in the same row
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1) {
            return false; // Another queen is on the upper diagonal
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (chess[i][j] == 1) {
            return false; // Another queen is on the lower diagonal
        }
    }

    // If no conflicts, it's safe to place a queen here
    return true;
}

// Function to print the current configuration of the chessboard
void print() {
    cout << "options\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chess[i][j] == 1) {
                cout << "[Q]"; // Print 'Q' for a queen
            } else {
                cout << "[ ]"; // Print empty space
            }
        }
        cout << endl;
    }
}

// Recursive function to solve the N-Queens problem
void solve(int col) {
    // Base case: if all columns are filled, print the solution
    if (col == n) {
        found = true;  // Mark that at least one solution is found
        print();       // Print the board configuration
        return;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {  // Check if it's safe to place a queen at (i, col)
            chess[i][col] = 1; // Place the queen
            solve(col + 1);    // Recur to place the next queen in the next column
            chess[i][col] = 0; // Backtrack: remove the queen from (i, col)
        }
    }
}

int main() {
    cout << "By RISHABH CHAWDA (24MAI0102)\n";
    cout << "enter no of queens to arrange :"; // Input the size of the chessboard
    cin >> n;
    solve(0);              // Start solving from the first column
    if (!found) {          // If no solution was found, print the message
        cout << "not able to place queen";
    }
    return 0;
}
