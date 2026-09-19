class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        int ele=INT_MIN;
        for(int i=n-2;i>=0;i--){
            ele=max(ele,nums[i+1]);
            ans[i]=ele;
        }
        return ans;
    }
};