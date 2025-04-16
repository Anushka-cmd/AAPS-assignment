#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySumOfSizeK(const vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) {
        cout << "Window size K is larger than array size." << endl;
        return -1;
    }

    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k];  // slide the window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSubarraySumOfSizeK(arr, k);

    if (result != -1) {
        cout << "Maximum sum of a subarray of size " << k << " is: " << result << endl;
    }

    return 0;
}
