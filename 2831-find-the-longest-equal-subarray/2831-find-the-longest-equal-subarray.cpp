class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>freq;
        int n=nums.size();
        for(int i=0; i<n;i++){
            freq[nums[i]].push_back(i);
        }
        int ans=0;
        for (auto &it : freq) {
            vector<int> &idx = it.second;

            int l = 0;
            for (int r = 0; r < idx.size(); r++) {

                while ((idx[r] - idx[l]) - (r - l) > k) {
                    l++;
                }

                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};