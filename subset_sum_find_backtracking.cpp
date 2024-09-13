#include<iostream>
#include<stack>
using namespace std;

// Global variables
int n, target;        // Number of nodes (elements) and the target sum
int *a = new int[n];  // Dynamic array to store the elements (note: `n` must be initialized before allocation)
bool found = false;   // Flag to indicate if a solution has been found
stack<int> stck;      // Stack to hold the current combination of elements

// Function to print the current combination stored in the stack
void print(){
    stack<int> temp;
    cout<<"solutions are :";
    // Reverse the stack to print elements in the correct order
    while(!stck.empty()){
        temp.push(stck.top());
        stck.pop();
    }
    while(!temp.empty()){
        cout<<temp.top() << " ";
        stck.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}

// Recursive function to find combinations that sum to the target
void solve(int currSum, int index){
    // If the current sum exceeds the target, return as no valid combination can be found
    if(currSum > target){
        return;
    }
    // If the current sum equals the target, print the combination and set the found flag
    if(currSum == target){
        found = true;
        print();
        return;
    }
    // Iterate through the elements starting from the current index
    for(int i = index; i < n; i++){
        stck.push(a[i]);           // Add the current element to the stack
        solve(currSum + a[i], i + 1); // Recursively try to find combinations with the updated sum and index
        stck.pop();                // Backtrack by removing the current element from the stack
    }
}

int main(){
    cout<< "By RISHABH CHAWDA (24MAI0102)\n";
    cout<<"enter number of nodes: ";
    cin>>n;  // Input the number of elements
    cout<<"enter numbers in array :";
    for(int i = 0; i < n; i++){
        cin >> a[i];  // Input the elements
    }
    cout<<"enter target sum :";
    cin >> target;  // Input the target sum
    solve(0, 0);    // Start solving from the initial sum of 0 and index 0
    if(found == false){
        cout<<"no solution.";  // If no valid combination is found, print this message
    }
    return 0;
}
