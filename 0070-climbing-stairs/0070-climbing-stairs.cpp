class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if(n <= 1) return 1;

    //     if(dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    // }

    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
       int prev2=1,prev1=2;
       int sum=0;
       for(int i=3;i<=n;i++){
            sum=prev1+prev2;
            prev2=prev1;
            prev1=sum;
       }
       return sum;
    }
};