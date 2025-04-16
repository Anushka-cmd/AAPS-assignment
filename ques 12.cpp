#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;
    
    // Step 1: Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    // Step 2: Find the successor
    for (int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot