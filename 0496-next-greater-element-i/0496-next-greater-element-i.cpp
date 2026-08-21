class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        for(int j=0;j<nums1.size();j++){
            bool found=false;
            
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==nums1[j])found=true;
                if(found && nums2[i]>nums1[j]){
                    ans[j]=nums2[i];
                    break;
                }
            }
        }
        return ans;
    }
};