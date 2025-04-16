#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
    
        currSum = max(nums[i], currSum + nums[i]);
        maxSoFar = max(maxSoFar, currSum);
    }

    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
