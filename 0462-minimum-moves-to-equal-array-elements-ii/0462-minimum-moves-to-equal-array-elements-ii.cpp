class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size() / 2];
        for(int n:nums){
            sum+=abs(n-mid);
        }
        return sum;
    }
};