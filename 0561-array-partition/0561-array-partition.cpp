class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums[0];
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=n-1;i>=0;){
            sum+=nums[i-1];
            i-=2;
        }
        return sum;
    }
};