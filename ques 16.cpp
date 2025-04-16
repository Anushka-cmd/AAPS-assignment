#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    int actualCount = 0;
    for (int num : nums) {
        if (num == candidate) actualCount++;
    }

    if (actualCount > nums.size() / 2)
        return candidate;
    else
        throw invalid_argument("No majority element found");
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 2, 2, 2};

    try {
        int result = majorityElement(nums);
        cout << "Majority element is: " << result << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
