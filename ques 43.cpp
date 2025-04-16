#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (auto& [num, freq] : freqMap) {
        minHeap.push({freq, num});
        if (minHeap.size() > k) {
            minHeap.pop(); 
        }
    }


    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> topK = topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
