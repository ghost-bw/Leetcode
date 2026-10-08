class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxe=*max_element(nums.begin(),nums.end());
        vector<int>freq(maxe+1);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]+=nums[i];
        }
        int prev1=0,prev2=0;
        for(int i=0;i<freq.size();i++){
            int take=prev2+freq[i];
            int skip=prev1;
            int curr=max(take,skip);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};