class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int count=0;
        for(int high=2;high<n;high++){
            if(2*(nums[low]+nums[high])==nums[low+1]){
                count++;
            }
            low++;
        }
        return count;
    }
};