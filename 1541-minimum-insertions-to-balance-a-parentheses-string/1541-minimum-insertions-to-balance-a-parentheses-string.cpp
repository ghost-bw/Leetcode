class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, req = 0;
        for (char c : s) {
            if (c == '(') {
                if (req % 2 != 0) {
                    ans++;
                    req--;
                }
                req += 2;
            } else {
                req--;
                if (req < 0) {
                    ans++;
                    req += 2;
                }
            }
        }
        return ans + req;
    }
};
