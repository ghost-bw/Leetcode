class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        string combined = s + "#" + rev_s;
        int n = combined.length();

        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        int longest_palindrome_len = lps[n - 1];

        string non_palindrome_suffix = s.substr(longest_palindrome_len);
        reverse(non_palindrome_suffix.begin(), non_palindrome_suffix.end());
        
        return non_palindrome_suffix + s;
    }
};
