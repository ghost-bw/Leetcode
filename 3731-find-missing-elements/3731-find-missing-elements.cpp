class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return {};

        sort(nums.begin(), nums.end());
        int min_val = nums[0];
        int max_val = nums[n - 1];

        vector<int> res;
        int i = 0;

        for (int curr = min_val; curr <= max_val; ++curr) {

            while (i < n && nums[i] < curr) {
                i++;
            }

            if (i < n && nums[i] == curr) {
                continue;
            } 

            else {
                res.push_back(curr);
            }
        }

        return res;
    }
};
