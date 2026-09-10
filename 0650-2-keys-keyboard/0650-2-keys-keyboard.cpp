class Solution {
public:
    int dp[1001][1001];

    int solve(int curr, int copied, int n,bool canCopy) {
        if (curr == n)
            return 0;

        if (curr > n)
            return 1e9;

        if (dp[curr][copied] != -1)
            return dp[curr][copied];

        int copy = 1e9;
        if (canCopy && curr != copied) { 
            copy = 1 + solve(curr, curr, n, false); // canCopy is set to false for the next call
        }

        int paste = 1e9;

        if (copied > 0)
            paste = 1 + solve(curr + copied, copied, n,true);

        return dp[curr][copied] = min(copy, paste);
    }

    int minSteps(int n) {
        if (n == 1)
            return 0;

        memset(dp, -1, sizeof(dp));

        return solve(1, 0, n, true);
    }
};