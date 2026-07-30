class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int ans=0;
        int n=nums.size();
        int zeroes=0;
        for(int r=0;r<n;r++){
            
            if(nums[r]==0) zeroes++;
            while(zeroes>1){
                if(nums[l]==0)zeroes--;
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};