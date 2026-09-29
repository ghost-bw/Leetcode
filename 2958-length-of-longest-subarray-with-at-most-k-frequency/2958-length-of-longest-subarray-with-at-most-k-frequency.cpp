class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int low=0;
        int n=nums.size();
        int maxlen=0;

        for(int high=0;high<n;high++){
            freq[nums[high]]++;
            while(freq[nums[high]]>k){
                freq[nums[low]]--;
                low++;
            }
            maxlen=max(maxlen,high-low+1);
        }
        return maxlen;
    }
};