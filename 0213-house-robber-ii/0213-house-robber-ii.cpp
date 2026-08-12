class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
    int solve(vector<int>& nums,int i,int j){
        int prev1=0,prev2=0;
        for(int x=i;x<=j;x++){
            int take=nums[x]+prev2;
            int skip=prev1;
            int curr=max(take,skip);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};