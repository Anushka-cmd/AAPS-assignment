
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        char ch = s[end];

        // If character is seen and inside current window
        if (lastSeen.count(ch) && lastSeen[ch] >= start) {
            start = lastSeen[ch] + 1;
        }

        lastSeen[ch] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}

