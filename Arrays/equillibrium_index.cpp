#include <bits/stdc++.h>
using namespace std;

int findEquilibriumIndex(vector<int> &arr) {
    int total_sum = 0, left_sum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < arr.size(); i++) {
        total_sum += arr[i];
    }

    // Iterate through the array to find the equilibrium index
    for (int i = 0; i < arr.size(); i++) {
        // Right sum is total_sum minus left_sum and current element
        int right_sum = total_sum - left_sum - arr[i];
        if (left_sum == right_sum) {
            return i; // Equilibrium index found
        }
        left_sum += arr[i]; // Update left_sum for the next iteration
    }

    return -1; // No equilibrium index found
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};
    cout << findEquilibriumIndex(arr) << endl; // Output: 2
    return 0;
}
