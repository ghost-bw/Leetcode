class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if(n <= 1) return 1;

    //     if(dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    // }

    int climbStairs(int n) {
       int a=1,b=1;
       for(int i=2;i<=n;i++){
        int sum=a+b;
        a=b;
        b=sum;
       }
       return b;
    }
};