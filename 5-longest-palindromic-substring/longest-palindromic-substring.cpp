#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;

        // Helper lambda to expand around a given center [left, right]
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length of the palindrome found
            int currentLen = right - left - 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left + 1; // Update starting index
            }
        };

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindromes (center at character i)
            expandAroundCenter(i, i);
            // Even length palindromes (center between i and i+1)
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
