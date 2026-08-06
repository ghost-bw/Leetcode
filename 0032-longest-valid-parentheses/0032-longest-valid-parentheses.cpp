#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int left = 0, right = 0, max_len = 0;
        int n = s.length();

        // 1. Left-to-Right Pass
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        // Reset counters for the next pass
        left = right = 0;

        // 2. Right-to-Left Pass
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = std::max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0; // Reset on invalid state
            }
        }

        return max_len;
    }
};
