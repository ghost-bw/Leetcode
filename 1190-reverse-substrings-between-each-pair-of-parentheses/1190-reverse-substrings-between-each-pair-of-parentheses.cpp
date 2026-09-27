#include <string>
#include <vector>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int n = s.length();
        vector<int> opened;
        vector<int> pair(n);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                opened.push_back(i);
            } else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string result = "";
        int direction = 1; // 1 = forward, -1 = backward
        
        for (int curr = 0; curr < n; curr += direction) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];      
                direction = -direction;
            } else {
                result += s[curr];
            }
        }
        
        return result;
    }
};
