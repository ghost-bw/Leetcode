class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool hash=0;
        int xr=0;
        for(int x: nums){
            xr^=x;
            if(x!=0){
                hash=true;
            }
        }
        if(hash==false) return 0;
        return xr!=0?nums.size():nums.size()-1;
    }
};