class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x= 0;
        for(int num:nums)x^=num;
        long long rightbit=x&-x;
        int a=0,b=0;
        for(int num:nums){
            if(num &rightbit)a^=num;
            else b^=num;
        }
        return {a,b};
    }
};