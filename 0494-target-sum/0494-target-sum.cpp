class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ts=0;
        for(auto i: nums){
            ts+=i;
        }
        int sum=ts+target;
        if(sum%2!=0) return 0;
        if(abs(target)>ts) return 0;
        int n=nums.size();
        int i, j;
        vector<vector<int>> dp(n+1);
        int ns=sum/2;
        for(i=0;i<=n;i++){
            vector<int> t(ns+1,-1);
            dp[i]=t;
        }
        for(j=0;j<=ns;j++){
            dp[n][j]=0;
        }
        dp[n][0]=1;
        for(i=n-1;i>=0;i--){
            for(j=0;j<=ns;j++){
                if(nums[i]>j) dp[i][j]=dp[i+1][j];
                else dp[i][j]=dp[i+1][j-nums[i]]+dp[i+1][j];
            }
        }
        return dp[0][ns];
    }
};