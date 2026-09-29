class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int low = 0;
        long long sum = 0, count = 0;
        for(int high = 0; high < nums.size(); high++) {
            sum += nums[high];
            while(low <= high && sum * (high - low + 1LL) >= k) {
                sum -= nums[low++];
            }
            count += high - low + 1LL;
        }

        return count;
    }
};