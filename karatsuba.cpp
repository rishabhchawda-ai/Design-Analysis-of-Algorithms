#include <iostream>
#include <bits/stdc++.h> // Includes all standard libraries
#include <string>
using namespace std;

// Recursive function implementing the Karatsuba algorithm for multiplication
int karat(int a, int b) {
    // Convert integers to strings to handle the splitting
    string as = to_string(a);
    string bs = to_string(b);
    int alen = as.length(); // Length of the first number
    int blen = bs.length(); // Length of the second number
    
    // Base case: if both numbers have only one digit, multiply directly
    if (alen == 1 && blen == 1) {
        return a * b;
    }

    // Find the maximum length of the two numbers
    int n = alen > blen ? alen : blen;
    
    // Pad the shorter number with leading zeros to match the lengths
    while (alen != n) {
        as = "0" + as;
        alen = as.length();
    }
    while (blen != n) {
        bs = "0" + bs;
        blen = bs.length();
    }

    // Split the strings into left and right halves
    int al = stoi(as.substr(0, n / 2));             // Left half of the first number
    int ar = stoi(as.substr(n / 2, n - (n / 2)));   // Right half of the first number
    int bl = stoi(bs.substr(0, n / 2));             // Left half of the second number
    int br = stoi(bs.substr(n / 2, n - (n / 2)));   // Right half of the second number

    // Recursively calculate three main products
    int x1 = karat(al, bl);                  // Multiplication of left halves
    int x2 = karat(al + ar, bl + br);        // Multiplication of sums of both halves
    int x3 = karat(ar, br);                  // Multiplication of right halves

    // Calculate m as half the length (n/2)
    int m = ceil(n / 2);

    // Combine the three products into the final product using the Karatsuba formula
    int prod = x1 * pow(10, 2 * m) + (x2 - x1 - x3) * pow(10, m) + x3;

    return prod;
}

int main() {
    cout << "By RISHABH CHAWDA (24MAI0102)\n";
    int a, b;

    // Input the two numbers to multiply
    cout << "Enter first number to multiply: ";
    cin >> a;
    cout << "Enter second number to multiply: ";
    cin >> b;

    // Display the product using the Karatsuba algorithm
    cout << "Product of " << a << " and " << b << " is " << karat(a, b);
    return 0;
}
