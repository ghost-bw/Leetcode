class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> ss(nums.begin(),nums.end());
        int n=nums.size();
        if(valueDiff==0 && ss.size()==n) return false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<i+1+indexDiff;j++){
                if(j>=n)break;
                if(abs((long long)nums[i]-nums[j])<=valueDiff) return true;
            }
        }
        return false;
    }
};