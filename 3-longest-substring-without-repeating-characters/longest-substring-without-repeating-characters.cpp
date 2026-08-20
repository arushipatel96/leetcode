#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Map character to its last seen index + 1 (1-based index)
        // Using vector of size 256 for all possible ASCII characters
        std::vector<int> charMap(256, 0); 
        
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < s.length(); ++right) {
            // If the character was seen before inside the current window, move the left pointer
            if (charMap[s[right]] > left) {
                left = charMap[s[right]];
            }

            // Update the last seen position (1-based indexing to avoid conflict with default 0)
            charMap[s[right]] = right + 1;

            // Calculate current window length and update max
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};