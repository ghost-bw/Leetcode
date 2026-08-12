class Solution {
public:
    // int fun(vector<int>& nums,int n,int i,int free,vector<vector<int>> &dp){
    //     if(i==n) return 0;
    //     if(dp[i][free]!=-1) return dp[i][free];
    //     if (free==0) return dp[i][free]=fun(nums,n,i+1,1,dp);
    //     else{
    //         int c1=nums[i]+fun(nums,n,i+1,0,dp);
    //         int c2=fun(nums,n,i+1,1,dp);
    //         return dp[i][free]=max(c1,c2);
    //     }
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0;
        int prev2=0;
        for(int i:nums){
            int take=i+prev2;
            int skip=prev1;
            int curr=max(take,skip);
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};