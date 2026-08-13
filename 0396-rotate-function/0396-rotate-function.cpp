class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long array_sum = 0;
        long long f_current = 0;
        
        
        for (int i = 0; i < n; i++) {
            array_sum += nums[i];
            f_current += i * nums[i];
        }
        
        long long max_val = f_current;
        
        
        for (int k = 1; k < n; k++) {
            // F(k) = F(k-1) + sum - n * nums[n - k]
            f_current = f_current + array_sum - n * nums[n - k];
            max_val = max(max_val, f_current);
        }
        
        return max_val;
    }
};
