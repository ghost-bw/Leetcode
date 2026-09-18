class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first_seen;
        unordered_map<int, int> last_seen;
        
        int degree = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (first_seen.find(num) == first_seen.end()) {
                first_seen[num] = i; // Store first index
            }
            last_seen[num] = i;      // Update last seen index
            count[num]++;            // Increment frequency
            
            degree = max(degree, count[num]); // Track the max degree
        }
        
        int min_len = nums.size();
        
        // Find the minimum length among all elements that match the max degree
        for (auto& pair : count) {
            int num = pair.first;
            if (pair.second == degree) {
                int current_len = last_seen[num] - first_seen[num] + 1;
                min_len = min(min_len, current_len);
            }
        }
        
        return min_len;
    }
};
