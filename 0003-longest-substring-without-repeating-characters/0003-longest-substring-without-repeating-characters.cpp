class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int maxLen = 0;
        unordered_set<char> st;

        for (int high = 0; high < s.length(); high++) {
            
            while (st.find(s[high]) != st.end()) {
                st.erase(s[low]);
                low++;
            }
            
            st.insert(s[high]);
            maxLen = max(maxLen, high - low + 1);
        }

        return maxLen;
    }
};
