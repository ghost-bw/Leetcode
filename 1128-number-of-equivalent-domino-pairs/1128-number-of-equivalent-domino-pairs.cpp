class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt[10][10] = {};
        int ans = 0;

        for (auto &d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);

            ans += cnt[a][b];
            cnt[a][b]++;
        }

        return ans;
    }
};