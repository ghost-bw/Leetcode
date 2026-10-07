class Solution {
public:
    vector<string> ans;

    void solve(string s, int st, int last, char a, char b) {
        int bal = 0;

        for (int i = st; i < s.size(); i++) {
            if (s[i] == a) bal++;
            else if (s[i] == b) bal--;

            if (bal >= 0) continue;

            for (int j = last; j <= i; j++) {
                if (s[j] == b && (j == last || s[j] != s[j - 1])) {
                    solve(s.substr(0, j) + s.substr(j + 1), i, j, a, b);
                }
            }
            return;
        }

        reverse(s.begin(), s.end());

        if (a == '(') {
            solve(s, 0, 0, ')', '(');
        } else {
            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        solve(s, 0, 0, '(', ')');
        return ans;
    }
};