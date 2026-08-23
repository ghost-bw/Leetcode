class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        vector<int> ans(n,-1);
        if(n<2*k+1)return ans;
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }
        ans[k]=sum/(2*k+1);
        for(int i=k+1;i<n-k;i++){
            sum-=nums[i-k-1];
            sum+=nums[i+k];
            ans[i]=sum/(2*k+1);
        }
        return ans;
    }
};