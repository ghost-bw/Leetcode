class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int> dq;
        if(nums.size()==0||k<=0) return nums;
        for(int i=0;i<nums.size();i++){
             while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove indices whose values are smaller than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Store maximum for current window
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};