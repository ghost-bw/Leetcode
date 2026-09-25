class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool decr=true;
        bool incr=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])decr=false;
            if(nums[i]>nums[i+1])incr=false;
        }
        return incr||decr;
    }
};