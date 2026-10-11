class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        int maxlen=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                len++;
            }else{
                len=0;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen+1;
    }
};