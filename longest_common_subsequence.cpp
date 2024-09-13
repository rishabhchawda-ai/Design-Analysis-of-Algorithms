// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     string s1="translate";
//     string s2="canteen";
//     int m = s1.size();
//     int n = s2.size();
//     int dp[m+1][n+1],seq[m+1][n+1];
//     for(int i=0;i<=m;i++){
//         for(int j=0;j<=n;j++){
//             dp[i][j]=0;
//             seq[i][j]=0;
//         }
//     }
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=n;j++){
//             if(s1.at(i+1)==s2.at(j+1)){
//                 dp[i][j] = 1+dp[i-1][j-1];
//                 seq[i][j] = 3;
//             }
//             else{
//                 int top = dp[i-1][j];
//                 int left = dp[i][j-1];
//                 dp[i][j] = top>left?top:left;
//                 seq[i][j] = top>left?2:1;
//             }
//         }
//     }
//     int last = seq[m][n];
//     string result=" ";
//     int i=m,j=n;
//     while(i!=0 && j!=0){
//         if(last == 3){
//             result += s1[i-1];
//             i--;
//             j--;
//         }
//         else if(last==2){
//                 i--;
//             }
//         else if(last==1){
//                 j--;
//             }
//         else{
//                 last = seq[i][j];
//         }
        
//     }

//     reverse(result.begin(),result.end());

//     cout<<dp[m][n];
//     cout<<result;
//     return 0;
// }

#include <iostream>
#include <algorithm> // For std::reverse
using namespace std;

int main() {
    cout<< "By RISHABH CHAWDA (24MAI0102)\n";
    string s1;  // Input string 1
    string s2;  // Input string 2
    cout << "enter s1: ";
    cin >> s1;
    cout << "enter s2: ";
    cin >> s2;
    int m = s1.size(); // Length of s1
    int n = s2.size(); // Length of s2
    int dp[m + 1][n + 1]; // DP matrix to store LCS lengths

    // Initialize dp matrix with zeros
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0; // Setting the base case: LCS of any string with an empty string is 0
        }
    }

    // Fill the dp matrix based on matching characters
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) { // If characters match
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Diagonal move: add 1 to LCS length
            } else {
                int top = dp[i - 1][j]; // LCS length if we ignore the current character of s1
                int left = dp[i][j - 1]; // LCS length if we ignore the current character of s2
                dp[i][j] = top > left ? top : left; // Take the maximum of the two values
            }
        }
    }

    // Print the dp matrix
    cout << "DP Matrix:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " "; // Displaying the values of the dp matrix
        }
        cout << endl;
    }

    // Backtracking to construct the LCS string from the dp matrix
    string result = ""; // To store the LCS
    int i = m, j = n; // Start from the bottom-right corner of the matrix
    while (i > 0 && j > 0) { // Continue until we reach the top-left corner
        if (s1[i - 1] == s2[j - 1]) { // If characters match
            result += s1[i - 1]; // Add the character to the result
            i--; // Move diagonally up-left
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) { // If the value above is greater
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    reverse(result.begin(), result.end()); // Reverse the result to get the correct LCS order

    // Output the results
    cout << "Length of LCS: " << dp[m][n] << endl; // Print the length of the LCS
    cout << "LCS: " << result << endl; // Print the LCS

    return 0;
}

/*
#include <iostream>
#include <algorithm> // For std::reverse
#include <iomanip>   // For std::setw to align the matrix
using namespace std;

int main() {
    cout << "By RISHABH CHAWDA (24MAI0102)\n";
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];

    // Initialize dp matrix with 0s
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Print the DP Matrix
    cout << "\nDP Matrix:\n   ";
    // Print the top header for s2
    for (int j = 0; j <= n; j++) {
        if (j == 0) cout << "   "; // Space for indexing
        else cout << setw(3) << s2[j - 1];
    }
    cout << "\n";

    // Print the rest of the matrix with s1 labels
    for (int i = 0; i <= m; i++) {
        if (i == 0) cout << "   "; // Space for indexing
        else cout << setw(3) << s1[i - 1]; // Print s1 character as row label
        for (int j = 0; j <= n; j++) {
            cout << setw(3) << dp[i][j];
        }
        cout << endl;
    }

    // Construct the LCS by backtracking through the dp matrix
    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end()); // Reverse the result to get the correct order

    // Output the results
    cout << "\nLength of LCS: " << dp[m][n] << endl;
    cout << "LCS: " << result << endl;

    return 0;
}

Here's the completed DP matrix with arrows indicating the backtracking path:

        s	p	e	e	d
    0	0	0	0	0	0
s	0	1 ↖	1 ←	1 ←	1 ←	1 ←
t	0	1 ↑	1 ↑	1 ←	1 ←	1 ←
e	0	1 ↑	1 ↑	2 ↖	2 ←	2 ←
a	0	1 ↑	1 ↑	2 ↑	2 ↑	2 ←
d	0	1 ↑	1 ↑	2 ↑	2 ↑	3 ↖

Explanation of Backtracking with Arrows
Backtracking Path:

Start at (i=5, j=5) (dp[5][5] = 3):

Characters Matched: s1[4] = 'd' and s2[4] = 'd'
Arrow: ↖ (Diagonal)
Action: Add 'd' to LCS, move to (4, 4).
Move to (i=4, j=4) (dp[4][4] = 2):

Characters Mismatched: s1[3] = 'a' and s2[3] = 'e'
Arrow: ← (Left)
Action: Move to (4, 3).
Move to (i=4, j=3) (dp[4][3] = 2):

Characters Mismatched: s1[3] = 'a' and s2[2] = 'e'
Arrow: ↑ (Up)
Action: Move to (3, 3).
Move to (i=3, j=3) (dp[3][3] = 2):

Characters Matched: s1[2] = 'e' and s2[2] = 'e'
Arrow: ↖ (Diagonal)
Action: Add 'e' to LCS, move to (2, 2).
Move to (i=2, j=2) (dp[2][2] = 1):

Characters Mismatched: s1[1] = 't' and s2[1] = 'p'
Arrow: ← (Left)
Action: Move to (2, 1).
Move to (i=2, j=1) (dp[2][1] = 1):

Characters Mismatched: s1[1] = 't' and s2[0] = 's'
Arrow: ↑ (Up)
Action: Move to (1, 1).
Move to (i=1, j=1) (dp[1][1] = 1):

Characters Matched: s1[0] = 's' and s2[0] = 's'
Arrow: ↖ (Diagonal)
Action: Add 's' to LCS, move to (0, 0).
Final LCS:
After backtracking, the characters added to the LCS in reverse order are 'd', 'e', 's', which gives the LCS "sed".

Summary:
LCS Length: 3
LCS: "sed"
*/