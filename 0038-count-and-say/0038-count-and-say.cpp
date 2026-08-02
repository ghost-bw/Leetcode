class Solution {
public:
    string fun(string s) {
        string ans = "";

        int count = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() && s[i] == s[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += s[i - 1];
                count = 1;
            }
        }

        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            ans = fun(ans);
        }

        return ans;
    }
};