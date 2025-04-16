#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countLessEqual(const vector<vector<int>>& matrix, int mid, int& smaller, int& larger) {
    int count = 0;
    int n = matrix.size();
    int row = n - 1, col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            smaller = max(smaller, matrix[row][col]);
            count += row + 1;
            col++;
        } else {
            larger = min(larger, matrix[row][col]);
            row--;
        }
    }

    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int smaller = matrix[0][0], larger = matrix[n - 1][n - 1];

        int count = countLessEqual(matrix, mid, smaller, larger);

        if (count < k) {
            low = larger;
        } else {
            high = smaller;
        }
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    int result = kthSmallest(matrix, k);
    cout << k << "-th smallest element is: " << result << endl;

    return 0;
}
