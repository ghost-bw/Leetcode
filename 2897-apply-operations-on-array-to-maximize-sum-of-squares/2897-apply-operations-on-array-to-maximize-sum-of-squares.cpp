class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bit_counts(31, 0);
        
        // Step 1: Count the occurrences of each bit
        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long ans = 0;
        
        // Step 2: Form the k largest possible numbers
        for (int j = 0; j < k; j++) {
            long long current_num = 0;
            for (int i = 0; i < 31; i++) {
                if (bit_counts[i] > 0) {
                    current_num |= (1 << i);
                    bit_counts[i]--;
                }
            }
            // Step 3: Add the square of the number to the answer
            ans = (ans + (current_num * current_num)) % MOD;
        }
        
        return ans;
    }
};
