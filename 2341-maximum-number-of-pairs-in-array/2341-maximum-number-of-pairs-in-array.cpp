class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        
        int count=0;
        for(int i=0;i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        res.push_back(count);
        res.push_back(nums.size()-2*count);
        return res;
    }
};