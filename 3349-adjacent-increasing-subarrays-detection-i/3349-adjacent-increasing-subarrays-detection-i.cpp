class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 0, cur = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                prev = cur;
                cur = 1;
            }

            if (cur >= 2 * k || min(prev, cur) >= k)
                return true;
        }

        return false;
    }
};