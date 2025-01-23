#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int findSecondLargest(const vector<int>& nums) {
    if (nums.size() < 2) {
        cout << "Array must have at least two elements." << endl;
        return -1;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        } else if (nums[i] > secondLargest && nums[i] < largest) {
            secondLargest = nums[i];
        }
    }

    if (secondLargest == INT_MIN) {
        cout << "No second largest number (all elements are the same)." << endl;
        return -1;
    }

    return secondLargest;
}

int main() {
    vector<int> arr = {10, 20, 20, 5};

    int result = findSecondLargest(arr);
    if (result != -1) {
        cout << "The second largest number is: " << result << endl;
    }

    return 0;
}
