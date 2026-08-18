class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int> &dp){
        
        if(n<=1){
            dp[n]=0;
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        dp[n]=min(cost[n-1]+solve(cost,n-1,dp),cost[n-2]+solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        if(n<=1){
            return 0;
        }
        int prev2=0;
        int prev1=0;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=min(cost[i-1]+prev1,cost[i-2]+prev2);
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
};