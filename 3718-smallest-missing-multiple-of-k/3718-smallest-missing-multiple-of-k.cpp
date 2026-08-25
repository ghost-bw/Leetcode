class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exist(101);
        for(int i:nums){
            exist[i]=true;
        }
        int n=k;
        while(n<101){
            if(!exist[n])return n;
            n+=k; 
        }
        return n;
    }
};