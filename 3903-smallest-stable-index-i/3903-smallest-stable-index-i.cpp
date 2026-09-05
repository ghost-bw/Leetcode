class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int> maxi(n,0);

        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            maxi[i]=mx;
        }
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            maxi[i]-=mn;
        }
        for(int i=0;i<n;i++){
            if(maxi[i]<=k)return i;
        }
        return -1;
    }
};