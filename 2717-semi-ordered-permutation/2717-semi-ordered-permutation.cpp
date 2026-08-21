class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        int x,y;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                x=i;
            }
            if(nums[i]==n){
                y=i;
            }
        }
        return (x<y)?(x+n-y-1):(x+n-y-2);
    }
};