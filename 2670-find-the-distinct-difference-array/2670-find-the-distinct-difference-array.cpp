class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans;
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            pre[i] = s.size();
        }

        s.clear();

        for (int i = n - 1; i >= 0; i--) {
            s.insert(nums[i]);
            suf[i] = s.size();
        }

        for (int i = 0; i < n; i++) {
            int left = pre[i];
            int right = (i == n - 1) ? 0 : suf[i + 1];
            ans.push_back(left - right);
        }

        return ans;
    }
};