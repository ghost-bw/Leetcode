class Solution {
private:
   
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count; 
        int l = 0;
        int total_subarrays = 0;

        for (int r = 0; r < n; r++) {
            count[nums[r]]++;

            
            while (count.size() > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                l++;
            }

            total_subarrays += (r - l + 1);
        }
        return total_subarrays;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
