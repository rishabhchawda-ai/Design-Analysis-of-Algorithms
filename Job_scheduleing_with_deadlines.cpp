#include <iostream>
using namespace std;

// Structure to represent a job with its ID, deadline, and profit
typedef struct Job {
    char id;
    int dead, profit;
} task;

int main() {
    cout<< "By RISHABH CHAWDA (24MAI0102)\n";
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Array to store the jobs
    task a[n];

    // Input job details from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline, and profit for job " << i + 1 << ": ";
        cin >> a[i].id >> a[i].dead >> a[i].profit;
    }

    // Sort jobs based on profit in descending order using selection sort
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            // Find the job with the highest profit
            if (a[j].profit > a[max].profit) {
                max = j;
            }
        }
        // Swap the jobs to sort by profit
        task temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }

    // Arrays to keep track of selected jobs and available slots
    bool selected[n] = {false}; // Tracks if a job is selected
    bool slot[n + 1] = {false}; // Tracks if a time slot is occupied

    // Try to schedule each job in its latest available slot
    for (int i = 0; i < n; i++) {
        // Check slots from job's deadline to the earliest slot (1)
        for (int j = a[i].dead; j >= 1; j--) {
            if (slot[j] == false) { // If slot is available
                slot[j] = true;     // Mark the slot as occupied
                selected[i] = true; // Mark the job as selected
                break;
            }
        }
    }

    // Calculate total profit and print selected jobs
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            cout << "Job " << a[i].id << " is selected\n";
            total += a[i].profit;
        }
    }
    cout << "Max profit achieved: " << total;
    return 0;
}
