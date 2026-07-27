
class Solution {
public:
    vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> ans(n, 0);
        std::unordered_map<int, std::vector<int>> numToIndices;
        
        // 1. Group all indices by their value
        for (int i = 0; i < n; i++) {
            numToIndices[nums[i]].push_back(i);
        }
        
        // 2. Process each distinct number group using a rolling prefix calculation
        for (auto& [val, idx] : numToIndices) {
            int m = idx.size();
            if (m == 1) continue; // Single elements have a distance sum of 0
            
            // Calculate total right-side contribution for the very first element
            long long leftSum = 0;
            long long rightSum = 0;
            for (int i : idx) {
                rightSum += (i - idx[0]);
            }
            ans[idx[0]] = rightSum;
            
            // Roll through the rest of the indices using math shifts
            for (int i = 1; i < m; i++) {
                long long delta = idx[i] - idx[i - 1];
                
                // i elements on the left become 'delta' units further away
                leftSum += delta * i;
                
                // (m - i) elements on the right become 'delta' units closer
                rightSum -= delta * (m - i);
                
                ans[idx[i]] = leftSum + rightSum;
            }
        }
        
        return ans;
    }
};
