class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0;
        int n= nums.size();
        int sum=0;
        int len;
        int ans=INT_MAX;
        for(high=0;high<n;high++){
            sum+=nums[high];
           while(sum>=target){
                int len=high-low+1;
                ans=min(len,ans);
                sum-=nums[low];
                low++;
           }
          
        }
       return (ans == INT_MAX) ? 0 : ans; 
    }
};