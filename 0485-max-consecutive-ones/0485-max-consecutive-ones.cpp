class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[0]==1) return 1;
        int count=0;
        int maxcount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                maxcount=max(maxcount,count+1);
                count++;
            }else{     
                count=0;
            }
        }
        return maxcount;
    }
};