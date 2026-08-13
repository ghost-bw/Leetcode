class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minend=nums[0];
        int maxend=nums[0];
        int ans=minend;
        for(int i=1;i<nums.size();i++){
           
           int v1=maxend*nums[i];
           int v2=minend*nums[i];
           maxend=max(max(v1,v2),nums[i]);
           minend=min(min(v1,v2),nums[i]);
           ans=max(ans,max(minend,maxend));
        }
        return ans;
    }
};