#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex; 

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numIndex.find(complement) != numIndex.end()) {
            return {numIndex[complement], i}; 
        }

        numIndex[nums[i]] = i;
    }

    throw invalid_argument("No two sum solution found");
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    try {
        pair<int, int> result = twoSum(nums, target);
        cout << "Indices: " << result.first << " and " << result.second << endl;
        cout << "Numbers: " << nums[result.first] << " + " << nums[result.second] << " = " << target << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
