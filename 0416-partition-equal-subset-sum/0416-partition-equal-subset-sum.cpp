class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int i = 0;i < n; i++){
            total_sum += nums[i];
        }
        if (total_sum%2) return false;
        int s = total_sum/2;
        bitset<10001> dp;
        dp[0] = 1;
        for (int num:nums){
            dp |= (dp << num);
            if (dp[s]) return true;
        }        
        return dp[s];
    }
};
