class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long total = 0;
        long long left = 0;

        for (int x : nums)
            total += x;

        for (int i = 0; i < half; i++)
            left += nums[i];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (2 * left > total)
                ans++;

            left -= nums[i];
            left += nums[(i + half) % n];
        }

        return ans;
    }
};