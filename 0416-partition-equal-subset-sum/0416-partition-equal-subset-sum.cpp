class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        return dp[sum];
     }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int i = 0;i < n; i++){
            total_sum += nums[i];
        }
        if (total_sum%2) return false;
        int s = total_sum/2;
        // bitset<10001> dp;
        // dp[0] = 1;
        // for (int num:nums){
        //     dp |= (dp << num);
        // }        
        // return dp[s];
        return isSubsetSum(nums,s);
    }
};
