class Solution {
public:
    // int solve(int n,vector<int> &dp){
    //     if(n<=1){
    //         dp[n]=n;
    //         return dp[n];
    //     }
    //     if(dp[n]!=-1)return dp[n];
    //     dp[n]= solve(n-1,dp)+solve(n-2,dp);
    //     return dp[n];
    // }
    int fib(int n) {
        if (n <= 1)
        return n;
        int prev2=0;
        int prev1=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=prev2+prev1;
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
};