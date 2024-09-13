#include <iostream>
using namespace std;

#define MAX 10          // Maximum number of vertices
int adj[MAX][MAX];      // Adjacency matrix to represent the graph
int color[MAX];         // Array to store the color of each vertex
int n;                  // Number of vertices
int m;                  // Number of colors to try

// Function to check if it's safe to color vertex `v` with color `c`
bool isSafe(int v, int c) {
    // Check all adjacent vertices of `v`
    for (int i = 0; i < n; i++) {
        // If there's an edge between v and i, and vertex i has the same color `c`, return false
        if (adj[v][i] == 1 && color[i] == c) {
            return false;  // It's not safe to color `v` with color `c`
        }
    }
    return true;  // It's safe to color `v` with color `c`
}

// Recursive function to solve the m-coloring problem
bool solve(int v) {
    // Base case: If all vertices are colored, return true
    if (v == n) {
        return true;  // All vertices are successfully colored
    }

    // Try coloring vertex `v` with each color from 1 to m
    for (int i = 1; i <= m; i++) {
        // Check if it's safe to color vertex `v` with color `i`
        if (isSafe(v, i)) {
            color[v] = i;          // Assign color `i` to vertex `v`
            if (solve(v + 1)) {    // Recur to color the next vertex
                return true;       // If successful, return true
            }
            color[v] = 0;          // Backtrack: reset color of vertex `v`
        }
    }
    return false;  // Return false if no valid coloring found
}

// Function to print the color of each vertex
void print() {
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " is colored with color " << color[i] << endl;
    }
}

int main() {
    cout << "By RISHABH CHAWDA (24MAI0102)\n";
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the minimum number of colours to try: ";
    cin >> m;

    // Initialize color array to zero (no color assigned)
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }

    // Input adjacency matrix
    cout << "Enter the adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];  // Input 1 if there's an edge between i and j, otherwise 0
        }
    }

    // Try to solve the coloring problem starting from the first vertex (0)
    if (!solve(0)) {  // If solve returns false, no valid coloring is possible with `m` colors
        cout << "Unable to color the graph with " << m << " colors." << endl;
    } else {
        print();  // Print the solution if found
    }

    return 0;
}
