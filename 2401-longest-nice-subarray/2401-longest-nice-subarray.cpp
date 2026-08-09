class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();

        int l=0,used=0,ans=0;
        for(int r=0;r<n;r++){
            while((used & nums[r])!=0){
                used^=nums[l++];
            }
            used|=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};