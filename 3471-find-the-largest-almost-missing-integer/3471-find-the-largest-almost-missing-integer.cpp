class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i: nums)freq[i]++;
        if(k==n) return *max_element(nums.begin(),nums.end());
        
        if (k == 1) {
            int maxno = INT_MIN;
            for (const auto& it : freq) {
                if (it.second == 1) {
                    maxno = max(maxno, it.first);
                }
            }
            return (maxno != INT_MIN) ? maxno : -1;
        }
        
        if(k>1 && k<n){
            if(freq[nums[0]]>1 && freq[nums[n-1]]==1){
                return nums[n-1];
            }else if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
                return max(nums[0],nums[n-1]);
            }else if(freq[nums[0]]==1 && freq[nums[n-1]]>1){
                return nums[0];
            }
        }
    return -1;
    }
};