class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        std:: set<int> seen;
        for(int i=0;i<nums.size();i++){
            auto it=seen.lower_bound(nums[i]-valueDiff);
            if(it != seen.end() && *it <= nums[i] + valueDiff) return true;
            seen.insert(nums[i]);
            if(seen.size()>indexDiff){
                seen.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};