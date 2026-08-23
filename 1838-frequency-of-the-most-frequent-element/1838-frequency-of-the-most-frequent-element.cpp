class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left=0;
        int mfreq=0;
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while((static_cast<long long>(nums[right]) * (right - left + 1)) - sum > k){
                sum-=nums[left];
                left++;
            }
            mfreq=max(mfreq,right-left+1);
        }
        return mfreq;
    }
};