#include <iostream>
#include <vector>
using namespace std;
vector<int> buildPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for(int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}
int rangeSum(const vector<int>& prefixSum, int L, int R) {
    if (L == 0) {
        return prefixSum[R];
    }
    return prefixSum[R] - prefixSum[L - 1];
}

int main() {
    // Example array
    vector<int> arr = {2, 4, 5, 7, 1, 3, 8};

    vector<int> prefixSum = buildPrefixSum(arr);

    int L, R;
    cout << "Enter L and R (0-based indices): ";
    cin >> L >> R;

    if (L >= 0 && R < arr.size() && L <= R) {
        int sum = rangeSum(prefixSum, L, R);
        cout << "Sum of elements from index " << L << " to " << R << " is: " << sum << endl;
    } else {
        cout << "Invalid range!" << endl;
    }

    return 0;
}
