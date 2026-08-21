class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nums;
        vector<int> ans(nums1.size(),-1);
        for (int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                nums[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nums[nums2[st.top()]]=-1;
            st.pop();
        }
        for(int j=0; j<nums1.size(); j++){
            ans[j]=nums[nums1[j]];
        }
        return ans;
    }
};