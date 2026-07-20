class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]+nums[1];
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=n-1;i>=0;i-=3){
            sum+=nums[i];
            if(i-1>=0) sum+=nums[i-1];
        }
        return sum;
    }
};