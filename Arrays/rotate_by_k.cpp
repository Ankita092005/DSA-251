#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

// Brute Force Approach
void rotateBruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where k >= n

    for (int i = 0; i < k; i++) {
        // Store the last element
        int last = arr[n - 1];

        // Shift all elements to the right
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }

        // Place the last element at the front
        arr[0] = last;
    }
}

// Optimized Approach
void rotateOptimized(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where k >= n

    // Reverse the first n-k elements
    reverse(arr.begin(), arr.begin() + (n - k));

    // Reverse the last k elements
    reverse(arr.begin() + (n - k), arr.end());

    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, k;

    // Input size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input number of rotations
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Uncomment the method you want to use

    // Brute Force Approach
    // rotateBruteForce(arr, k);

    // Optimized Approach
    rotateOptimized(arr, k);

    // Output the rotated array
    cout << "Rotated Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
