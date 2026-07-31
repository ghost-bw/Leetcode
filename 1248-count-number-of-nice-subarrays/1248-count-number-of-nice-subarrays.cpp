class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int l=0;
        int count=0;
        int odds=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==1)odds++;
            while(odds>k){
                if(nums[l]%2==1)odds--;
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};