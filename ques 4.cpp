#include <iostream>
#include <vector>
using namespace std;

bool canBeSplitWithEqualPrefixSuffixSum(const vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) totalSum += num;

    int prefixSum = 0;

    for (int i = 0; i < arr.size() - 1; ++i) { 
        prefixSum += arr[i];
        int suffixSum = totalSum - prefixSum;

        if (prefixSum == suffixSum) {
            cout << "Can split after index " << i << " (Prefix sum and Suffix sum = " << prefixSum << ")\n";
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 3};

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    if (!canBeSplitWithEqualPrefixSuffixSum(arr)) {
        cout << "Cannot split array into equal prefix and suffix sums.\n";
    }

    return 0;
}

