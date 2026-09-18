class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal) {
            unordered_set<char> unique_chars(s.begin(), s.end());
            return unique_chars.size() < s.length();
        }
        vector<int> diff_indices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                diff_indices.push_back(i);
            }
        }
        
        return diff_indices.size() == 2 && 
               s[diff_indices[0]] == goal[diff_indices[1]] && 
               s[diff_indices[1]] == goal[diff_indices[0]];
    }
};
