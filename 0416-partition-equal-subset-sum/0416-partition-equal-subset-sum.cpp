class Solution {
public:
    bool fun(vector<int>& nums, int i, int n, int sum, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;

        if (i == n)
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool take = false;
        if (nums[i] <= sum)
            take = fun(nums, i + 1, n, sum - nums[i], dp);

        bool notTake = fun(nums, i + 1, n, sum, dp);

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return fun(nums, 0, n, target, dp);
    }
};