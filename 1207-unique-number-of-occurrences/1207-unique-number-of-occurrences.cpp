class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num: nums){
            freq[num]++;
        }
        unordered_set<int> seen;
        for(auto &it: freq){
            if(seen.count(it.second)){
                return false;
            }else{
                seen.insert(it.second);
            }
        }
        return true;
    }
};