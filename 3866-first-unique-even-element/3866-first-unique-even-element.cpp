class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> seen;
        for(int num: nums){
            if(num%2==0) seen[num]++;
        }
        for(int num: nums){
            if(num% 2==0 && seen[num]==1) return num;
        }
        return -1;

    }
};