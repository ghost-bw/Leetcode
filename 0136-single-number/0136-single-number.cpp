class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorall= 0;
        for(int num: nums){
            xorall^=num;
        }
        return xorall;
    }
};