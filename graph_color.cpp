#include <iostream>
#define MAX 10  // Maximum number of vertices
using namespace std;

int adj[MAX][MAX];  // Adjacency matrix to represent the graph
int color[MAX];     // Array to store the color assigned to each vertex

// Function to assign a color to vertex v
void applycolor(int v, int n) {
    int used[n] = {0};//Array to keep track of used colors for adjacent vertices of v

    // Mark colors used by adjacent vertices
    for (int i = 0; i < n; i++) {
        // If vertex i is adjacent to v and has been colored, mark its color as used
        if (adj[v][i] == 1 && color[i] != -1) {
            used[color[i]] = 1;
        }
    }

    // Assign the smallest available color to vertex v
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {  // Check if color i is not used
            color[v] = i;    // Assign color i to vertex v
            break;
        }
    }
}

int main() {
    int n;  // Number of vertices
    cout<< "By RISHABH CHAWDA (24MAI0102)\n";
    // Input the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Input the adjacency matrix
    cout << "Enter the adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];  // Read each element of the adjacency matrix
        }
    }

    // Initialize all vertices with no color (-1)
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    // Assign the first color (0) to the first vertex
    color[0] = 0;

    // Apply coloring to all vertices
    for (int i = 0; i < n; i++) {
        applycolor(i, n);  // Assign the appropriate color to vertex i
    }

    // Output the color of each vertex
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " is colored with " << color[i] << endl;
    }
    
    return 0;
}
