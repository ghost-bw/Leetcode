class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
       int sum=nums[0];
       int count=0;
        for(int i=1;i<nums.size();i++){
            if(sum>=0 && (sum+nums[i])==0){
                count++;
            }else if(sum<=0 && (sum+nums[i])==0){
                count++;
            }
            sum+=nums[i];
        }
        return count;
    }
};